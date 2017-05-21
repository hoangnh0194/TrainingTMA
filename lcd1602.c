#include "lcd1602.h"
//

unsigned char LCD_Wait(void) 
{ 
	Rs=0; 
	Rw=1;	delay_ms(10); 
	En=1;	delay_ms(10); 
	En=0; 
	//return DBPort;		 
} 
//     
void LCD_Write(bit style, unsigned char input) 
{ 
	En=0; 
	Rs=style; 
	Rw=0;		delay_ms(10); 
	DB4=input&;	        
	En=1;		delay_ms(10); 
	En=0;		delay_ms(10); 
	LCD_Wait();	 
} 
 
//    
 
void LCD_SetDisplay(unsigned char DisplayMode) 
{ 
	LCD_Write(LCD_COMMAND, 0x08|DisplayMode);	 
} 
//  

void LCD_SetInput(unsigned char InputMode) 
{ 
	LCD_Write(LCD_COMMAND, 0x04|InputMode); 
} 
 
// 
 

void LCD_Move(unsigned char object, unsigned char direction) 
{ 
	if(object==LCD_CURSOR) 
		LCD_Write(LCD_COMMAND,0x10|direction); 
	if(object==LCD_SCREEN) 
		LCD_Write(LCD_COMMAND,0x18|direction); 
} 
 
//
void LCD_Initial() 
{ 
	LcdEn=0; 
	LCD_Write(LCD_COMMAND,0x38);          
	LCD_Write(LCD_COMMAND,0x38); 
	LCD_SetDisplay(LCD_SHOW|LCD_NO_CURSOR);  
	LCD_Write(LCD_COMMAND,LCD_CLEAR_SCREEN);   
	LCD_SetInput(LCD_AC_UP|LCD_NO_MOVE);       
} 
 
// 
void GotoXY(unsigned char x, unsigned char y) 
{ 
	if(y==0) 
		LCD_Write(LCD_COMMAND,0x80|x); 
	if(y==1) 
		LCD_Write(LCD_COMMAND,0x80|(x-0x40)); 
} 
void Print(unsigned char *str) 
{ 
	while(*str!='\0') 
	{ 
		LCD_Write(LCD_DATA,*str); 
		str++; 
	} 
}

//
void LCD_LoadChar(unsigned char user[8], unsigned char place) 
{ 
	unsigned char i; 
	LCD_Write(LCD_COMMAND,0x40|(place*8)); 
	for(i=0; i<8; i++) 
		LCD_Write(LCD_DATA,user[i]); 
}