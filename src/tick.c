
#include <avr/interrupt.h>

#include <avril/types.h>
#include <avril/tick.h>

volatile tick_t numticks;

void
tick(void)
{
  numticks++;
}

tick_t
gettick(void)
{
  tick_t res;
  cli();
  res = numticks;
  sei();
  return res;
}

void
waitticks(tick_t ticks)
{
  /* get the current time */
  tick_t first = gettick();
  /* spin until the timeout is reached */
  while ((gettick()-first) < ticks);
  return;
}

