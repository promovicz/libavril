
/* Utilities for simple access to the first USART. */

#ifndef _AVRIL_URXTX_H_
#define _AVRIL_URXTX_H_

#include <avril/types.h>

/*
 * Initialize the USART with the given baud rate.
 *
 * The word configuration is always 8 bit, no parity, 1 stop bit.
 *
 * Anything else is beyond the scope of this interface.
 */
extern void   uinit(uint32_t baudrate);

/*
 * Transmit one byte with the first usart. Non-blocking.
 */
extern void   utx(char data);

/*
 * Receive one byte with the first usart. Non-blocking.
 *
 * Returns TRUE if we received a byte, FALSE otherwise.
 */
extern bool_t urx(char *data);

#endif /* !_AVRIL_URXTX_H_ */
