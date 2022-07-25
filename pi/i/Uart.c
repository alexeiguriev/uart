/*
 * Uart.c
 *
 * Created: 7/21/2022 5:01:40 PM
 *  Author: alexei.guriev
 */ 

#include "uart.h"
#include "uartCnf.h"
#include "TimerCfg/TimerCfg.h"

/* local variables */

const uart_interfaces * uartInterfaces;
static UartInstanceType s_instatnces[UART_INSTANCE_COUNT];
static uint32_t s_txCounter[UART_INSTANCE_COUNT];
static uint32_t s_rxCounter[UART_INSTANCE_COUNT];
TimerSwHandle timerSwHandle;
/* static functions */
static void s_UartConfigCallbackType(uint8_t channel,UartDataType data);

/* public functions */
StatusError UART_Init(const UartInstanceIndexType instance, UartConfigType * uartConfig)
{
	StatusError err;
	if (instance >= UART_INSTANCE_COUNT)
	{
		return StatusErrIndex;
	}
	
	TimerSwInitParam *pTimerSwInitParam = TimerGetIntervalPointerCfg();
	
	err = TimerSwInit(pTimerSwInitParam,&timerSwHandle);
	
	if (err != StatusErrNone)
	{
		return err;
	}
	
	err = UartCfgInit(instance,uartConfig);
	
	if (err != StatusErrNone)
	{
		return err;
	}
	
	return StatusErrNone;
}

StatusError UART_Deinit(const UartInstanceIndexType instance)
{
	return StatusErrNotImplemented;
}

StatusError UART_InstallRxCallback(const UartInstanceIndexType instance, UartCallbackType function, void * callbackParam)
{
	if (instance >= UART_INSTANCE_COUNT)
	{
		return StatusErrIndex;
	}
	
	UartInstanceType * uartInstance = &s_instatnces[instance];

	uartInstance->rxCallback = function;
	uartInstance->rxCallbackParam = function;
	
	return StatusErrNone;
}

StatusError UART_InstallTxCallback(const UartInstanceIndexType instance, UartCallbackType function, void * callbackParam)
{
	if (instance >= UART_INSTANCE_COUNT)
	{
		return StatusErrIndex;
	}
	
	UartInstanceType * uartInstance = &s_instatnces[instance];

	uartInstance->txCallback = function;
	uartInstance->txCallbackParam = function;
	
	return StatusErrNone;
}

StatusError UART_SendDataBlocking(const UartInstanceIndexType instance, const UartDataType * txBuff, const uint32_t txSize,const TimerSwValue interval)
{
	StatusError err;
	uint32_t txCounter = 0;
	if (instance >= UART_INSTANCE_COUNT)
	{
		return StatusErrIndex;
	}

	UartInstanceType * uartInstance = &s_instatnces[instance];
	//if (true == uartInstance->isRxBusy)
	//{
		//return StatusErrBusy;
	//}
//
	//uartInstance->isRxBusy = true;
	
	err = TimerSwStartup(&timerSwHandle,interval);
	
	if (err != StatusErrNone)
	{
		uartInstance->isRxBusy = false;
		return StatusErrLayer;
	}
	while(txCounter < txSize)
	{
		err = TimerSwIsExpired(&timerSwHandle);
		
		if (err == StatusErrTime)
		{
			uartInstance->isRxBusy = false;
			return err;
		}
		
		if (true == UartCfgCheckIsTxBuffIsEmpty(instance))
		{
			UartCfgSendOneByte(instance,txBuff[txCounter]);
			txCounter++;
		}
	}
	
	uartInstance->isRxBusy = false;
	return StatusErrNone;
}

StatusError UART_SendDataAsynchrone(const UartInstanceIndexType instance,const UartDataType * txBuff,uint32_t txSize)
{
	return StatusErrNotImplemented;
}

StatusError UART_GetTransmitStatus(const UartInstanceIndexType instance, uint32_t * bytesRemaining)
{
	return StatusErrNotImplemented;
}

StatusError UART_AbortSendingData(const UartInstanceIndexType instance)
{
	return StatusErrNotImplemented;
}

StatusError UART_ReceiveDataBlocking(const UartInstanceIndexType instance, UartDataType * rxBuff, const uint32_t rxSize,const uint32_t interval)
{
	StatusError err;
	uint32_t rxCounter = 0;
	
	if (instance >= UART_INSTANCE_COUNT)
	{
		return StatusErrIndex;
	}
	UartInstanceType * uartInstance = &s_instatnces[instance];
	
	if (true == uartInstance->isRxBusy)
	{
		return StatusErrBusy;
	}
	
	uartInstance->isRxBusy = true;
	
	err = TimerSwStartup(&timerSwHandle,interval);
	
	if (err != StatusErrNone)
	{
		uartInstance->isRxBusy = false;
		return StatusErrLayer;
	}
	
	while(rxCounter < rxSize)
	{
		err = TimerSwIsExpired(&timerSwHandle);
		
		if (err == StatusErrTime)
		{
			uartInstance->isRxBusy = false;
			return err;
		}
		
		if (true == UartCfgCheckIsRxDataIsReceived(instance))
		{
			rxBuff[rxCounter] = UartCfgGetOneByte(instance);
			rxCounter++;
		}
	}
	
	uartInstance->isRxBusy = false;
	return StatusErrNone;
}

StatusError UART_ReceiveDataAsynchrone(const UartInstanceIndexType instance, UartDataType * rxBuff, const uint32_t rxSize)
{
	if (instance >= UART_INSTANCE_COUNT)
	{
		return StatusErrIndex;
	}
	if (rxBuff == NULL)
	{
		return StatusErrParam;
	}
	
	UartCfgSetRxBuffer(instance,s_UartConfigCallbackType);
	
	UartInstanceType * uartInstance = &s_instatnces[instance];
	
	if (true == uartInstance->isRxBusy)
	{
		return StatusErrBusy;
	}
	
	uartInstance->rxBuff = rxBuff;
	uartInstance->rxSize = rxSize;
	uartInstance->isRxBusy = true;
	s_rxCounter[instance] = 0;
	
	UartCfgRxInterruptEnable(instance, true);
	
	return StatusErrNone;
}

StatusError UART_GetReceiveStatus(const UartInstanceIndexType instance, uint32_t * bytesRemaining)
{
	return StatusErrNotImplemented;
}

StatusError UART_SetBaudRate(const UartInstanceIndexType instance, const UartDataType desiredBaudRate)
{
	return StatusErrNotImplemented;
}

StatusError UART_GetBaudRate(const UartInstanceIndexType instance, UartDataType* desiredBaudRate)
{
	return StatusErrNotImplemented;
}


/* local functions */

static void s_UartConfigCallbackType(uint8_t channel,UartDataType data)
{
	if (channel < UART_INSTANCE_COUNT)
	{
		UartInstanceType * uartInstance = &s_instatnces[channel];
		
		s_instatnces[channel].rxBuff[s_rxCounter[channel]] = data;
		s_rxCounter[channel]++;
		
		if (s_rxCounter[channel] >= uartInstance->rxSize)
		{
			if (uartInstance->rxCallback != NULL)
			{
				uartInstance->rxCallback(channel);
			}
			UartCfgRxInterruptEnable(channel, false);
			uartInstance->isRxBusy = false;
		}
	}
	
}
