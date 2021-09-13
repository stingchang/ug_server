#include <Arduino.h>

#define SDA_PIN D2//0
#define SCL_PIN D1//

/* These 'DATA_INDEX_' variable list mas to match MEGA */
// Convert 2 bytes to 4 digits number, ex: byte1 = '/00000011/, byte2 = '/00100000/=> 0000001100100000 =>2^10 + 2^9 + 2^6 = 1600
#define DATA_INDEX_LIGHT1 0        /* eg: 1430 = turn on at 14:30 */
#define DATA_INDEX_LIGHT1_ON_TIME 1        /* eg: 1430 = turn on at 14:30 */
#define DATA_INDEX_LIGHT1_OFF_TIME 2       /* eg: 1030 = turn off at 10:30 */
#define DATA_INDEX_LIGHT2 3        /* eg: 1430 = turn on at 14:30 */
#define DATA_INDEX_LIGHT2_ON_TIME 4
#define DATA_INDEX_LIGHT2_OFF_TIME 5
#define DATA_INDEX_ROOM_AUTO 6      /* 00 = off, 01 = on */

#define DATA_INDEX_CO2 8              /* ex: 1500 = 1500 PPM, transffered in 15.00 */
#define DATA_INDEX_CO2_AUTO_HIGH 10    /* ex: 1500 = 1500 PPM */
#define DATA_INDEX_CO2_AUTO_LOW 11     /* ex: 500 = 500 PPM */
#define DATA_INDEX_HUMIDITY 12        /* ex: 4510 = 45.1% */

#define DATA_INDEX_HUMIDITY_AUTO_HIGH 14
#define DATA_INDEX_HUMIDITY_AUTO_LOW 15
#define DATA_INDEX_TEMPERATUREC 16    /* ex: 2570 = 25.7'c */
#define DATA_INDEX_TEMPERATUREF 17    /* ex: 1050 = 105.0'f */

#define DATA_INDEX_DWC1_TDS 18         /* ex: 0656 = 6.56   */
#define DATA_INDEX_DWC1_TEMPERATURE_AUTO_STATUS 19
#define DATA_INDEX_DWC1_TEMPERATURE_AUTO_HIGH 20
#define DATA_INDEX_DWC1_TEMPERATURE_AUTO_LOW 21
#define DATA_INDEX_DWC1_TEMPERATURE 22
#define DATA_INDEX_DWC1_LEVEL 23  /* 00 = low, 01 = high */
#define DATA_INDEX_DWC1_PH 24  

#define DATA_INDEX_DWC2_TDS 25
#define DATA_INDEX_DWC2_TEMPERATURE_AUTO_STATUS 26
#define DATA_INDEX_DWC2_TEMPERATURE_AUTO_HIGH 27
#define DATA_INDEX_DWC2_TEMPERATURE_AUTO_LOW 28
#define DATA_INDEX_DWC2_TEMPERATURE 29
#define DATA_INDEX_DWC2_LEVEL 30
#define DATA_INDEX_DWC2_PH 31

// array size data
//#define DATA_INDEX_DWC1_TEMPERATURE_24HOUR 33 // 33-56 , use 48 bytes
//#define DATA_INDEX_DWC1_TEMPERATURE_7DAY 57   // 57-63 , use 14 bytes
//#define DATA_INDEX_DWC1_PPM_24HOUR 64 // 64-87
//#define DATA_INDEX_DWC1_PPM_7DAY 88   // 88-94
//
//#define DATA_INDEX_DWC2_TEMPERATURE_24HOUR 89 // 89-112 , use 48 bytes
//#define DATA_INDEX_DWC2_TEMPERATURE_7DAY 113   // 113-126 , use 14 bytes
//#define DATA_INDEX_DWC2_PPM_24HOUR 127 // 127-151 , use 48 bytes
//#define DATA_INDEX_DWC2_PPM_7DAY 152   // 152-165 , use 14 bytes

// data size 165 bytes, so we need 6 32-byte arrays to cover all
