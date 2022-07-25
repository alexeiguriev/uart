/*
 * Uart.h
 *
 * Created: 7/21/2022 4:59:55 PM
 *  Author: alexei.guriev
 */ 


#ifndef UART_H_
#define UART_H_


#include "uartTypes.h"
#include "TimerSw.h"

StatusError UART_Init(const UartInstanceIndexType instance, UartConfigType * uartConfig);

StatusError UART_Deinit(const UartInstanceIndexType instance);

StatusError UART_InstallRxCallback(const UartInstanceIndexType instance, UartCallbackType function, void * callbackParam);

StatusError UART_InstallTxCallback(const UartInstanceIndexType instance, UartCallbackType function, void * callbackParam);

StatusError UART_SendDataBlocking(const UartInstanceIndexType instance, const UartDataType * txBuff, const uint32_t txSize,const TimerSwValue interval);

StatusError UART_SendDataAsynchrone(const UartInstanceIndexType instance,const UartDataType * txBuff,uint32_t txSize);

StatusError UART_GetTransmitStatus(const UartInstanceIndexType instance, uint32_t * bytesRemaining);

StatusError UART_AbortSendingData(const UartInstanceIndexType instance);

StatusError UART_ReceiveDataBlocking(const UartInstanceIndexType instance, UartDataType * rxBuff, const uint32_t rxSize,const uint32_t interval);

StatusError UART_ReceiveDataAsynchrone(const UartInstanceIndexType instance, UartDataType * rxBuff, const uint32_t rxSize);

StatusError UART_GetReceiveStatus(const UartInstanceIndexType instance, uint32_t * bytesRemaining);

StatusError UART_SetBaudRate(const UartInstanceIndexType instance, const UartDataType desiredBaudRate);

StatusError UART_GetBaudRate(const UartInstanceIndexType instance, UartDataType* desiredBaudRate);



#endif /* UART_H_ */