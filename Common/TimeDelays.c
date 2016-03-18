#include "TimeDelays.h"
#include <xc.h>
#include <stdio.h>
#include "configureUSART.h"

void WaitOneSecond(void)
{
int  i = 0;
for(i=0; i<=80; i++) 
   {
    _delay(100000ul);  // 100 000 * 4 / 32 000 000 = 1/80 s 
   }
}

void WaitQuarterSecond(void)
{
int  i = 0;
for(i=0; i<=20; i++) 
   {
    _delay(100000ul);  // 100 000 * 4 / 32 000 000 = 1/80 s 
   }
}

void WaitFifthSecond(void)
{
    int i = 0;
    for (i = 0; i <= 16; i++)
    {
        _delay(100000ul);
    }
}
