
/* A way for getting at the cpu frequency. */

#ifndef _AVR_FCPU_H_
#define _AVR_FCPU_H_

#include <avril/types.h>

/*
 * Currently, the user must always specify a fixed frequency.
 */
#ifndef FCPU
#error "No cpu frequency specified. Set FCPU."
#endif

/*
 * Get the current cpu frequency.
 */
#define fcpu()     ((freq_t)FCPU)

#endif /* !_AVR_FCPU_H_ */
