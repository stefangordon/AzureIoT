// Copyright (c) Arduino. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
#include <SPI.h>
#include <Adafruit_WINC1500.h>
#include <Adafruit_WINC1500Client.h>
#include <Adafruit_WINC1500MDNS.h>
#include <Adafruit_WINC1500Server.h>
#include <Adafruit_WINC1500SSLClient.h>
#include <Adafruit_WINC1500Udp.h>
#include <time.h>

// #include <WiFi101.h>



#include "simplesample_http.h"

// Define the WINC1500 board connections below.
// If you're following the Adafruit WINC1500 board
// guide you don't need to modify these:
#define WINC_CS   8
#define WINC_IRQ  7
#define WINC_RST  4
#define WINC_EN   2     // or, tie EN to VCC
// The SPI pins of the WINC1500 (SCK, MOSI, MISO) should be
// connected to the hardware SPI port of the Arduino.
// On an Uno or compatible these are SCK = #13, MISO = #12, MOSI = #11.
// On an Arduino Zero use the 6-pin ICSP header, see:
//   https://www.arduino.cc/en/Reference/SPI

// Setup the WINC1500 connection with the pins above and the default hardware SPI.
Adafruit_WINC1500 WiFi(WINC_CS, WINC_IRQ, WINC_RST);

char ssid[] = ""; //  your network SSID (name)
char pass[] = "";    // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;

void setup() {
#ifdef WINC_EN
  pinMode(WINC_EN, OUTPUT);
  digitalWrite(WINC_EN, HIGH);
#endif
  Serial.begin(9600);

  while(!Serial) {
    ;
  }

  double dt = difftime(time(NULL),0);
  int idt = difftime(time(NULL),0);
  Serial.println(dt);
  Serial.println(idt);

  // check for the presence of the shield :
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    if (status != WL_CONNECTED) {
      // wait 10 seconds for connection:
      delay(10000);
    }
  }
  Serial.println("Connected to wifi");
}

void loop() {
  simplesample_http_run();
}

