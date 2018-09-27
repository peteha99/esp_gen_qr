#include <Arduino.h>
#include "ESP_QRcode.h"
#include "qrcode.h"

#include <string.h> //for strlen(mystring)
#include <stdio.h> //for gets(mystring)

// #define piexl_size 3
//#define ST7735_BLACK       0x0000      /*   0,   0,   0 */
//#define ST7735_WHITE       0xFFFF      /* 255, 255, 255 */

ESP_QRcode::ESP_QRcode(TFT_eSPI *TFTLCD)
{
	this->LCD = TFTLCD;
}



void ESP_QRcode::qrcode(const char *string, uint16_t x, uint16_t y, uint8_t width, uint8_t version) {
  
  // Create the QR code
  QRCode qrcode;
  int16_t eccsize;
  int16_t size = strlen(string); //string.length();
  if (size > 251 ){
    eccsize = 1;
  }
  else{
    eccsize = 0;
  }
  

  uint8_t qrcodeData[qrcode_getBufferSize(version)];
  qrcode_initText(&qrcode, qrcodeData, version, eccsize, string);
  
  // Top quiet zone
  uint8_t thickness = width / qrcode.size;
  uint16_t lineLength = qrcode.size * thickness;
  uint8_t xOffset = x + (width-lineLength)/2;
  uint8_t yOffset = y + (width-lineLength)/2;
  LCD->fillRect(x, y, width, width, TFT_WHITE);

  for (uint8_t y = 0; y < qrcode.size; y++) {
    for (uint8_t x = 0; x < qrcode.size; x++) {
      uint8_t q = qrcode_getModule(&qrcode, x, y);
      if (q) LCD->fillRect(x * thickness + xOffset, y * thickness + yOffset, thickness, thickness, TFT_BLACK);
    }
  }
}

void ESP_QRcode::qrcode(const String &string, uint16_t x, uint16_t y, uint8_t width, uint8_t version) {
  int16_t len = string.length() + 2;
  char buffer[len];
  string.toCharArray(buffer, len);
  qrcode(buffer, x, y, width, version);
}