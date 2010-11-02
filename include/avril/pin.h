
/* Utilities for accessing pins. */

#ifndef _AVRIL_PIN_H_
#define _AVRIL_PIN_H_

/*
 * Helper macro for output-pins.
 *
 * Defines 4 static inline functions:
 *   - $(name)0 function for setting low
 *   - $(name)1 function for setting high
 *   - $(name)_set function taking a boolean
 *   - $(name)_init function setting up the pin
 */
#define PIN_FOR_OUTPUT(name, port, pin)        \
  static inline void name##0  (void)           \
    { PORT##port &= ~_BV(pin); }               \
  static inline void name##1  (void)           \
    { PORT##port |=  _BV(pin); }               \
  static inline void name##_set (bool_t value) \
    { if(value) name##1(); else name##0(); }   \
  static inline void name##_init (void)        \
    { DDR##port |= _BV(pin); }                 

/*
 * Helper macro for input pins.
 *
 * Defines 2 static inline functions:
 *   - $(name)_get function for reading
 *   - $(name)_init function setting up the pin
 */
#define PIN_FOR_INPUT(name, port, pin)          \
  static inline bool_t name##_get (void)        \
    { return (PIN##port&_BV(pin))?FALSE:TRUE; } \
  static inline void name##_init (void)         \
    { DDR##port &= ~_BV(pin); }                 

#endif /* !_AVRIL_PIN_H_ */
