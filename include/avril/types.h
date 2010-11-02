
/* Some basic types used all over the place. */

#ifndef _AVRIL_TYPES_H_
#define _AVRIL_TYPES_H_

#include <stdint.h>

/* a convenient bool_t */
typedef uint8_t bool_t;
#define TRUE ((bool_t)1)
#define FALSE ((bool_t)0)

/* type for "timer ticks" and the like */
typedef uint32_t tick_t;

/* type for frequencies in Hz */
typedef uint32_t freq_t;

#endif /* !_AVRIL_TYPES_H_ */

