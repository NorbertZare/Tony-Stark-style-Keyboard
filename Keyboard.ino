#include <Wire.h>
#include "paj7620.h"
#include "DigiKeyboard.h"
 
#define GES_REACTION_TIME		800
#define GES_QUIT_TIME			1000

byte i;

void setup()
{
	uint8_t error = 0;

	error = paj7620Init();			// initialize Paj7620 registers
 
DigiKeyboard.sendKeyStroke(0);
delay (100);

}

void loop()
{
	uint8_t data = 0, data1 = 0, error; 

	error = paj7620ReadReg(0x43, 1, &data);				// Read Bank_0_Reg_0x43/0x44 for gesture result.
	if (!error) 
	{
		switch (data) 									// When different gestures be detected, the variable 'data' will be set to different values by paj7620ReadReg(0x43, 1, &data).
		{
			case GES_RIGHT_FLAG:
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_LEFT_FLAG) 
				{
					//("Right-Left");
				}
				else if(data == GES_FORWARD_FLAG) 
				{
					delay(GES_QUIT_TIME);
				}
				else if(data == GES_BACKWARD_FLAG) 
				{
					delay(GES_QUIT_TIME);
				}
				else
				{
         DigiKeyboard.sendKeyStroke(0);
         DigiKeyboard.sendKeyStroke(KEY_O, MOD_GUI_LEFT | MOD_CONTROL_LEFT);
       delay(200);
					//("Right");
				}          
				break;
			case GES_LEFT_FLAG:
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_RIGHT_FLAG) 
				{
					//("Left-Right");
				}
				else if(data == GES_FORWARD_FLAG) 
				{
					delay(GES_QUIT_TIME);
				}
				else if(data == GES_BACKWARD_FLAG) 
				{
					delay(GES_QUIT_TIME);
				}
				else
				{
        
         DigiKeyboard.sendKeyStroke(0);
         DigiKeyboard.sendKeyStroke(KEY_O, MOD_GUI_LEFT | MOD_CONTROL_LEFT);
       delay(200);
					//("Left");
				}          
				break;
				break;
			case GES_UP_FLAG:
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_DOWN_FLAG) 
				{
					//("Up-Down");
				}
				else if(data == GES_FORWARD_FLAG) 
				{
					delay(GES_QUIT_TIME);
				}
				else if(data == GES_BACKWARD_FLAG) 
				{
					delay(GES_QUIT_TIME);
				}
				else
				{
					//("Up");
				}
				break;
			case GES_DOWN_FLAG:
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_UP_FLAG)
				{
					//("Down-Up");
				}
				else if(data == GES_FORWARD_FLAG) 
				{
					delay(GES_QUIT_TIME);
				}
				else if(data == GES_BACKWARD_FLAG) 
				{
					delay(GES_QUIT_TIME);
				}
				else
				{
					//("Down");
				}
				break;
			case GES_FORWARD_FLAG:
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_BACKWARD_FLAG) 
				{
					//("Forward-Backward");
					delay(GES_QUIT_TIME);
				}
				else
				{
					delay(GES_QUIT_TIME);
				}
				break;
			case GES_BACKWARD_FLAG:		  
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_FORWARD_FLAG) 
				{
					//("Backward-Forward");
					delay(GES_QUIT_TIME);
				}
				else
				{
					delay(GES_QUIT_TIME);
				}
				break;
			case GES_CLOCKWISE_FLAG:
				//("Clockwise");
				break;
			case GES_COUNT_CLOCKWISE_FLAG:
				//("anti-clockwise");
				break;  
			default:
				paj7620ReadReg(0x44, 1, &data1);
				if (data1 == GES_WAVE_FLAG) 
				{
					//("wave");
				}
				break;
		}
	}
	delay(200);
}
