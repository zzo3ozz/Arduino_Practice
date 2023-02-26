#include "WiFiEsp.h"
#include <TinyGPSPlus.h>
#define BSIZE 200

char SBuf[BSIZE];
char add[BSIZE];

#ifndef HAVE_HWSERIAL1
#endif

char ssid[] = "KT_GiGA_1682";            // your network SSID (name)
char pass[] = "72bd18ic75";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

char server[] = "sc1.swu.ac.kr";

unsigned long lastConnectionTime = 0;         // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10000L; // delay between updates, in milliseconds

// Initialize the Ethernet client object
WiFiEspClient client;
TinyGPSPlus gps;

typedef struct GPSData {
  unsigned int dateUTC;
  double latitude;
  char NSIndicator;
  double longitude;
  char WEIndicator;
  double speedKm;
  double courseDeg;
} GPSData;


void setup()
{
  // initialize serial for debugging
  Serial.begin(115200);
  // initialize serial for ESP module
  Serial1.begin(115200); 
  // initialize serial for GPS module
  Serial2.begin(9600);
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

  GPSData Data;
    if(Serial2.available()) {
      gps.encode(Serial2.read());

      
      Data.dateUTC = gps.date.value();
      Data.latitude = gps.location.lat(); Data.NSIndicator = (gps.location.rawLat().negative ? 'S':'N');
      Data.longitude = gps.location.lng(); Data.WEIndicator = (gps.location.rawLng().negative ? 'E':'W');
      Data.speedKm = gps.speed.kmph(); Data.courseDeg = gps.course.deg();
    }

  // if 10 seconds have passed since your last connection,
  // then connect again and send data
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest(Data);
  }
}

// this method makes a HTTP connection to the server
void httpRequest(GPSData Data)
{
  Serial.println();
  Serial.println(Data.WEIndicator);
    
  // close any connection before send a new request
  // this will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection
  if (client.connect(server, 80)) {
    Serial.println("Connecting...");
    
    sprintf(SBuf, "date=%u&lat=%ld&lng=%ld&speed=%ld&course=%ld&NS=%c&WE=%c",
    Data.dateUTC, Data.latitude, Data.longitude, Data.speedKm, Data.courseDeg, Data.NSIndicator, Data.WEIndicator);
    sprintf(add, "GET /~tjdud0814/final/GPS/DataSend.jsp?%s HTTP/1.1", SBuf);
    // send the HTTP PUT request
    client.println(add);
    client.println(F("Host: sc1.swu.ac.kr"));
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
