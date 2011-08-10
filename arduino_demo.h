#define CIK "PUTYOURCIKHERE"           // <-- FILL IN YOUR DEVICE CIK HERE (https://portals.exosite.com -> Add Device)!

byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x25, 0xF1};
byte ip[] = { 192,168,10,201 };        // <-- FILL IN YOUR DEVICE IP ADDRESS HERE!
byte gateway[] = { 192,168,10,1 };     // <-- FILL IN YOUR NETWORK GATEWAY IP ADDRESS HERE!	
byte subnet[] = { 255, 255, 255, 0 };  // <-- FILL IN YOUR NETWORK SUBNET MASK HERE!
byte server[] = { 173, 255, 209, 28 }; // m2.exosite.com
Client client(server, 80); // Port 80 is default for HTTP

void sendToExosite(int res, int value) {  
  String myDataString = ""; //allocate for actual data sent
  static char enetInitDone = 0;
  
  if (!enetInitDone) {
    Ethernet.begin(mac, ip);
    delay(500);  
    enetInitDone = 1;   
  }
  
  if (client.connect()) 
  {
    if (client.connected())
    {
      myDataString += res;
      myDataString += "=";  //put into resource
      myDataString += value; //just send the value 
   
      // Send request using Exosite basic HTTP API
      client.println("POST /api:v1/stack/alias HTTP/1.1");
      client.println("Host: m2.exosite.com");
      client.print("X-Exosite-CIK: "); 
      client.println(CIK);
      client.println("Content-Type: application/x-www-form-urlencoded; charset=utf-8");
      client.println("Accept: application/xhtml+xml");
      client.print("Content-Length: ");
      client.println(myDataString.length()); //calculate length
      client.println();
      client.println(myDataString);
      // Read from the nic or the IC buffer overflows with no warning and goes out to lunch
      while (client.available()) {
        char c = client.read();
      }
      client.stop();
    }
  }
}
    
