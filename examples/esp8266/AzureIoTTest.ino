// Copyright (c) Arduino. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
#include <AzureIoT.h>
#include <ESP8266WiFi.h>
#include "simplesample_http.h"

#include <debug.h>
#include <time.h>

char ssid[] = "ssid"; //  your network SSID (name)
char pass[] = "password";    // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;

void setup() {
    Serial.begin(115200);
	Serial.setDebugOutput(true);
	
    // attempt to connect to Wifi network:
	Serial.print("Attempting to connect to SSID: ");
	Serial.println(ssid);
	// Connect to WPA/WPA2 network. Change this line if using open or WEP network:
	status = WiFi.begin(ssid, pass);

	while (WiFi.status() != WL_CONNECTED) {
	    delay(500);
	    Serial.print(".");
	}
  
  	Serial.println("Connected to wifi");

  	// let wifi stabilize (dns/dhcp?)
	delay(2000);

  	// 0 for GMT.  -8 * 3600 for PST.
  	configTime(0, 0, "pool.ntp.org", "time.nist.gov");
	time(NULL);
  	delay(3000);
}

void loop() {
  simplesample_http_run();
}

