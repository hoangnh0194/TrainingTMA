#ifndef LCD_1602_H_ 
#define LCD_1602_H_
 
#include <intrins.h>
//define pins
#define Rs
#define En
#define Rw
#define DB4
#define DB5
#define DB6
#define DB7
// 
#define LCD_COMMAND			0       
#define LCD_DATA			1      
#define LCD_CLEAR_SCREEN	0x01       
#define LCD_HOMING  		0x02      

 
// 
#define LCD_SHOW			0x04    
#define LCD_HIDE			0x00    	   
#define LCD_CURSOR			0x02 	
#define LCD_NO_CURSOR		        0x00    		      
#define LCD_FLASH			0x01     
#define LCD_NO_FLASH		        0x00    
// 
#define LCD_AC_UP			0x02 
#define LCD_AC_DOWN			0x00     
#define LCD_MOVE			0x01     
#define LCD_NO_MOVE			0x00   
#define LCD_CURSOR		0x02       
#define LCD_SCREEN		0x08 
#define LCD_LEFT		0x00 
/////
#define LCD_RIGHT		0x04 
unsigned char LCD_Wait(void);
void LCD_Write(bit style, unsigned char input);
void LCD_SetDisplay(unsigned char DisplayMode);
void LCD_SetInput(unsigned char InputMode);
void LCD_Move(unsigned char object, unsigned char direction);
void LCD_Initial();
void GotoXY(unsigned char x, unsigned char y); 
void Print(unsigned char *str);
void LCD_LoadChar(unsigned char user[8], unsigned char place); 

#endif