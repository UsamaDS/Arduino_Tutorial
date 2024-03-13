/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use Arduino WiFi shield
  to connect your project to Blynk.

  Please update your shield firmware:
    https://www.arduino.cc/en/Hacking/WiFiShieldFirmwareUpgrading

  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPLoSqj_vws"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "f_s3kQXN_Hkp9s6wcqtZc6U9NhUnfjk9"


#include <SPI.h>
#include <WiFiS3.h>
#include <BlynkSimpleWifi.h>
#include <TimeLib.h>
#include <WidgetRTC.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Internet";
char pass[] = "28511666";

BlynkTimer timer;
WidgetRTC rtc;

void clockDisplay() {
  // You can call hour(), minute(), ... at any time
  // Please see Time library examples for details

  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  String currentDate = String(day()) + " " + month() + " " + year();

  // Send time to the App
  Blynk.virtualWrite(V1, currentTime);
  // Send date to the App
  Blynk.virtualWrite(V2, currentDate);
}

BLYNK_CONNECTED() {
  // Synchronize time on connection
  rtc.begin();
}
void setup() {
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  setSyncInterval(10 * 60); // sync interval in seconds (10 minutes)

  timer.setInterval(1000L, clockDisplay);
}

void loop() {
  Blynk.run();
  timer.run();
}
