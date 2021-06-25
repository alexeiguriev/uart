/*
 * uartCfg.c
 *
 *  Created on: Jun 25, 2021
 *      Author: AlexeiAROBS
 */

/* Local variables */


#include "com/uart/static/if/uart_types.h"

const uart_interfaces UARTuart_interfaces;

statusType UART_InitInterfaceCfg(const uart_instanceType instance, uartConfigType * uartConfig)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_Init(instance, uartConfig->lpuartStatePtr,uartConfig->lpuartUserConfig);

	return retStatus;
}

statusType UART_DeinitInterfaceCfg(const uart_instanceType instance)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_Deinit(instance);

	return retStatus;
}

statusType UART_InstallRxCallbackInterfaceCfg(const uart_instanceType instance, uart_callbackType function, void * callbackParam)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_InstallRxCallback(instance,function,callbackParam);

	return retStatus;
}

statusType UART_InstallTxCallbackInterfaceCfg(const uart_instanceType instance, uart_callbackType function, void * callbackParam)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_InstallTxCallback(instance,function,callbackParam);

	return retStatus;
}

statusType UART_SendDataBlockingInterfaceCfg(const uart_instanceType instance, const uart_dataType * rxBuff, const uint32_t rxSize,const uint32_t timeout)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_SendDataBlocking(instance,rxBuff,rxSize,timeout);

	return retStatus;
}

statusType UART_SendDataAsynchroneInterfaceCfg(const uart_instanceType instance,const uint8_t * txBuff,uint32_t txSize)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_SendData(instance,txBuff,txSize);

	return retStatus;
}

statusType UART_GetTransmitStatusInterfaceCfg(const uart_instanceType instance, uint32_t * bytesRemaining)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_GetTransmitStatus(instance,bytesRemaining);

	return retStatus;
}

statusType UART_AbortSendingDataInterfaceCfg(const uart_instanceType instance)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_AbortSendingData(instance);

	return retStatus;
}

statusType UART_ReceiveDataBlockingInterfaceCfg(const uart_instanceType instance, uart_dataType * rxBuff, const uint32_t rxSize,const uint32_t timeout)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_ReceiveDataBlocking(instance,rxBuff,rxSize,timeout);

	return retStatus;
}

statusType UART_ReceiveDataAsynchroneInterfaceCfg(const uart_instanceType instance, uart_dataType * rxBuff, const uint32_t rxSize)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_ReceiveData(instance,rxBuff,rxSize);

	return retStatus;
}

statusType UART_GetReceiveStatusInterfaceCfg(const uart_instanceType instance, uint32_t * bytesRemaining)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_GetReceiveStatus(instance,bytesRemaining);

	return retStatus;
}

statusType UART_SetBaudRateInterfaceCfg(const uart_instanceType instance, const uart_baudRateType desiredBaudRate)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	retStatus = (statusType)LPUART_DRV_SetBaudRate(instance,desiredBaudRate);

	return retStatus;
}

statusType UART_GetBaudRateInterfaceCfg(const uart_instanceType instance, uart_baudRateType* desiredBaudRate)
{
	statusType retStatus = AX_STATUS_SUCCESS;

	LPUART_DRV_GetBaudRate(instance,desiredBaudRate);

	return retStatus;
}
const uart_interfaces UARTuart_interfaces =
{
		.init = UART_InitInterfaceCfg,
		.deinit = UART_DeinitInterfaceCfg,
		.installRxCallback = UART_InstallRxCallbackInterfaceCfg,
		.installTxCallback = UART_InstallTxCallbackInterfaceCfg,
		.sendDataBlocking = UART_SendDataBlockingInterfaceCfg,
		.sendDataAsynchrone = UART_SendDataAsynchroneInterfaceCfg,
		.getTransmitStatus = UART_GetTransmitStatusInterfaceCfg,
		.abortSendingData = UART_AbortSendingDataInterfaceCfg,
		.receiveDataBlocking = UART_ReceiveDataBlockingInterfaceCfg,
		.receiveDataAsynchrone = UART_ReceiveDataAsynchroneInterfaceCfg,
		.getReceiveStatus = UART_GetReceiveStatusInterfaceCfg,
		.setBaudRate = UART_SetBaudRateInterfaceCfg,
		.getBaudRate = UART_GetBaudRateInterfaceCfg
};
