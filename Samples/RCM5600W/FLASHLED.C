/*
   Copyright (c) 2015, Digi International Inc.

   Permission to use, copy, modify, and/or distribute this software for any
   purpose with or without fee is hereby granted, provided that the above
   copyright notice and this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
/*******************************************************************
	Flashled.c

   This program is used with RCM56xxW or RCM66xxW series controllers and
   interface board.

   Description
   ===========
   This program uses Dynamic C's costatement feature to flash
   the LED on the interface board.

	I/O control       On Base-board
	--------------    ----------------------
	Port D bit 0		DS1 (LED)

   Jumper settings (Interface Board)
   ----------------------------
   JP1   1-2 program mode
         5-6 enables DS1 (LED)
         7-8 enables S1  (button), optional

         2    4    6   8
         o    o    o   o
         |         |
         o    o    o   o
         1    3    5   7

   Instructions
   ============
   1.  Make sure jumpers are connected as shown above.
   2.  Compile and run this program.
   3.  DS1 (LED) flashes on/off.

*******************************************************************/

#if RCM6600W_SERIES
	#use "rcm66xxw.lib"
#else
	#use "rcm56xxw.lib"
#endif

#define LEDON  0
#define LEDOFF 1

#define DS1 0

main()
{
	brdInit();

	while (1)
	{
		costate
		{
	      BitWrPortI(PDDR, &PDDRShadow, LEDON, DS1);
			waitfor(DelayMs(50));       // On for 50 ms.
	      BitWrPortI(PDDR, &PDDRShadow, LEDOFF, DS1);
			waitfor(DelayMs(100));      // Off for 100 ms.
		}
	}
}