

#include "TDA7468.h"

I2C_HandleTypeDef i2ch;

uint8_t Surr[2];
TDAREGS Tda;
const uint8_t Bass[16] = {0,1,2,3,4,5,6,7,15,14,13,12,11,10,9,8};
const uint8_t Treble[16] = {0,16,32,48,64,80,96,112,240,224,208,192,176,160,144,128};

void TDA7468_Init (I2C_HandleTypeDef hi2c){
	
	i2ch = hi2c;
	Tda.InMic.Input = IN2;
	Tda.InMic.Mute = MUTE_OFF;
	Tda.InMic.Mic = MIC_GAIN_0dB;
	
	Tda.Input_Gain = INPU_GAIN_14db;
	
	Tda.Surr.SBuffer_Gain = SURR_BUFFER_GAIN_0dB;
	Tda.Surr.SGain = SUR_GAIN_0dB;
	Tda.Surr.SMix = SURR_MIX_INV0;
	Tda.Surr.SMode = SURROUND_OFF;
	
	Tda.Left_Volume = 0;
	Tda.Right_Volume = 0;
	
	Tda.Treeble = 0x0F;
	Tda.Bass = 0x0F;
	
	Tda.Output = OUTPUT_MUTE_OFF;
	
	Tda.Alc.ALC_Mode = 0;
	Surr[0] = SURROUND;
	Surr[1] 	 = Tda.Surr.SMode|Tda.Surr.SMode|Tda.Surr.SMix|Tda.Surr.SBuffer_Gain;
	HAL_I2C_Master_Transmit(&i2ch,TDA7468_I2C_ADRESS,Surr,2,100);
	Surr[0] = INPUT_SLECT;
	Surr[1] 	 = Tda.InMic.Input|Tda.InMic.Mute|Tda.InMic.Mic|Tda.InMic.Mic_On;
	HAL_I2C_Master_Transmit(&i2ch,TDA7468_I2C_ADRESS,Surr,2,100);
	Surr[0] = VOLUME_LEFT;
	Surr[1] 	 = 0x0F;
	HAL_I2C_Master_Transmit(&i2ch,TDA7468_I2C_ADRESS,Surr,2,100);
	Surr[0] = VOLUME_RIGHT;
	Surr[1] 	 = 0x0F;
	HAL_I2C_Master_Transmit(&i2ch,TDA7468_I2C_ADRESS,Surr,2,100);
	Surr[0] = OUTPUT;
	Surr[1] 	 = Tda.Output;
	HAL_I2C_Master_Transmit(&i2ch,TDA7468_I2C_ADRESS,Surr,2,100);
	 TDA7468_Bass_Treble (  Tda.Treeble, Tda.Bass);

}
TDAREGS TDA7468_Get_Settings (void){

return Tda;
}
	
void TDA7468_Master_Volume (uint8_t Vol){

	Surr[0] = VOLUME_LEFT;
	Surr[1] 	 = Vol;
	HAL_I2C_Master_Transmit(&i2ch,TDA7468_I2C_ADRESS,Surr,2,100);
	Surr[0] = VOLUME_RIGHT;
	Surr[1] 	 = Vol;
	HAL_I2C_Master_Transmit(&i2ch,TDA7468_I2C_ADRESS,Surr,2,100);
	Tda.Left_Volume = Vol;
	Tda.Right_Volume = Vol;

}

void TDA7468_Bass_Treble (uint8_t Ba, uint8_t Tre){
	uint8_t Buf [2];
	
	Buf[0]= TREBLE_BASS;
	Buf[1] = Treble[Tre]|Bass[Ba];
	HAL_I2C_Master_Transmit(&i2ch,TDA7468_I2C_ADRESS,Buf,2,100);
	Tda.Bass = Ba;
	Tda.Treeble = Tre;
}

void TDA7468_Set_Iput_Gain (uint8_t Gain){
	uint8_t Buf [2];
	if (Gain>7) Gain = 7;
	Buf[0] = INPUT_GAIN;
	Buf[1] = Gain;
	HAL_I2C_Master_Transmit(&i2ch,TDA7468_I2C_ADRESS,Buf,2,100);
	Tda.Input_Gain = Gain;
}
void TDA7468_Set_Input (uint8_t Input){
	uint8_t Buf [2];
	Buf[0]=INPUT_SLECT;
	if (Input>3){
	}
	else {
		Tda.InMic.Input = Input;
	}
	Buf[0] = INPUT_SLECT;
	Buf[1] 	 = Tda.InMic.Input|Tda.InMic.Mute|Tda.InMic.Mic|Tda.InMic.Mic_On;
	HAL_I2C_Master_Transmit(&i2ch,TDA7468_I2C_ADRESS,Buf,2,100);

}


