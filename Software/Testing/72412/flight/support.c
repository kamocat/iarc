/**
@author Daniel Sidlauskas Miller

Source code for flight control support functions
*/

#include <stdlib.h>
#include <avr_compiler.h>
#include <usart_driver.h>
#include <twi_master_driver.h>
#include "support.h"
#include <stdio.h>

/* Set the system clock to 32mhz */
void set_clock( void ) {
	OSC.CTRL = 0b00000010;//Enable oscilator
	while(!(OSC.STATUS & 0b00000010));//wait for it to be ready
	CCPWrite(&CLK.CTRL, 0b00000001);//Enable oscilator
}







			


void sendchar(USART_data_t * uart, char buffer){
	char bytetobuffer;
	do{
		bytetobuffer = USART_TXBuffer_PutByte(uart, buffer);
	}while(!bytetobuffer);

}
void sendstring(USART_data_t * uart, char *buffer){
	int i;
	for(i=0;buffer[i]!=0;i++){
		sendchar(uart, buffer[i]);
	}
}
void sendpacket(USART_data_t * uart, char *buffer){
	int i;
	for(i=0;i<23;i++){
		sendchar(uart, buffer[i]);
	}
}



void CCPWrite( volatile uint8_t * address, uint8_t value )
{
	#if defined __GNUC__
	AVR_ENTER_CRITICAL_REGION( );
	volatile uint8_t * tmpAddr = address;
	#ifdef RAMPZ
	RAMPZ = 0;
	#endif
	asm volatile(
		"movw r30,  %0"      "\n\t"
		"ldi  r16,  %2"      "\n\t"
		"out   %3, r16"      "\n\t"
		"st     Z,  %1"       "\n\t"
		:
		: "r" (tmpAddr), "r" (value), "M" (CCP_IOREG_gc), "i" (&CCP)
		: "r16", "r30", "r31"
	);

	AVR_LEAVE_CRITICAL_REGION( );
	#endif
}



void sprintBinary(char * buffer, int * value){
	int i;
	int k = 2;
	buffer[0] = '0';
	buffer[1] = 'b';
	for(i = 15; i >= 0; i --, k++){
		if(*value & (1 << i)){
			buffer[k] = '1';
		}
		else{
			buffer[k] = '0';
		}
	}
	sprintf(&buffer[18], "\n\r");
}
			
/*TWI Master Initiate*/
void twiInitiate(TWI_Master_t *title,TWI_t *interface){
	TWI_MasterInit(title, interface, TWI_MASTER_INTLVL_HI_gc, TWI_BAUDSETTING);
	interface->MASTER.CTRLB |= 0x04;
}


/*USART Initiate*/
void uartInitiate(USART_data_t * title,USART_t * interface, unsigned long int baudrate){
	USART_InterruptDriver_Initialize(title, interface, USART_DREINTLVL_LO_gc);
	USART_Format_Set(title->usart, USART_CHSIZE_8BIT_gc, USART_PMODE_DISABLED_gc, false);
	USART_RxdInterruptLevel_Set(title->usart, USART_RXCINTLVL_LO_gc);
	
	if(baudrate == 115200){
		USART_Baudrate_Set(interface, 1047, -6);
	}
	else if(baudrate == 38400){
		USART_Baudrate_Set(interface, 3269 , -6);
	}
	else if(baudrate == 9600){
		USART_Baudrate_Set(interface, 3317 , -4);
	}

	USART_Rx_Enable(title->usart);
	USART_Tx_Enable(title->usart);
	
}

