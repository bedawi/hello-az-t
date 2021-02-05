#include <Arduino.h>

/***************************************************
 * This is an example program to test the AZ-Touch.
 * It is intended to help new users to quickly test
 * their new hardware and have a template to start
 * their own programs. 
 * 
 * This program only works in Visual Studio Code
 * with PlatformIO installed and configured.
 * 
 * The author or this program are not affiliated 
 * with AZ-Tech.
 * 
 * This is free and unencumbered software released into the public domain.
 * 
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 * 
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * For more information, please refer to <http://unlicense.org/>
 ****************************************************/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Wire.h>

#ifdef ESP8266
#define STMPE_CS 16
#define TFT_CS 0
#define TFT_DC 15
#define SD_CS 2
#endif

#ifdef ESP32
//#define STMPE_CS 32
#define TFT_CS 5
#define TFT_DC 4
#define SD_CS 14
#define TFT_MOSI 23
#define TFT_CLK 18
#define TFT_RST 22
#define TFT_MISO 19
#define TFT_LED 15
#define HAVE_TOUCHPAD
#define TOUCH_CS 14
#define TOUCH_IRQ 2
#endif

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);


void setup()
{
  Serial.begin(115200);
  delay(1000);

  pinMode(TFT_LED, OUTPUT);
  Serial.println("Hello AZ-T started.");

  tft.begin();
  tft.setRotation(3);   // landscape mode  
  tft.fillScreen(ILI9341_BLACK);// clear screen 

  tft.setCursor(70,110);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("Hello AZ-T");
  Serial.println("The Screen should now show \"Hello AZ-T\"");
  
}

void loop(void)
{

}

