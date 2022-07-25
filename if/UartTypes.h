/*
 * UartTypes.h
 *
 * Created: 7/21/2022 4:35:46 PM
 *  Author: alexei.guriev
 */ 


#ifndef UARTTYPES_H_
#define UARTTYPES_H_

#include <stdint.h>
#include <stdbool.h>
#include "StatuError.h"

typedef uint32_t UartBaudRateType;

typedef enum
{
	UartStopBitOne,
	UartStopBitTwo,
}UartStopBitType;

typedef enum
{
	Uart5Bit = 5,
	Uart6Bit = 6,
	Uart7Bit = 7,
	Uart8Bit = 8,
	Uart9Bit = 9
}UartBitCountPerCharType;

typedef enum
{
	UartParityDisabled,
	UartParityEven,
	UartParityOdd
}UartParityModeType;

typedef struct
{
	bool					usingInterrupt;
	UartBaudRateType		baudRate;
	UartParityModeType		pariryMode;
	UartStopBitType			stopBit;
	UartBitCountPerCharType	bitCountPerChar;
	void *					callbackParam;
}UartConfigType;

typedef uint8_t UartDataType;
typedef void (*UartCallbackType)(uint8_t);

typedef struct
{
    const uint8_t * txBuff;              /*!< The buffer of data being sent.*/
    uint8_t * rxBuff;                    /*!< The buffer of received data.*/
    volatile uint32_t txSize;            /*!< The remaining number of bytes to be transmitted. */
    volatile uint32_t rxSize;            /*!< The remaining number of bytes to be received. */
    volatile bool isTxBusy;              /*!< True if there is an active transmit.*/
    volatile bool isRxBusy;              /*!< True if there is an active receive.*/
    volatile bool isTxBlocking;          /*!< True if transmit is blocking transaction. */
    volatile bool isRxBlocking;          /*!< True if receive is blocking transaction. */
    UartBitCountPerCharType bitCountPerChar; /*!< number of bits in a char (8/9/10) */
    UartCallbackType rxCallback;          /*!< Callback to invoke for data receive
                                              Note: when the transmission is interrupt based, the callback
                                              is being called upon receiving a byte; when DMA transmission
                                              is used, the bytes are copied to the rx buffer by the DMA engine
                                              and the callback is called when all the bytes have been transferred. */
    void * rxCallbackParam;              /*!< Receive callback parameter pointer.*/
    UartCallbackType txCallback;          /*!< Callback to invoke for data send
                                              Note: when the transmission is interrupt based, the callback
                                              is being called upon sending a byte; when DMA transmission
                                              is used, the bytes are copied to the tx buffer by the DMA engine
                                              and the callback is called when all the bytes have been transferred. */
    void * txCallbackParam;              /*!< Transmit callback parameter pointer.*/
    bool usingInterrupt;				/*!< Type of LPUART transfer (interrupt/dma based) */

    bool rxComplete;              /*!< Synchronization object for blocking Rx timeout condition */
    bool txComplete;              /*!< Synchronization object for blocking Tx timeout condition */
    volatile StatusError transmitStatus;    /*!< Status of last driver transmit operation */
    volatile StatusError receiveStatus;     /*!< Status of last driver receive operation */
}UartInstanceType;

typedef uint8_t UartInstanceIndexType;

/*!
 * @brief uart driver interfaces.
 *
 * this function include all uart interfaces.
 *
 * Implements : uart_interfaces
 */
typedef struct
{
	StatusError (*init)(const UartInstanceType instance, UartConfigType * uartConfig);
	StatusError (*deinit)(const UartInstanceType instance);
	StatusError (*installRxCallback)(const UartInstanceType instance, UartCallbackType function, void * callbackParam);
	StatusError (*installTxCallback)(const UartInstanceType instance, UartCallbackType function, void * callbackParam);
	StatusError (*sendDataBlocking)(const UartInstanceType instance, const UartDataType * rxBuff, const uint32_t rxSize,const uint32_t timeout);
	StatusError (*sendDataAsynchrone)(const UartInstanceType instance,const uint8_t * txBuff,uint32_t txSize);
	StatusError (*getTransmitStatus)(const UartInstanceType instance, uint32_t * bytesRemaining);
	StatusError (*abortSendingData)(const UartInstanceType instance);
	StatusError (*receiveDataBlocking)(const UartInstanceType instance, UartDataType * rxBuff, const uint32_t rxSize,const uint32_t timeout);
	StatusError (*receiveDataAsynchrone)(const UartInstanceType instance, UartDataType * rxBuff, const uint32_t rxSize);
	StatusError (*getReceiveStatus)(const UartInstanceType instance, uint32_t * bytesRemaining);
	StatusError (*setBaudRate)(const UartInstanceType instance, const UartBaudRateType desiredBaudRate);
	StatusError (*getBaudRate)(const UartInstanceType instance, UartBaudRateType* desiredBaudRate);
}uart_interfaces;





#endif /* UARTTYPES_H_ */