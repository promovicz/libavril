
/* An extremely primitive "system timer". */

/* 
 * WARNING: This timer overflows after 497 days at 100 Hz.
 *          Waiting across the epoch will "deadlock" for 497 days.
 *          Consider this carefully before using.
 */

#ifndef _AVRIL_TICK_H_
#define _AVRIL_TICK_H_

/*
 * Increment the tick counter.
 *
 * This should be called from the system timer
 * interrupt context with interrupts disabled.
 *
 * Failure to do so may result in FUBAR.
 */
extern void tick(void);

/*
 * Get the current time in ticks.
 */
extern tick_t gettick(void);

/*
 * Wait for a specified amount of ticks.
 */
extern void waitticks(tick_t ticks);

#endif /* !_AVRIL_TICK_H_ */

