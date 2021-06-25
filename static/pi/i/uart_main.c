/*
 * uart_main.c
 *
 *  Created on: Jun 23, 2021
 *      Author: AlexeiAROBS
 */
/* include */
#include "com/uart/static/if/uart.h"

/* local variables */

const uart_interfaces * uartInterfaces;
/* static functions */

/* public functions */
statusType UART_vDoSetInterface(const uart_interfaces * interfaces)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	if (interfaces->init == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->deinit == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->installRxCallback == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->installTxCallback == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->sendDataBlocking == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->sendDataAsynchrone == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->getTransmitStatus == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->abortSendingData == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->receiveDataBlocking == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->receiveDataAsynchrone == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->getReceiveStatus == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->setBaudRate == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}
	if (interfaces->getBaudRate == NULL)
	{
		retStatus |= AX_STATUS_NULL_PTR;
	}

	if (retStatus == AX_STATUS_SUCCESS)
	{
		uartInterfaces = interfaces;
	}


	return retStatus;

}

statusType UART_Init(const uart_instanceType instance, uartConfigType * uartConfig)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->init(instance, uartConfig);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_Deinit(const uart_instanceType instance)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->deinit(instance);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_InstallRxCallback(const uart_instanceType instance, uart_callbackType function, void * callbackParam)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->installRxCallback(instance,function,callbackParam);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_InstallTxCallback(const uart_instanceType instance, uart_callbackType function, void * callbackParam)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->installTxCallback(instance,function,callbackParam);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_SendDataBlocking(const uart_instanceType instance, const uart_dataType * rxBuff, const uint32_t rxSize,const uint32_t timeout)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->sendDataBlocking(instance,rxBuff,rxSize,timeout);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_SendDataAsynchrone(const uart_instanceType instance,const uint8_t * txBuff,uint32_t txSize)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->sendDataAsynchrone(instance,txBuff,txSize);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_GetTransmitStatus(const uart_instanceType instance, uint32_t * bytesRemaining)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->getTransmitStatus(instance,bytesRemaining);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_AbortSendingData(const uart_instanceType instance)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->abortSendingData(instance);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_ReceiveDataBlocking(const uart_instanceType instance, uart_dataType * rxBuff, const uint32_t rxSize,const uint32_t timeout)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->receiveDataBlocking(instance,rxBuff,rxSize,timeout);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_ReceiveDataAsynchrone(const uart_instanceType instance, uart_dataType * rxBuff, const uint32_t rxSize)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->receiveDataAsynchrone(instance,rxBuff,rxSize);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_GetReceiveStatus(const uart_instanceType instance, uint32_t * bytesRemaining)
{
	statusType retStatus = AX_STATUS_SUCCESS;
	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->getReceiveStatus(instance,bytesRemaining);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}
	return retStatus;
}

statusType UART_SetBaudRate(const uart_instanceType instance, const uart_baudRateType desiredBaudRate)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->setBaudRate(instance,desiredBaudRate);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}

	return retStatus;
}

statusType UART_GetBaudRate(const uart_instanceType instance, const uart_baudRateType* desiredBaudRate)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	if(uartInterfaces->init != NULL)
	{
		retStatus = uartInterfaces->getBaudRate(instance,desiredBaudRate);
	}
	else
	{
		retStatus = AX_STATUS_NULL_PTR;
	}

	return retStatus;
}

