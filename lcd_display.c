#include "lcd1602.h"
#include "wiringPi.h"
#include "stdio.h"



int main()
{
   wiringPiSetupGpio();
   pinMode(Rs,OUTPUT);
   pinMode(En,OUTPUT);
   pinMode(Rw,OUTPUT);
   pinMode(BD4,OUTPUT);
   pinMode(BD5,OUTPUT);
   pinMode(BD6,OUTPUT);
   pinMode(BD7,OUTPUT);
   
   while (1)
   {
     
   }
   return 0;
}
