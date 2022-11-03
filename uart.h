#ifndef _UART_H
#define _UART_H
void Uart_SetBaudRate(unsigned short BuadRate);
void uart_init();
void sent_uartdata(char data);
char recieve_uartdata();
void Uart_SendString(const char DataString[]);
#endif