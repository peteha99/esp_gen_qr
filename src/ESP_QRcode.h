#include <Adafruit_GFX.h>
#include <TFT_eSPI.h>

class ESP_QRcode
{
	private:
		TFT_eSPI *LCD;
		//void render(int x, int y, int color);

	public:
		ESP_QRcode(TFT_eSPI *TFTLCD);
		
		void qrcode(const char *string, uint16_t x, uint16_t y, uint8_t width = 220, uint8_t version = 6);
        void qrcode(const String &string, uint16_t x, uint16_t y, uint8_t width = 220, uint8_t version = 6);
};