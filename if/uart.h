/*
 * uart.h
 *
 *  Created on: Jun 22, 2021
 *      Author: AlexeiAROBS
 */

#ifndef AX_UART_H_
#define AX_UART_H_

#include "uart_types.h"

statusType UART_vDoSetInterface(const uart_interfaces * interfaces);

statusType UART_Init(const uart_instanceType instance, uartConfigType * uartConfig);

statusType UART_Deinit(const uart_instanceType instance);

statusType UART_InstallRxCallback(const uart_instanceType instance, uart_callbackType function, void * callbackParam);

statusType UART_InstallTxCallback(const uart_instanceType instance, uart_callbackType function, void * callbackParam);

statusType UART_SendDataBlocking(const uart_instanceType instance, const uart_dataType * rxBuff, const uint32_t rxSize,const uint32_t timeout);

statusType UART_SendDataAsynchrone(const uart_instanceType instance,const uint8_t * txBuff,uint32_t txSize);

statusType UART_GetTransmitStatus(const uart_instanceType instance, uint32_t * bytesRemaining);

statusType UART_AbortSendingData(const uart_instanceType instance);

statusType UART_ReceiveDataBlocking(const uart_instanceType instance, uart_dataType * rxBuff, const uint32_t rxSize,const uint32_t timeout);

statusType UART_ReceiveDataAsynchrone(const uart_instanceType instance, uart_dataType * rxBuff, const uint32_t rxSize);

statusType UART_GetReceiveStatus(const uart_instanceType instance, uint32_t * bytesRemaining);

statusType UART_SetBaudRate(const uart_instanceType instance, const uart_baudRateType desiredBaudRate);

statusType UART_GetBaudRate(const uart_instanceType instance, const uart_baudRateType* desiredBaudRate);


#endif /* AX_UART_H_ */
