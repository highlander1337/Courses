#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>

// hardware inputs

#define PIN_BUTTON1 2 // INC_TIME
#define PIN_BUTTON2 3 // DEC_TIME
#define PIN_BUTTON3 4 // START/PAUSE

// hardware outputs
#define PIN_BUZZER 12 // BUZZER SOUND ALARM

// LCD hardware
#define PIN_LCD_RS 5
#define PIN_LCD_RW 6
#define PIN_LCD_EN 7
#define PIN_LCD_D4 8
#define PIN_LCD_D5 9
#define PIN_LCD_D6 10
#define PIN_LCD_D7 11

// LCD datasheet info
#define LCD_NUM_COL 16
#define LCD_NUM_ROW 2

// true table values for buttons event
/*
  b1    b2    b3    value   signal
  0     0     1     1       START_PAUSE
  0     1     0     2       DEC_TIME
  1     0     0     4       INC_TIME
  1     1     0     6       ABRT
  ?     ?     ?     ?       X
*/

#define BUTTON_PAD_VALUE_START_PAUSE 1
#define BUTTON_PAD_VALUE_DEC_TIME 2
#define BUTTON_PAD_VALUE_INC_TIME 4
#define BUTTON_PAD_VALUE_ABRT 6

typedef enum
{
  NOT_PRESSED,
  BOUNCE,
  PRESSED
} button_state_t;

// Signals of the application
typedef enum
{
  INC_TIME,
  DEC_TIME,
  TIME_TICK,
  START_PAUSE,
  ABRT,
  // Internal activity signals
  ENTRY,
  EXIT
  // END typedef enum
} protimer_signal_t;

// Various States of the application
typedef enum
{
  IDLE,
  TIME_SET,
  COUNTDOWN,
  PAUSE,
  STAT
  // END typedef enum
} protimer_state_t;

// Main application structure
typedef struct
{
  // current time
  uint32_t c_time;
  // elapsed time
  uint32_t e_time;
  // productive time
  uint32_t p_time;
  protimer_state_t active_state;
  // END typedef struct
} protimer_t;

// Generic(Super) event structure
typedef struct
{
  uint8_t sig;
} event_t;

// For user generated events
typedef struct
{
  event_t super;
} protimer_user_event_t;

// For tick event
typedef struct
{
  event_t super;
  uint8_t ss;
} protimer_tick_event_t;

typedef enum
{
  EVENT_HANDLED,
  EVENT_IGNORED,
  EVENT_TRANSITION,
} event_status_t;

void protimer_init(protimer_t *mobj);
static event_status_t protimer_state_machine(protimer_t *const mobj,
                                             event_t const *const e);

#endif