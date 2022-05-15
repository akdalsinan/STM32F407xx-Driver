#include "USART.h"



/*
 * @brief USART_Init,Configures the USART peripheral
 *
 * @param USART_Handle=User config structure
 *
 * @retval void
 */
void USART_Init(USART_HandleTypedef_t *USART_Handle)
{
	uint32_t PeriphClock=0;
	uint32_t mantissaPart=0;
	uint32_t fractionPart=0;
	uint32_t USART_DIV_Value=0;
	uint32_t tempReg=0;

	/****************** OverSampling		Parity		WordLength		Mode *****************/

	uint32_t tempValue = 0;
	tempValue=USART_Handle->Instance->CR1;
	tempValue |= (USART_Handle->Init.OverSampling) | (USART_Handle->Init.Parity) | (USART_Handle->Init.WordLength) | (USART_Handle->Init.Mode);
	USART_Handle->Instance->CR1=tempValue;


	/****************** StopBits *****************/

	tempValue=USART_Handle->Instance->CR2;
	tempValue=(0x3U << 12U); //12.biti clearlama işlemi
	tempValue |= (USART_Handle->Init.StopBits);
	USART_Handle->Instance->CR2=tempValue;


	/****************** HardWareFlowControl *****************/

	tempValue=USART_Handle->Instance->CR3;
	tempValue |= (USART_Handle->Init.HardWareFlowControl);
	USART_Handle->Instance->CR3=tempValue;

	/****************** Baud Rate Config   ******************/
	/*
	 * USART1 ve USART6 APB2 hattında bulunur
	 * USART2, USART3, UART4,  UART5 APB1 hattında bulunur
	 *
	 * hangi clock hattını kullancağız? bu sorgulama için bu if yazılmıştır.
	 * clock hattına göre Baud Rate Config. yapılacaktır.
	 *
	 */
	if (USART_Handle->Instance == USART1 || USART_Handle->Instance == USART6 )
	{
		PeriphClock=RCC_GetAPB2Clock();

	}
	else
	{
		PeriphClock=RCC_GetAPB1Clock();

	}

	if (USART_Handle->Init.OverSampling == USART_OVERSAMPLE_8 )
	{
		USART_DIV_Value = __USART_DIV_8(PeriphClock,USART_Handle->Init.BaudRate);
		mantissaPart=(USART_DIV_Value /100U );
		fractionPart=(USART_DIV_Value)-(mantissaPart*100U);
		fractionPart= (((fractionPart *8U )+ 50U)/100U) & (0x07U);
	}
	else
	{
		USART_DIV_Value  = __USART_DIV_16(PeriphClock,USART_Handle->Init.BaudRate);
		mantissaPart=(USART_DIV_Value /100U );
		fractionPart=(USART_DIV_Value)-(mantissaPart*100U);
		fractionPart= (((fractionPart *16U )+ 50U)/100U) & (0x0FU);
	}

	tempReg |= (mantissaPart << 4U);
	tempReg |= (fractionPart << 0U);

	USART_Handle->Instance->BRR=tempReg;
}



/*
 * @brief USART_PeriphCMD,ENABLE or DISABLE USART peripheral
 *
 * @param USART_Handle=User config structure
 * @param stateOfUSART=ENABLE or DISABLE
 *
 * @retval void
 *
 * USART'ı yazılımsal olarakaktif etmek için CR1 registerin 13. biti UE(Usart Enable) bitini aktif etmeliyiz.
 */
void USART_PeriphCMD(USART_HandleTypedef_t *USART_Handle,FunctionalState_t stateOfUSART)
{
	if (stateOfUSART== ENABLE)
	{
		USART_Handle->Instance->CR1 |=(0x1U << USART_CR1_UE);
	}
	else
	{
		USART_Handle->Instance->CR1 &=~ (0x1U << USART_CR1_UE);
	}

}


/*
 * @brief USART_TransmitData,Transmit data to the
 *
 * @param USART_Handle=User config structure
 * @param *pData= Address of data to send
 * @param sizeOfData= Length of your data in bytes
 *
 * @retval void
 */
void USART_TransmitData (USART_HandleTypedef_t *USART_Handle,uint8_t *pData, uint16_t sizeOfData )
{
	/*
	 * veri göndermim 4 şekilde yapılabilir
	 * 1) 9 bit data + no parity
	 * 2) 8 bit data + 1 bit parity
	 * 3) 8 bit data + no parity
	 * 4) 7 bit data + 1 bit parity           eger gönderilen veri 1. şekilde ise uint16_t türüne typecast edilir
	 *
	 */

	uint16_t *data16Bits;

	if((USART_Handle->Init.WordLength== USART_WORDLENGTH_9Bits) && (USART_Handle->Init.Parity== USART_PARİTY_NONE))
	{
		data16Bits= (uint16_t*)pData;
	}
	else
	{
		data16Bits=NULL;
	}

	while(sizeOfData)
	{
		while (  ! (USART_Handle->Instance->SR & (0x1U << USART_SR_TX) ) ); // SR Register--> TX(7.bit) 1'se while(0) veri yazma, TX bit 0'sa while(1) veri yaz

		if (data16Bits== NULL) // data16Bits== NULL ise 8 bitlik veri yazacağız
		{
			USART_Handle->Instance->DR= (uint8_t)(*pData & 0xFFU);		//8 bit göndermek için 0xFFU ile and'leme işlemi yaptık
			pData++;
			sizeOfData--;
		}
		else 				   // 16 bitlik veri yazacağız yani 1. şekildeki gönderim olacak 9 bitlik veri gönderimi olacak
		{
			USART_Handle->Instance->DR=(uint16_t)(*data16Bits & 0x1FFU); //9 bit göndermek için 0x1FFU ile and'leme işlemi yaptık
			data16Bits++;
			sizeOfData -=2;

		}

	}

	while (  !(USART_Handle->Instance->SR & (0x1U << USART_SR_TC)) ); //SR Register-->Transmit Complete-TC(6.bit)
																	  //TC Bit=1 ise transmission is complete,TC Bit=0 ise transmission is not complete



}






