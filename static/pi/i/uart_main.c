/*
 * uart_main.c
 *
 *  Created on: Jun 23, 2021
 *      Author: AlexeiAROBS
 */
/* include */
#include "Ax_driver/uart_com/static/if/uart.h"

/* local variables */

uart_interfaces * uartInterfaces;
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
	if (interfaces->sendData == NULL)
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

	return retStatus;
}

statusType UART_Deinit(const uart_instanceType instance)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_InstallRxCallback(const uart_instanceType instance, uart_callbackType function, const void * callbackParam)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_InstallTxCallback(const uart_instanceType instance, uart_callbackType function, const void * callbackParam)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_SendDataBlocking(const uart_instanceType instance, const uart_dataType * rxBuff, const uint32_t rxSize,const uint32_t timeout)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_SendData(const uart_instanceType instance, const uint32_t * bytesRemaining)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_GetTransmitStatus(const uart_instanceType instance, const uint32_t * bytesRemaining)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_AbortSendingData(const uart_instanceType instance)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_ReceiveDataBlocking(const uart_instanceType instance, const uart_dataType * rxBuff, const uint32_t rxSize,const uint32_t timeout)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_ReceiveDataAsynchrone(const uart_instanceType instance, const uart_dataType * rxBuff, const uint32_t rxSize)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_GetReceiveStatus(const uart_instanceType instance, const uint32_t * bytesRemaining)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_SetBaudRate(const uart_instanceType instance, const uart_baudRateType desiredBaudRate)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

statusType UART_SetBaudRate(const uart_instanceType instance, const uart_baudRateType* desiredBaudRate)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	return retStatus;
}

