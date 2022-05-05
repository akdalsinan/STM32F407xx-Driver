
#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stm32f407xx.h"

/*
 * @def_group SPI baudrate
 */
#define SPI_BAUDRATE_DIV2			((uint32_t) (0x00000000) )
#define SPI_BAUDRATE_DIV4			((uint32_t) (0x00000008) )
#define SPI_BAUDRATE_DIV8			((uint32_t) (0x00000010) )
#define SPI_BAUDRATE_DIV16			((uint32_t) (0x00000018) )
#define SPI_BAUDRATE_DIV32			((uint32_t) (0x00000020) )
#define SPI_BAUDRATE_DIV64			((uint32_t) (0x00000028) )
#define SPI_BAUDRATE_DIV128			((uint32_t) (0x00000030) )
#define SPI_BAUDRATE_DIV256			((uint32_t) (0x00000038) )

/*
 * @def_group SPI CPHA values
 */
#define SPI_CPHA_FIRST			 		((uint32_t) (0x00000000) )
#define SPI_CPHA_SECOND			 		((uint32_t) (0x00000001) )

/*
 * @def_group SPI CPOL values
 */
#define SPI_CPOL_LOW			 		((uint32_t) (0x00000000) )
#define SPI_CPOL_HIGH			 		((uint32_t) (0x00000002) )

/*
 * @def_group SPI DFF values
 */
#define SPI_DFF_8BIT					((uint32_t) (0x00000000) )
#define SPI_DFF_16BIT					((uint32_t) (0x00000800) ) //0000 0000 0000 0000 0000 1000 0000 0000

/*
 * @def_group SPI MODE values
 */
#define SPI_MODE_MASTER					((uint32_t) (0x00000004) )
#define SPI_MODE_SLAVE					((uint32_t) (0x00000000) )

/*
 * @def_group SPI FF values
 */
#define SPI_FRAMEFORMAT_MSB				((uint32_t) (0x00000000) )
#define SPI_FRAMEFORMAT_LSB				((uint32_t) (0x00000080) )

/*
 * @def_group SPI BusConfig Values
 */
#define SPI_BUS_Fullduplex				((uint32_t) (0x00000000))
#define SPI_BUS_ReceiveOnly				((uint32_t) (0x00000400))
#define SPI_BUS_HalfDuplex_T			((uint32_t) (0x0000C000))
#define SPI_BUS_HalfDuplex_R			((uint32_t) (0x00008000))

/*
 * @def_group SPI SSM Values
 */
#define SPI_SSM_DISABLE					((uint32_t) (0x00000000))
#define SPI_SSM_ENABLE					((uint32_t) (0x00000300)) //SSM bit(CR 9. bit)=1 and SSR bit(CR 8. bit)=1
																  //0000 0000 0000 0000 0000 0011 0000 0000=0x00000300
typedef struct //user! verilecek struct yapısı
{
	uint32_t Mode;				//@def_group SPI MODE values(master or slave)
	uint32_t CPHA;				//@def_group SPI CPHA values
	uint32_t CPOL;				//@def_group SPI CPOL values
	uint32_t Baudrate;			//@def_group SPI baudrate
	uint32_t SSM_Cmd;			//@def_group SPI SSM Values
	uint32_t DFF_Format;		//@def_group SPI DFF values
	uint32_t BusConfig;			//@def_group SPI BusConfig Values
	uint32_t FrameFormat;       //@def_group SPI FF values
}SPI_InitTypedef_t;


typedef struct
{
	SPI_Typedef_t *Instance;
	SPI_InitTypedef_t Init;

}SPI_HandleTypedef_t;


void SPI_Init(SPI_HandleTypedef_t *SPI_Handle);									  // C1 register--> CPHA bit(0), CPOL bit(1), MODE-MSTR bit(2),
																				  // Baud Rate-BR bit(3-4-5), SSI bit(8),
																				  // SSM bit(9), RXONLY-bus config. bit(10), DFF bit(11)

void SPI_PeriphCmd(SPI_HandleTypedef_t *SPI_Handle,FunctionalState_t stateOfSPI); // CR1 register--> SPE bit(6. bit) DISABLE or ENABLE

void SPI_TransmitData(SPI_HandleTypedef_t *SPI_Handle,uint8_t *pData, uint16_t sizeOfData);


#endif /* INC_SPI_H_ */
