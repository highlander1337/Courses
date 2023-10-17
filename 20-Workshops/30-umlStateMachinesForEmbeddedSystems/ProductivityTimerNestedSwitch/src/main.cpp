#include "main.h"

// Main application object
static protimer_t protimer;

// put function declarations here:
static void protimer_event_dispatcher(protimer_t *const mobj,
                                      event_t const *const e);

void setup() {
  // put your setup code here, to run once:
  protimer_init(&protimer);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
static void protimer_event_dispatcher(protimer_t *const mobj,
                                      event_t const *const e) {
  // Actual status
  event_status_t status;

  // Actual state
  protimer_state_t source;

  source = mobj->active_state;

  status = protimer_state_machine(mobj, e);

  if (status == EVENT_TRANSITION) {
    // exit or entry event
    event_t ee;
    // 1. Execute the exit action for the source state
    ee.sig = EXIT;
    mobj->active_state = source;
    protimer_state_machine(mobj, &ee);
    // 2. Execute the entry action for the target state
    ee.sig = ENTRY;
    protimer_state_machine(mobj, &ee);
  }
}
