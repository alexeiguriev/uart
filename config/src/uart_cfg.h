/*
 * uart_cfg.h
 *
 *  Created on: Jun 22, 2021
 *      Author: AlexeiAROBS
 */

#ifndef AX_UART_CFG_H_
#define AX_UART_CFG_H_

#include "lpuart1.h"

typedef enum
{
	uart_instance = INST_LPUART1,
}uart_instanceDefType;

typedef struct
{
	lpuart_state_t * lpuartStatePtr;
	const lpuart_user_config_t * lpuartUserConfig;

}uart_congigDefType;

typedef uint32_t uart_baudRateDefType;
typedef uint8_t uart_dataDefType;
typedef uart_callback_t uart_callbackDefType;



#endif /* AX_UART_CFG_H_ */
