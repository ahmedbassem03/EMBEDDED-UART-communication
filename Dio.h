#ifndef _Dio_h_
#define _Dio_h_
void Dio_SetPinDirection(unsigned char DDRX, unsigned char Pin,unsigned char Direction);
unsigned char Dio_GetPinState(unsigned char Port,unsigned char pin);
void Dio_SetPortDirection(unsigned char PORTX, unsigned char Pin,unsigned char Direction);
#endif