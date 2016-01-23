// Please use an Arduino IDE 1.6.8 (once released) or an hourly build from 1/21/2016 or later from
// https://www.arduino.cc/en/Main/Software
// Prior builds may experience pre-processor function prototype failures.

#include <ESP8266WiFi.h>
#include <time.h>
#include "simplesample_http.h"

char ssid[] = "ssid"; //  your network SSID (name)
char pass[] = "password";    // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;

void setup() {
	initSerial();
	initWifi();
	initTime();   
}

void loop() {
	// Run the SimpleSample from the Azure IoT Hub SDK
	// You must set the connection string in simplesample_http.c
  	simplesample_http_run();
}

void initSerial() {
	// Start serial and initialize stdout
    Serial.begin(115200);
	Serial.setDebugOutput(true);
}

void initWifi() {
	// Attempt to connect to Wifi network:
	Serial.print("Attempting to connect to SSID: ");
	Serial.println(ssid);

	// Connect to WPA/WPA2 network. Change this line if using open or WEP network:
	status = WiFi.begin(ssid, pass);

	while (WiFi.status() != WL_CONNECTED) {
	    delay(500);
	    Serial.print(".");
	}
  
  	Serial.println("Connected to wifi");
}

void initTime() {
	// Initialize time via NTP server
  	// The delays increase the reliability of this
  	// and help ensure time is set before we move on.
  	// Better solution coming soon.
	delay(2000);
	// Configure NTP servers
  	// First parameter is time zone offset in seconds.  We'll use 0 for GMT.
  	configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  	// Make a time request
	time(NULL);
  	delay(3000);
}