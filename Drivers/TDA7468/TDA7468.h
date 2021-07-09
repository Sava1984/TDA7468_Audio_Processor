#ifndef __TDA7468_H
#define __TDA7468_H

#include "main.h"
#define TDA7468_I2C_ADRESS	0x88

#define  	INPUT_SLECT		0x00
#define		INPUT_GAIN		0x01
#define		SURROUND			0x02
#define 	VOLUME_LEFT		0x03
#define		VOLUME_RIGHT	0x04
#define		TREBLE_BASS		0x05
#define		OUTPUT				0x06
#define		BASS_ALC			0x07

#define 	IN1						0x00
#define		IN2						0x01
#define		IN3						0x02
#define		IN4						0x03

#define		MUTE_ON				0x04
#define		MUTE_OFF			0x00

#define		MIC_GAIN_14dB	0x00
#define		MIC_GAIN_10dB	0x08
#define		MIC_GAIN_6dB	0x10
#define		MIC_GAIN_0dB	0x18
#define		MIC_ON				0x00
#define		MIC_OFF				0x20

#define		INPU_GAIN_0db	0
#define		INPU_GAIN_2db	1
#define		INPU_GAIN_4db	2
#define		INPU_GAIN_6db	3
#define		INPU_GAIN_8db	4
#define		INPU_GAIN_10db	5
#define		INPU_GAIN_12b	6
#define		INPU_GAIN_14db	7

#define		SURROUND_ON		1
#define		SURROUND_OFF	0

#define		SUR_GAIN_0dB	0
#define		SUR_GAIN_6dB	2
#define		SUR_GAIN_9dB	4
#define		SUR_GAIN_12dB	6

#define		SURR_MIX_INV100	0
#define		SURR_MIX_INV50	0x08
#define		SURR_MIX_INV25	0x10
#define		SURR_MIX_INV0		0x18
#define		SURR_MIX_NON_INV100		0x20
#define		SURR_MIX_NON_INV75		0x28
#define		SURR_MIX_NON_INV50		0x30
#define		SURR_MIX_MUTE	0x38

#define		SURR_BUFFER_GAIN_0dB	0x40
#define		SURR_BUFFER_GAIN_6dB	0

#define		OUTPUT_MUTE_ON	0
#define		OUTPUT_MUTE_OFF	1

typedef struct 
{
		uint8_t Input;
		uint8_t Mute;
		uint8_t Mic;
		uint8_t	Mic_On;
		

} INPUT_MIC;
typedef struct {
		uint8_t SMode;
		uint8_t SGain;
		uint8_t SMix;
		uint8_t SBuffer_Gain;
		

} SURR;

typedef struct {
		uint8_t ALC_Mode;
		uint8_t ALC_Det;
		uint8_t	ALC_Rel_Curr;
		uint8_t	ALC_Attack;
		uint8_t Thres;
		

} ALC;

typedef struct {
		INPUT_MIC InMic;
		uint8_t Input_Gain;
		SURR		Surr;
		int8_t Left_Volume;
		uint8_t Right_Volume;
		uint8_t Treeble;
		uint8_t Bass;
		uint8_t Output;
		ALC Alc;
		
} TDAREGS;

void TDA7468_Init (I2C_HandleTypeDef hi2c);
TDAREGS TDA7468_Get_Settings (void);
void TDA7468_Master_Volume (uint8_t Vol);
void TDA7468_Bass_Treble (uint8_t Ba, uint8_t Tre);
void TDA7468_Set_Iput_Gain (uint8_t Gain);
void TDA7468_Set_Input (uint8_t Input);
#endif /* __TDA7468_H */