void motorSpeed(int * pry,
		int * integration, 
		int * gyroint, 
		int * joystick, 
		int * motorSpeeds,
		int * pidValues13,
		int * pidValues24,
		int * pidValuesDen13,
		int * pidValuesDen24){
	int i;
	int prybuffer[3];
	int xMove;
	int yMove;
	for(i=0;i<3;i++){
		prybuffer[i] = pry[i];
	}
	for(i=0;i<2;i++){
		if(prybuffer[i] > 200){
			prybuffer[i] = 200;
			}
		else if(prybuffer[i] < -200){
			prybuffer[i] = -200;
		}
	}
	for(i = 0; i < 4; i ++){
		motorSpeeds[i] = MOTORREG;
		//Joystick Throttle
		motorSpeeds[i] += joystick[2] * ZJOYSENS + joystick[4] * THROTTLEMAIN;
	}
	//For x axis rotating on Z
	motorSpeeds[0] += (prybuffer[1] * pidValues13[0]/pidValuesDen13[0]) + (gyroint[1] * pidValues13[2]/pidValuesDen13[2]);
	motorSpeeds[2] -= (prybuffer[1] * pidValues13[0]/pidValuesDen13[0]) + (gyroint[1] * pidValues13[2]/pidValuesDen13[2]);
	//Joystick X axis tilt
	xMove = joystick[1] * TILTJOYSENS13;
	motorSpeeds[0] -= xMove;
	motorSpeeds[1] -= xMove;
	motorSpeeds[2] += xMove;
	motorSpeeds[3] += xMove;
	//Joystick Z axis rotate (slow down speed up both motors)
	if(joystick[3] < 0){
		motorSpeeds[0] += joystick[3] * ROTJOYSENSDOWN;
		motorSpeeds[2] += joystick[3] * ROTJOYSENSDOWN;
	}
	else{
		motorSpeeds[0] += joystick[3] * ROTJOYSENSUP;
		motorSpeeds[2] += joystick[3] * ROTJOYSENSUP;
	}
	
	//For y axis rotating on Z
	motorSpeeds[1] += (prybuffer[0] * pidValues24[0]/pidValuesDen24[0]) + (gyroint[0] * pidValues24[2]/pidValuesDen24[2]);
	motorSpeeds[3] -= (prybuffer[0] * pidValues24[0]/pidValuesDen24[0]) + (gyroint[0] * pidValues24[2]/pidValuesDen24[2]);
	//Joystick Y axis tilt
	yMove = joystick[0] * TILTJOYSENS24;
	motorSpeeds[2] -= yMove;
	motorSpeeds[1] -= yMove;
	motorSpeeds[0] += yMove;
	motorSpeeds[3] += yMove;
	//Joystick Z axis rotate (slow down speed up both motors)
	if(joystick[3] > 0){
		motorSpeeds[1] -= joystick[3] * ROTJOYSENSDOWN;
		motorSpeeds[3] -= joystick[3] * ROTJOYSENSDOWN;
	}
	else{
		motorSpeeds[1] -= joystick[3] * ROTJOYSENSUP;
		motorSpeeds[3] -= joystick[3] * ROTJOYSENSUP;
	}

	


}

void yawCorrect(int * motorSpeeds, int * gyroint,int * integration, int * roterr, char * pidRotUp, char * pidRotDenUp, char * pidRotDown, char * pidRotDenDown){
	int roterrup;
	int roterrdown;
	int rotintup;
	int rotintdown;
	int diferrup = gyroint[2] * pidRotUp[2]/pidRotDenUp[2];
	int diferrdown = gyroint[2] * pidRotDown[2]/pidRotDown[2];

	if(diferrup > 0){
		motorSpeeds[0] -= diferrdown;
		motorSpeeds[2] -= diferrdown;
		motorSpeeds[1] += diferrup;
		motorSpeeds[3] += diferrup;
	}
	else{
		motorSpeeds[0] -= diferrup;
		motorSpeeds[2] -= diferrup;
		motorSpeeds[1] += diferrdown;
		motorSpeeds[3] += diferrdown;
	}

	roterrup = *roterr * pidRotUp[0]/pidRotDenUp[0];	
	roterrdown = *roterr * pidRotDown[0]/pidRotDenDown[0];	

	if(roterrup > 0){
		motorSpeeds[0] += roterrup;
		motorSpeeds[2] += roterrup;
		motorSpeeds[1] -= roterrdown;
		motorSpeeds[3] -= roterrdown;
	}
	else{
		motorSpeeds[0] += roterrdown;
		motorSpeeds[2] += roterrdown;
		motorSpeeds[1] -= roterrup;
		motorSpeeds[3] -= roterrup;
	}

	rotintup = integration[2] * pidRotUp[1]/pidRotDenUp[1];
	rotintdown = integration[2] * pidRotDown[1]/pidRotDenDown[1];

	if(rotintup > 0){
		motorSpeeds[0] += rotintup;
		motorSpeeds[2] += rotintup;
		motorSpeeds[1] -= rotintdown;
		motorSpeeds[3] -= rotintdown;
	}
	else{
		motorSpeeds[0] += rotintdown;
		motorSpeeds[2] += rotintdown;
		motorSpeeds[1] -= rotintup;
		motorSpeeds[3] -= rotintup;
	}


}



	




