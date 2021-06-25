/*
 * uart_types.h
 *
 *  Created on: Jun 22, 2021
 *      Author: AlexeiAROBS
 */

#ifndef AX_UART_TYPES_H_
#define AX_UART_TYPES_H_

#include "general/static/if/general.h"
#include "com/uart/config/src/uart_cfg.h"

typedef uart_instanceDefType uart_instanceType;
typedef uart_baudRateDefType uart_baudRateType;
typedef uart_dataDefType uart_dataType;
typedef uart_congigDefType uartConfigType;
typedef uart_callbackDefType uart_callbackType;

/*!
 * @brief uart driver interfaces.
 *
 * this function include all uart interfaces.
 *
 * Implements : uart_interfaces
 */
typedef struct
{
	statusType (*init)(const uart_instanceType instance, uartConfigType * uartConfig);
	statusType (*deinit)(const uart_instanceType instance);
	statusType (*installRxCallback)(const uart_instanceType instance, uart_callbackType function, void * callbackParam);
	statusType (*installTxCallback)(const uart_instanceType instance, uart_callbackType function, void * callbackParam);
	statusType (*sendDataBlocking)(const uart_instanceType instance, const uart_dataType * rxBuff, const uint32_t rxSize,const uint32_t timeout);
	statusType (*sendDataAsynchrone)(const uart_instanceType instance,const uint8_t * txBuff,uint32_t txSize);
	statusType (*getTransmitStatus)(const uart_instanceType instance, uint32_t * bytesRemaining);
	statusType (*abortSendingData)(const uart_instanceType instance);
	statusType (*receiveDataBlocking)(const uart_instanceType instance, uart_dataType * rxBuff, const uint32_t rxSize,const uint32_t timeout);
	statusType (*receiveDataAsynchrone)(const uart_instanceType instance, uart_dataType * rxBuff, const uint32_t rxSize);
	statusType (*getReceiveStatus)(const uart_instanceType instance, uint32_t * bytesRemaining);
	statusType (*setBaudRate)(const uart_instanceType instance, const uart_baudRateType desiredBaudRate);
	statusType (*getBaudRate)(const uart_instanceType instance, const uart_baudRateType* desiredBaudRate);
}uart_interfaces;


#endif /* AX_UART_TYPES_H_ */
