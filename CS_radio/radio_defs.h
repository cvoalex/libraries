#pragma once




#if defined(ARDUINO_PORTENTA_H7_M4) || defined(ARDUINO_PORTENTA_H7_M7)
    #define PORTENTA_E22_400M30S
    //#define PORTENTA_E22_900M30S

    #define R1_TXEN PG_3
    #define R1_RXEN PG_10
    #define R1_NSS PC_13
    #define R1_DIO1 PE_3
    #define R1_NRST PC_15
    #define R1_BUSY PD_4

    #define R2_TXEN PA_6
    #define R2_RXEN PA_4
    #define R2_NSS PI_4
    #define R2_DIO1 PI_5
    #define R2_NRST PH_14
    #define R2_BUSY PH_10

#else
    #define TTGO1278


    #define TTGO_SCK        5
    #define TTGO_MISO       19
    #define TTGO_MOSI       27
    #define TTGO_SS         18
    #define TTGO_DIO0       26
    #define TTGO_DIO1       33
    #define TTGO_DIO2       32
    #define TTGO_RST        23


    //Radio1MHz
    #define R1_NSS 25
    #define R1_DIO1 26
    #define R1_NRST 27
    #define R1_BUSY 28

    //Radio2MHz
    #define R2_NSS 29
    #define R2_DIO1 30
    #define R2_NRST 31
    #define R2_BUSY 32

    //RadioGHz
    #define R3_NSS 33
    #define R3_DIO1 34
    #define R3_NRST 35
    #define R3_BUSY 36


#endif





#define RADIOTXDELAY  20 // 1000
#define RADIOWAITFORACK 7000
#define RADIOWAITFORCOMPLETE 7000
#define SLEEPTIME 15*1000    //1 Orbit  90*60*1000 Min
#define MODEMCHANGEMAXTIME 2*24*60*60*1000

#define R_STATE "R_STATE"
#define R2_STATE "R2_STATE"

#define R_INSTATE "R_INSTATE"
#define R_LASTTX "R_LASTTX"
#define R_LASTRX "R_LASTRX"
#define R_TM "R_TM"


#define R2_INSTATE "R2_INSTATE"
#define R2_LASTTX "R2_LASTTX"
#define R2_LASTRX "R2_LASTRX"
#define R2_TM "R2_TM"





#define PING_INTERVAL             2       // seconds, how much time to wait between PINGs sent from this node

#if defined(TTGO1262)    
    #define LORA_RADIO_FREQUENCY        900.0   
    #define LORA_RADIO2_FREQUENCY       900.0   
    
#endif
#if defined(TTGO1268)  || defined(TTGO1278) ||defined(ARDUINO_PORTENTA_H7_M4) || defined(ARDUINO_PORTENTA_H7_M7)    
    #define LORA_RADIO_FREQUENCY        443.0   //FREQUENCY_900M30S
    #define LORA_RADIO2_FREQUENCY       443.0   //FREQUENCY_900M30S    
#endif


// Keep TIME OF FLIGHT below 1.5-2 Seconds!!!!

//813 bps   
#define LORA_BANDWIDTH                 250  //125.0   // kHz dual-sideband  //Large packets would casue errors!!@#!@#! at 125
#define LORA_SPREADING_FACTOR          11       // 2^9 chirps  10
#define LORA_CODING_RATE               8       // 4/7 coding
#define LORA_TXDELAY                   20  //1000

//5600
#define LORA_BANDWIDTHMEGA                 500  //125.0   // kHz dual-sideband
#define LORA_SPREADING_FACTORMEGA          8       // 2^9 chirps
#define LORA_CODING_RATEMEGA               7       // 4/7 coding
#define LORA_TXDELAYMEGA                  20  //  500

//3200
#define LORA_BANDWIDTHULTRA                 500  //125.0   // kHz dual-sideband
#define LORA_SPREADING_FACTORULTRA          9       // 2^9 chirps
#define LORA_CODING_RATEULTRA               7       // 4/7 coding
#define LORA_TXDELAYULTRA                 20  //   400

//1600
#define LORA_BANDWIDTHHIGH                 250  //125.0   // kHz dual-sideband
#define LORA_SPREADING_FACTORHIGH          9       // 2^9 chirps
#define LORA_CODING_RATEHIGH               7       // 4/7 coding
#define LORA_TXDELAYHIGH                   600

