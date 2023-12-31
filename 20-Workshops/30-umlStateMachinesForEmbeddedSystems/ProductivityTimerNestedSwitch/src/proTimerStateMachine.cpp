#include "lcd.h"
#include "main.h"

// Prototypes of helper functions

static void disp_time(uint32_t time);
static void disp_msg(String s, uint8_t c, uint8_t r);
static void disp_clear(void);
static void do_beep(void);

// prototypes of state handlers

static event_status_t protimer_state_machine(protimer_t *const mobj,
                                             event_t const *const e);
static event_status_t protimer_state_handler_IDLE(protimer_t *const mobj,
                                                  event_t const *const e);
static event_status_t protimer_state_handler_TIME_SET(protimer_t *const mobj,
                                                      event_t const *const e);
static event_status_t protimer_state_handler_COUNTDOWN(protimer_t *const mobj,
                                                       event_t const *const e);
static event_status_t protimer_state_handler_PAUSE(protimer_t *const mobj,
                                                   event_t const *const e);
static event_status_t protimer_state_handler_STAT(protimer_t *const mobj,
                                                  event_t const *const e);

// Prototypes of protimer machine
void protimer_init(protimer_t *mobj);

void protimer_init(protimer_t *mobj) {
  event_t ee;
  ee.sig = ENTRY;
  mobj->active_state = IDLE;
  mobj->p_time = 0;
  protimer_state_machine(mobj, &ee);
}

static event_status_t protimer_state_machine(protimer_t *const mobj,
                                             event_t const *const e) {
  switch (mobj->active_state) {
  case IDLE: {
    return protimer_state_handler_IDLE(mobj, e);
  }
  case TIME_SET: {
    return protimer_state_handler_TIME_SET(mobj, e);
  }
  case COUNTDOWN: {
    return protimer_state_handler_COUNTDOWN(mobj, e);
  }
  case PAUSE: {
    return protimer_state_handler_PAUSE(mobj, e);
  }
  case STAT: {
    return protimer_state_handler_STAT(mobj, e);
  }
  }
}

static event_status_t protimer_state_handler_IDLE(protimer_t *const mobj,
                                                  event_t const *const e) {
  switch (e->sig) {
  case ENTRY: {
    mobj->c_time = 0;
    mobj->e_time = 0;
    disp_time(0);
    disp_msg("Set", 0, 0);
    disp_msg("time", 0, 1);
    return EVENT_HANDLED;
  }
  case EXIT: {
    disp_clear();
    return EVENT_HANDLED;
  }
  case INC_TIME: {
    mobj->c_time += 60;
    mobj->active_state = TIME_SET;
    return EVENT_TRANSITION;
  }
  case START_PAUSE: {
    mobj->active_state = STAT;
    return EVENT_TRANSITION;
  }
  case TIME_TICK: {
    if (((protimer_tick_event_t *)(e))->ss == 5) {
      do_beep();
      return EVENT_HANDLED;
    }
    return EVENT_IGNORED;
  }
  } // END OF SWITCH
  return EVENT_IGNORED;
}

static event_status_t protimer_state_handler_TIME_SET(protimer_t *const mobj,
                                                      event_t const *const e) {
  switch (e->sig) {
  case ENTRY: {
    disp_time(mobj->c_time);
    return EVENT_HANDLED;
  }

  case EXIT: {
    disp_clear();
    return EVENT_HANDLED;
  }

  case ABRT: {
    mobj->active_state = IDLE;
    return EVENT_TRANSITION;
  }

  case INC_TIME: {
    mobj->c_time += 60;
    disp_time(mobj->c_time);
    return EVENT_HANDLED;
  }

  case DEC_TIME: {
    if (mobj->c_time >= 60) {
      mobj->c_time -= 60;
      disp_time(mobj->c_time);
      return EVENT_HANDLED;
    }
    return EVENT_IGNORED;
  }
  case START_PAUSE: {
    if (mobj->c_time >= 60) {
      mobj->active_state = COUNTDOWN;
      return EVENT_TRANSITION;
    }
    return EVENT_IGNORED;
  }
  } // END OF SWITCH
  return EVENT_IGNORED;
}

static event_status_t protimer_state_handler_COUNTDOWN(protimer_t *const mobj,
                                                       event_t const *const e) {
  switch (e->sig) {
  case EXIT: {
    mobj->p_time += mobj->e_time;
    mobj->e_time = 0;
    return EVENT_HANDLED;
  }

  case TIME_TICK: {
    if (((protimer_tick_event_t *)(e))->ss == 10) {
      --mobj->c_time;
      ++mobj->e_time;
      disp_time(mobj->c_time);
      if (mobj->c_time == 0) {
        mobj->active_state = IDLE;
        return EVENT_TRANSITION;
      }
      return EVENT_HANDLED;
    }
    return EVENT_IGNORED;
  }

  case ABRT: {
    mobj->active_state = IDLE;
    return EVENT_TRANSITION;
  }

  case START_PAUSE: {
    mobj->active_state = PAUSE;
    return EVENT_TRANSITION;
  }

  } // END OF SWITCH
  return EVENT_IGNORED;
}

static event_status_t protimer_state_handler_PAUSE(protimer_t *const mobj,
                                                   event_t const *const e) {
  switch (e->sig) {
  case ENTRY: {
    disp_msg("Paused", 5, 1);
    return EVENT_HANDLED;
  }
  case EXIT: {
    disp_clear();
    return EVENT_HANDLED;
  }
  case START_PAUSE: {
    mobj->active_state = COUNTDOWN;
    return EVENT_TRANSITION;
  }
  case INC_TIME: {
    mobj->c_time += 60;
    mobj->active_state = TIME_SET;
    return EVENT_TRANSITION;
  }
  case DEC_TIME: {
    if (mobj->c_time >= 60) {
      mobj->c_time -= 60;
      mobj->active_state = TIME_SET;
      return EVENT_TRANSITION;
    }
    return EVENT_IGNORED;
  }
  case ABRT: {
    mobj->active_state = IDLE;
    return EVENT_TRANSITION;
  }

  } // END OF SWITCH
  return EVENT_IGNORED;
}

static event_status_t protimer_state_handler_STAT(protimer_t *const mobj,
                                                  event_t const *const e) {
  static uint8_t time_tick; // to handle stat only apearing for 3seconds
  // ((protimer_tick_event_t *)(e))->ss == 10 could be anything
  switch (e->sig) {
  case ENTRY: {
    disp_time(mobj->p_time);
    disp_msg("Productive", 1, 1);
    disp_msg("time", 11, 1);
    return EVENT_HANDLED;
  }
  case EXIT: {
    disp_clear();
    return EVENT_HANDLED;
  }
  case TIME_TICK: {
    if (++time_tick == 30) {
      time_tick = 0;
      mobj->active_state = IDLE;
      return EVENT_TRANSITION;
    }
    return EVENT_IGNORED;
  }
  } // END OF SWITCH
  return EVENT_IGNORED;
}

// Helper functions

// to display time
static void disp_time(uint32_t time) {
  char buf[7];
  String time_msg;

  uint16_t min = time / 60;
  uint8_t sec = time % 60;

  sprintf(buf, "%03d:%02d", min, sec);

  time_msg = (String)buf;

  lcd_set_cursor(5, 0);
  lcd_print(time_msg);
}

// to display lcd messages
static void disp_msg(String s, uint8_t c, uint8_t r) {
  lcd_set_cursor(c, r);
  lcd_print(s);
}

// to clear lcd messages
static void disp_clear(void) { lcd_clear(); }

// to alert the user
static void do_beep(void) { tone(PIN_BUZZER, 4000, 25); }