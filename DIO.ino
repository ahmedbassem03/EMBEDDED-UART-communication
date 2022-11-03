
#include <avr/io.h>

#define SetBit(Reg,Pin) (Reg |= (1<<Pin))
#define ClearBit(Reg,Pin) (Reg &=~ (1<<Pin))
#define ToggleBit(Reg,Pin) (Reg ^= (1<<Pin))
#define GetBit(Reg,Pin) (Reg&(1<<Pin))
#include "Dio.h"

void Dio_SetPinDirection(unsigned char DDRX, unsigned char Pin,unsigned char Direction){//function for setting DDR, pin in the DDR, and whether it's direction is output or input
  switch (DDRX) //switch case for registors
  {
    
       case 'B'://DDRB
    if (Direction == 1)//direction output
    {
      SetBit(DDRB,Pin);//set which pin in DDRB
     
    }
    else{
      ClearBit(DDRB,Pin); //otherwise clear pin in DDRB      
      
    }
    break;
        case 'C':
    if (Direction == 1)
    {
      SetBit(DDRC,Pin); 
      
    }
    else{
      ClearBit(DDRC,Pin);       
      
    }
    break;
        case 'D':
    if (Direction == 1)
    {
      SetBit(DDRD,Pin);      
      
    }
    else{
      ClearBit(DDRD,Pin);      
      
    }
    break;
}
}
unsigned char Dio_GetPinState(unsigned char Port,unsigned char pin){//function to read port and pin value
  int BitValue;
  switch(Port){
    
    case 'B':
    BitValue = GetBit(PORTB,pin);//recieve vaue from the pin to show if its output or input 
    break;
    case 'C':
    BitValue = GetBit(PORTC,pin);//shows if PORTC is input or output
    break;
    case 'D':
    BitValue = GetBit(PORTD,pin);
    break;
  }
  return BitValue;
}
void Dio_SetPortDirection(unsigned char PORTX, unsigned char Pin,unsigned char Direction){//function to chose PORT, PIN, and either output or input
  switch (PORTX)//switch case for ports
  {
    
       case 'B'://PORTB
    if (Direction == 1)//direction output
    {
      SetBit(PORTB,Pin);//which pin in PORTB     
     
    }
    else{
      ClearBit(PORTB,Pin);       
      
    }
    break;
        case 'C':
    if (Direction == 1)//set PORTC as output
    {
      SetBit(PORTC,Pin); 
      
    }
    else{
      ClearBit(PORTC,Pin);       
      
    }
    break;
        case 'D':
    if (Direction == 1)
    {
      SetBit(PORTD,Pin);//which pin in PORTD    
      
    }
    else{
      ClearBit(PORTD,Pin);//clear the pin   
      
    }
    break;
}
}