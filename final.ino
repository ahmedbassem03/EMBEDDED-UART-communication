#include <Arduino.h>
#include <util/delay.h>
#include "ADC.h"
#include "Dior.h"
#include "uart.h"//include all header files 

void loop(){
  setup();
  int adcread;//variable for reading the values to use in uart
  unsigned char buffer[4];//4 strings
  while(1)
  {
  pot();//recall and run these functions in a loop
  lights();
  adcread=adc_read(3);
  itoa(adcread,buffer,10);
  Uart_SendString(buffer);
  }
}

void setup(){//setup or initialise these functions
    pot();
    lights();
    uart_init();
    
}

void pot(void){
  float data;
  Dio_SetPinDirection('D',2,1);//the LED connected to the potentiometer
  Dio_SetPinDirection('C',1,0);//potentiometer connected to pin 1 where it takes input

  adc_init();

  data = adc_read(1);// adc pin 1 which has the readings


  if(data>400){
    

    
    Dio_SetPortDirection('D',2,1);
    
  }
    else
    Dio_SetPortDirection('D',2,0);
    
 
}

void lights(void){
float volt;
  Dio_SetPinDirection('D',6,1);//both LEDs give output
  Dio_SetPinDirection('D',7,1);
  Dio_SetPinDirection('C',3,0);//switch pin 3 takes input

  adc_init();

  volt = adc_read(3);// adc pin 3 which has the readings for the switch system

  
  if(volt>600){
    

    
    Dio_SetPortDirection('D',6,1);// first lamp lights
    _delay_ms(1000);
    Dio_SetPortDirection('D',7,0);//then turns off after 1 second
    _delay_ms(1000);
    Dio_SetPortDirection('D',6,1);//second lamp lights
    _delay_ms(1000);
    Dio_SetPortDirection('D',7,0);//then turns off after 1 second
    _delay_ms(2000);
    Dio_SetPortDirection('D',6,1);//both lamps turn on after 2 seconds
    Dio_SetPortDirection('D',7,1);
    _delay_ms(2000);
    Dio_SetPortDirection('D',6,0);//both lamps turn off after 2 seconds 
    Dio_SetPortDirection('D',7,0);
    _delay_ms(3000);//after 3 seconds it resets

  }
    else
    Dio_SetPortDirection('D',6,0);// if voltage threshhold isnt met the turn off both lamps
    Dio_SetPortDirection('D',7,0);
    
 
}