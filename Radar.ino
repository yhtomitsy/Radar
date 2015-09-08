#include <WiShield.h>
#include <WiServer.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define WIRELESS_MODE_INFRA  1
#define WIRELESS_MODE_ADHOC 2

SoftwareSerial teraRanger(10, 11); // set software serial port for teraRanger
Servo panServo; // declare servo

int pos = 0; // position of servo
int sensorReading = 0; // reading from teraranger

WIFI_SETUP();

// IP Address for hosting server 
uint8 ip[] = {185,27,134,202};

// sends received data to online server
GETrequest sendData(ip, 80, "www.kisese.byethost7.com", "/kura/flags_process.php?flag=a"+ String(sensorReading)+ "," + String(pos));

void setup() {
  Serial.begin(57600); // set baud rate
  WiServer.init(NULL); // Initialize WiServer (we'll pass NULL for the page serving function since we don't need to serve web pages)
  teraRanger.begin(115200); // set baud rate of software serial port
  panServo.attach(9);  // attach servo to pin 9 
  // Have the processData function in the wifi setup tab called when data is returned by the server
  sendData.setReturnFunc(printData);
}

void loop() {
  panServo.write(pos);
  while(!teraRanger.available()){
    delay(1);
  }
  if (teraRanger.available()){
    String input = teraRanger.readStringUntil('\n');

    sensorReading = input.toInt();
    String reverse = String(sensorReading);

    input.trim();
    reverse.trim();

    if (input.equals(reverse)) {
      Serial.print(input);
    }
  }
  sendData.submit(); // submits the servo position and sensor reading to the online server
  delay(50);
}
