#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI(); // Invoke custom library
#include <ESP_QRcode.h>
ESP_QRcode tftqrcode(&tft);
String qr = "abcdefghijkmlnopqrstuvwxyz";

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Starting...");

  tft.init();
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK);
    tft.drawString("Connecting", 60,60 );
//  tftqrcode.qrcode(, 3, 3,122,11);
  //  tft.setCursor(35, 45);
  //  tft.println(F("Automata"));
  
}

void loop() {
  // put your main code here, to run repeatedly:


}
