#include "main.h"
// #include "btnDeBouncingStateMachine.h"

// Main application object
static protimer_t protimer;

// Button debouncing object
// static stm_button_debouncing_t btnDeBouncing;

// function declarations here:
static void protimer_event_dispatcher(protimer_t *const mobj,
                                      event_t const *const e);
static uint8_t process_button_pad_value(uint8_t btn_pad_value);

void setup() {
  // serial initialization
  Serial.begin(115200);

  // display initialization
  // display.init();
  Serial.println("Productive timer application");
  Serial.println("============================");

  // define pinMode configuration
  pinMode(PIN_BUTTON1, INPUT);
  pinMode(PIN_BUTTON2, INPUT);
  pinMode(PIN_BUTTON3, INPUT);

  // initialize main application object
  protimer_init(&protimer);
  // initialize button debouncing object
  // stmButtonDeBouncing_init(&btnDeBouncing);
}

void loop() {

  // hardware variables
  uint8_t b1, b2, b3, btn_pad_value;

  // user event variables
  protimer_user_event_t ue;

  // tick event variables
  static uint32_t current_time = millis();
  static protimer_tick_event_t te;
  // te should be initialized equal to zero,
  // but static variables are initialized equals zero by default

  // 1. read the button pad status
  b1 = digitalRead(PIN_BUTTON1);
  b2 = digitalRead(PIN_BUTTON2);
  b3 = digitalRead(PIN_BUTTON3);

  // buttons combination pressed
  btn_pad_value = (b1 << 2) | (b2 << 1) | b3; // bitwise operators

  // software button de-bouncing (due to mechanical button internal switch)
  btn_pad_value = process_button_pad_value(btn_pad_value);

  // 2. make an event
  if (btn_pad_value) {
    switch (btn_pad_value) {
    case BUTTON_PAD_VALUE_INC_TIME:
      ue.super.sig = INC_TIME;
      break;
    case BUTTON_PAD_VALUE_DEC_TIME:
      ue.super.sig = DEC_TIME;
      break;
    case BUTTON_PAD_VALUE_START_PAUSE:
      ue.super.sig = START_PAUSE;
      break;
    case BUTTON_PAD_VALUE_ABRT:
      ue.super.sig = ABRT;
      break;
    default:
      // do nothing
      break;
    }
    // 3. send it to event dispatcher
    protimer_event_dispatcher(&protimer, &ue.super);
  }

  // 4. dispatch the time tick event for every 100ms
  if ((millis() - current_time) > 100) {
    // 100ms has passed
    current_time = millis();
    te.super.sig = TIME_TICK;
    if (++te.ss > 10)
      te.ss = 1;
    protimer_event_dispatcher(&protimer, &te.super);
  }
}

// function definitions here:
static void protimer_event_dispatcher(protimer_t *const mobj,
                                      event_t const *const e) {
  // Actual status
  event_status_t status;

  // Actual state
  protimer_state_t source, target;

  source = mobj->active_state;
  status = protimer_state_machine(mobj, e);

  if (status == EVENT_TRANSITION) {
    // Target state
    target = mobj->active_state;
    // exit or entry event
    event_t ee;
    // 1. Execute the exit action for the source state
    ee.sig = EXIT;
    mobj->active_state = source;
    protimer_state_machine(mobj, &ee);
    // 2. Execute the entry action for the target state
    ee.sig = ENTRY;
    mobj->active_state = target;
    protimer_state_machine(mobj, &ee);
  }
}

static uint8_t process_button_pad_value(uint8_t btn_pad_value) {
  static button_state_t btn_sm_state = NOT_PRESSED;
  static uint32_t curr_time = millis();

  switch (btn_sm_state) {
  case NOT_PRESSED: {
    if (btn_pad_value) {
      btn_sm_state = BOUNCE;
      curr_time = millis();
    }
    break;
  }
  case BOUNCE: {
    if (millis() - curr_time >= 50) {
      // 50ms has passed
      if (btn_sm_state) {
        btn_sm_state = PRESSED;
        return btn_pad_value;
      } else
        btn_sm_state = NOT_PRESSED;
    }
    break;
  }
  case PRESSED: {
    if (!btn_pad_value) {
      btn_sm_state = BOUNCE;
      curr_time = millis();
    }
    break;
  }
    return 0;
  }
}