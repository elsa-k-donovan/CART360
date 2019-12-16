
//#include <Particle.h>
#include "simple-OSC.h"

IPAddress outIp(192, 168, 0, 100); //your computer IP
unsigned int outPort = 7000;  //computer incoming port

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

unsigned int localPort = 8888;
IPAddress ipAddress;
int port;
UDP udp;


void setup()
{
    // Serial.begin(115200);
    // Serial.begin(57600);
    // while(!Serial);
    // WiFi.connect();

   // udp.begin(0); //necessary even for sending only.

    // while (!WiFi.ready())
    // {
    //     delay(500);
    //     Serial.print(".");
    // }
  

    /*COPIED*/
    // Put initialization like pinMode and begin functions here.
    Serial.begin(57600);
    while(!Serial);
    WiFi.connect();
    Serial.println("WiFi connected");
    //pinMode(pResistor, INPUT);
    pinMode(7, OUTPUT);

//wifi function
    while(!WiFi.ready());
    Serial.println("Setup");
    udp.begin(localPort);

    Serial.println(WiFi.hostname());
    Serial.println(WiFi.localIP());
}

void loop()
{
    int valA0 = analogRead(A0);
    int valA1 = analogRead(A1);
    int valA2 = analogRead(A2);
    int valA3 = analogRead(A3);
    int valA4 = analogRead(A4);

    //int testVal = 255;
    // Serial.println(WiFi.localIP());

    //SEND
    //OSCMessage outMessage("/pong");
    OSCMessage outMessage("/pong");
    //outMessage.addString("test");
    //outMessage.addFloat(-3.14);
    outMessage.addInt(valA0);
    outMessage.addInt(valA1);
    outMessage.addInt(valA2);
    outMessage.addInt(valA3);
    outMessage.addInt(valA4);

    outMessage.send(udp,outIp,outPort);

    Serial.println(" ");

    Serial.print("val A0: ");
    Serial.println(valA0);

    Serial.println(" ");

    Serial.print("val A1: ");
    Serial.println(valA1);

    Serial.println(" ");

    Serial.print("val A2: ");
    Serial.println(valA2);

    Serial.println(" ");

    Serial.print("val A3: ");
    Serial.println(valA3);

    Serial.println(" ");

    Serial.print("val A4: ");
    Serial.println(valA4);


   digitalWrite(7, HIGH);
   delay(100);
   digitalWrite(7, LOW);
   delay(75);
}