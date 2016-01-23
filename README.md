# AzureIoT - Azure IoT library for Arduino

This library is a port of the [Microsoft Azure IoT device SDK for C](https://github.com/Azure/azure-iot-sdks/blob/master/c/readme.md) to Arduino. It allows you to use your Arduino/Genuino with the [Azure IoT Hub](https://azure.microsoft.com/en-us/services/iot-hub/).

The following boards are supported
- Arduino/Genuino [MKR1000](https://www.arduino.cc/en/Main/ArduinoMKR1000) 
- [Zero](https://www.arduino.cc/en/Main/ArduinoBoardZero) and [WiFi Shield 101](https://www.arduino.cc/en/Main/ArduinoWiFiShield101) 
- ESP8266 based boards

[![Microsoft Azure Certified][Microsoft-Azure-Certified-Badge]][azure-certifiedforiot]

## Getting started

See the [Microsoft Azure IoT device SDK for C - Arduino WiFi Shield 101 and MKR1000 Setup Guide](https://github.com/Azure/azure-iot-sdks/blob/master/c/doc/run_sample_on_arduino_wifi101.md).

## Working with ESP8266

- Use Arduino IDE 1.6.8 or later (or current nightly if not yet released).

- Install esp8266 board support following instructions under "Using git version" at [esp8266/arduino](https://github.com/esp8266/arduino).

- Install this library from source

```
cd C:\Program Files (x86)\Arduino\libraries
git clone <repo url for this source>
```
- Open sample provided in library directory

## License

See [LICENSE](LICENSE) file.

[azure-certifiedforiot]:  http://azure.com/certifiedforiot 
[Microsoft-Azure-Certified-Badge]: images/Microsoft-Azure-Certified-150x150.png (Microsoft Azure Certified)
