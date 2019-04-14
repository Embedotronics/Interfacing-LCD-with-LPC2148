#include <lpc214x.h>
 

void initLCD(void);
//void enable(void);
void LCD_Write(unsigned int c);
void LCD_Cmd(unsigned int LCD_Cmd);
void delay(void);


int main(void)
{
	unsigned char ch[]="Embedotronics";
	  unsigned char ch1[]="Technologies";
	  unsigned int i,j,k,t;
	
    initLCD();
	
    for(i=0;ch[i]!='\0';i++)
	    LCD_Write(ch[i]);

		LCD_Cmd(0xc3);
    for(j=0;ch1[j]!='\0';j++)
	{
		LCD_Write(ch1[j]);
 	 }
	 while(1){
	for(k=0;k<16;k++)
	{
	LCD_Cmd(0x1c);
	for(t=0;t<300000;t++);
	}
	}
}

void initLCD(void)
{
    IO0DIR = 0x0FFFF00;
    delay(); //Initial Delay
    LCD_Cmd(0x38);
		LCD_Cmd(0x01);
		LCD_Cmd(0x0c);
		LCD_Cmd(0x83);
		LCD_Cmd(0x06);
}

void LCD_Write(unsigned int c)
{
    IO0PIN = (c<<16)|(1<<10); 
    delay(); //Pulse Enable to process it
}
       
void LCD_Cmd(unsigned int LCD_Cmd)
{
    IO0PIN = (LCD_Cmd<<16)|(0<<10);
    delay(); //Pulse Enable to process it
}

void delay(void)
{
    int i=0,x=0;
	    IO0PIN|=(1<<13);
    for(i=0; i<19999; i++)
    { 
			x++; 
		}
			IO0PIN&=~(1<<13);
}
