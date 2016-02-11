// Copyright (c) Arduino. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
//
// #include <Adafruit_WINC1500.h>
// #include <Adafruit_WINC1500Client.h>
// #include <Adafruit_WINC1500MDNS.h>
// #include <Adafruit_WINC1500Server.h>
#include <Adafruit_WINC1500SSLClient.h>
// #include <Adafruit_WINC1500Udp.h>

#ifndef HTTPSCLIENT_H
#define HTTPSCLIENT_H

#define HTTPS_PORT          443

class HTTPSClient : public Adafruit_WINC1500SSLClient
{
    public:
        HTTPSClient();
        int begin(const char* host, int port = HTTPS_PORT);
        int sendRequest(const char* method, const char* path);
        int sendHeader(const String& header);
        int sendBody(const unsigned char *content, int length);
        int readStatus();
        int readHeader(String& name, String& value);
        size_t contentLength();
        int readBody(unsigned char *content, int length);
        void end();

    private:
        String readLine();

        size_t _contentLength;
};

#endif
