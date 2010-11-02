
#include <avr/io.h>

#include <avril/fcpu.h>
#include <avril/urxtx.h>

void
uinit(uint32_t baudrate)
{
  /* calculate baud rate register value */
  uint16_t ubrr = ((fcpu()+(baudrate*8L))/(baudrate*16L)-1);

  /* set the baud rate */
  UBRRL = (ubrr   )&0xFF;
  UBRRH = (ubrr>>8)&0xFF;

  /* configure 8bit, no parity, 1 stop bit, TX and RX */
  UCSRB = _BV(TXEN)|_BV(RXEN);
  UCSRC = _BV(URSEL)|_BV(UCSZ1)|_BV(UCSZ0);
}

void
utx(char data)
{
  /* wait for empty transmit buffer */
  while (!(UCSRA & (1<<UDRE)));
  /* put the data word into the output buffer */
  UDR = data;
}

bool_t
urx(char *buffer)
{
  /* check if we have a byte */
  if(UCSRA&_BV(RXC)) {
    *buffer = UDR;
    return TRUE;
  } else {
    return FALSE;
  }
}

