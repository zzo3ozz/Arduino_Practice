/*
 WiFiEsp example: WebClientRepeating

 This sketch connects to a web server and makes an HTTP request
 using an Arduino ESP8266 module.
 It repeats the HTTP call each 10 seconds.

 For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html
*/

#include "WiFiEsp.h"

// Emulate Serial1 on pins 6/7 if not present
#ifndef HAVE_HWSERIAL1
//#include "SoftwareSerial.h"
//SoftwareSerial Serial1(19, 18); // RX, TX
#endif

char ssid[] = "KT_GiGA_1682";            // your network SSID (name)
char pass[] = "72bd18ic75";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

char server[] = "sc1.swu.ac.kr";

unsigned long lastConnectionTime = 0;         // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10000L; // delay between updates, in milliseconds

// Initialize the Ethernet client object
WiFiEspClient client;

const byte buttonPin = 2;
void setup()
{
  // initialize serial for debugging
  //BUTTON PIN
  pinMode (buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
  // initialize serial for ESP module
  Serial1.begin(115200);
  // initialize ESP module
  WiFi.init(&Serial1);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");
  
  printWifiStatus();
}

void loop()
{
  // if there's incoming data from the net connection send it out the serial port
  // this is for debugging purposes only
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if 10 seconds have passed since your last connection,
  // then connect again and send data
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }
}

// this method makes a HTTP connection to the server
void httpRequest()
{
  int buttonState = 0;
  Serial.println();  
  // close any connection before send a new request
  //read the state of the pushbutoon value:
  buttonState = digitalRead(buttonPin);
  // this will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection
  if (client.connect(server, 80)) {
    Serial.println("Connecting...");
    
    // send the HTTP PUT request
//    client.println(F("GET /~tjdud0814/reqGetData.jsp?GPSLAT=3736.17296&GPSLONG=12702.14551&SPEED=12.304&TEMP=18&MOISTURE=60 HTTP/1.1"));
    if(buttonState == 0) client.println("GET /~tjdud0814/final/Button/DataSend.jsp?BUTTON=on HTTP/1.1");
    else client.println("GET /~tjdud0814/final/Button/DataSend.jsp?BUTTON=off HTTP/1.1");
    client.println(F("Host:sc1.swu.ac.kr"));
    client.println("Connection: close");
    client.println();
   
    // note the time that the connection was made
    lastConnectionTime = millis();
  }
  else {
    // if you couldn't make a connection
    Serial.println("Connection failed");
  }
}


void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}