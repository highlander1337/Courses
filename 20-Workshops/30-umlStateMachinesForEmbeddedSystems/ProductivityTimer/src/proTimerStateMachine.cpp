#include "main.h"

// Prototypes of helper functions

static void display_time(uint32_t time);
static void display_message(String s);
static void display_clear(void);
static void do_beep(void);

// prototypes of state handlers

static event_status_t protimer_state_machine(protimer_t *const mobj,
                                             event_t const *const e);
static event_status_t protimer_state_handler_IDLE(protimer_t *const mobj,
                                                  event_t const *const e);
static event_status_t protimer_state_handler_TIME_SET(protimer_t *const mobj,
                                                      event_t const *const e);

// Prototypes of protimer machine
void protimer_init(protimer_t *mobj);

void protimer_init(protimer_t *mobj) {

  mobj->active_state = IDLE;
  mobj->pro_time = 0;
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
  }
}

static event_status_t protimer_state_handler_IDLE(protimer_t *const mobj,
                                                  event_t const *const e) {
  switch (e->sig) {
  case ENTRY: {
    mobj->curr_time = 0;
    mobj->elapsed_time = 0;
    display_time(0);
    display_message("Set time");
    return EVENT_HANDLED;
  }
  case EXIT: {
    display_clear();
    return EVENT_HANDLED;
  }
  case INC_TIME: {
    mobj->curr_time += 60;
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
  return EVENT_IGNORED;
}
// Helper functions

// to display time
static void display_time(uint32_t time) {}

// to display lcd messages
static void display_message(String s) {}

// to clear lcd messages
static void display_clear(void) {}

// to alert the user
static void do_beep(void) {}