//888 bps
#define LORA_BANDWIDTHMEDIUM                 250  //125.0   // kHz dual-sideband
#define LORA_SPREADING_FACTORMEDIUM          10       // 2^9 chirps
#define LORA_CODING_RATEMEDIUM               7       // 4/7 coding
#define LORA_TXDELAYMEDIUM                 20  //   800

//223 bps
#define LORA_BANDWIDTHLOW                 125  //125.0   // kHz dual-sideband
#define LORA_SPREADING_FACTORLOW          11       // 2^9 chirps
#define LORA_CODING_RATELOW               8       // 4/7 coding
#define LORA_TXDELAYLOW                 20  //   1500

#define LORA_SYNC_WORD                 0x12    // private network
#define LORA_OUTPUT_POWER              12      // +14 dBm
#define LORA_OUTPUT_POWER_TTGO         16
#define LORA_CURRENT_LIMIT             140.0    // mA  was 60,  120
#define LORA_PREAMBLE_LENGTH           8       // symbols
#define LORA_TCXO_VOLTAGE              1.6     // V


/* FossaSat Rates
#define LORA_CARRIER_FREQUENCY                          436.7       //< MHz 
#define LORA_BANDWIDTH                                  125.0       //< kHz dual sideband 
#define LORA_SPREADING_FACTOR                           11
#define LORA_SPREADING_FACTOR_ALT                       10
#define LORA_CODING_RATE                                8           //< 4/8, Extended Hamming 
#define LORA_OUTPUT_POWER                               20          //< dBm 
#define LORA_PREAMBLE_LENGTH                            8           //< symbols 
#define LORA_CURRENT_LIMIT                              140.0       //< mA 
*/


/*
HIGHBW, MEDIUMBW, LOWBW, NORMALBW

https://medium.com/home-wireless/testing-lora-radios-with-the-limesdr-mini-part-2-37fa481217ff
https://www.rfwireless-world.com/calculators/LoRa-Data-Rate-Calculator.html

Minimize bandwidth and maximize spreading factor to boost link budget. 
Maximize coding rate to boost reliability.    

Data Rate = Bandwidth / (2 ** SF)

Spreading Factor - LoRa converts symbols (binary data) to chirp signals that span the frequency range. The chirp time (=symbol time) is roughly proportional to 2**spreading factor.
    Each step up in spreading factor doubles the time on air to transmit a symbol.
    Each unit increase in SF correlates to about 2.5dB extra link budget.


Bandwidth - Higher bandwidth has higher data rates and is more power-efficient, but has more congestion and less range.
    Each doubling of the bandwidth correlates to almost 3dB less link budget   

Coding Rate - Increasing the coding rate increases reliability while decreasing data rate.     

SX1272
int16_t 	setBandwidth (float bw)
 	Sets LoRa link bandwidth. Allowed values are 125, 250 and 500 kHz. Only available in LoRa mode. More...
 
int16_t 	setSpreadingFactor (uint8_t sf)
 	Sets LoRa link spreading factor. Allowed values range from 6 to 12. Only available in LoRa mode. More...
 
int16_t 	setCodingRate (uint8_t cr)
 	Sets LoRa link coding rate denominator. Allowed values range from 5 to 8. Only available in LoRa mode. More...
 
int16_t 	setOutputPower (int8_t power, bool useRfo=false)
 	Sets transmission output power. Allowed values range from -1 to 14 dBm (RFO pin) or +2 to +20 dBm (PA_BOOST pin). More...


SX126X
int16_t 	setBandwidth (float bw)
 	Sets LoRa bandwidth. Allowed values are 7.8, 10.4, 15.6, 20.8, 31.25, 41.7, 62.5, 125.0, 250.0 and 500.0 kHz. More...
 
int16_t 	setSpreadingFactor (uint8_t sf)
 	Sets LoRa spreading factor. Allowed values range from 5 to 12. More...
 
int16_t 	setCodingRate (uint8_t cr)
 	Sets LoRa coding rate denominator. Allowed values range from 5 to 8. More...     

*/








#define ESP32_GATEWAY_NSS_BUILTIN               16
#define ESP32_GATEWAY_DIO0_BUILTIN              26
#define ESP32_GATEWAY_NRST_BUILTIN             -1// RADIOLIB_PIN_UNUSED
#define ESP32_GATEWAY_DIO1_BUILTIN              33




#define _MEGABW "MEGABW"
#define _ULTRABW "ULTRABW"
#define _HIGHBW "HIGHBW"
#define _MEDIUMBW "MEDIUMBW"
#define _LOWBW "LOWBW"
#define _NORMALBW "NORMALBW"
    

