/*
 * set up wifi connections. You will have to changge the: 
 * local IP, gateway IP, subnet_mask, ssid, security type and passphrase  
 * to match your network
 */
void WIFI_SETUP(){
  // Wireless configuration parameters ----------------------------------------
  unsigned char local_ip[] = {192,168,43,2};  // IP address of WiShield
  unsigned char gateway_ip[] = {192,168,43,1};  // router or gateway IP address
  unsigned char subnet_mask[] = {255,255,255,0};  // subnet mask for the local network
  const prog_char ssid[] PROGMEM = {"yhtomit"};   // max 32 bytes
  
  unsigned char security_type = 3;  // 0 - open; 1 - WEP; 2 - WPA; 3 - WPA2

  // WPA/WPA2 passphrase
  const prog_char security_passphrase[] PROGMEM = {"12345678"}; // max 64 characters
  
  // WEP 128-bit keys
  // sample HEX keys
  prog_uchar wep_keys[] PROGMEM = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, // Key 0
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Key 1
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Key 2
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  // Key 3
          };
  
  // setup the wireless mode
  // infrastructure - connect to AP
  // adhoc - connect to another WiFi device
  unsigned char wireless_mode = WIRELESS_MODE_INFRA;
  
  unsigned char ssid_len;
  unsigned char security_passphrase_len;
  // End of wireless configuration parameters ----------------------------------------
}

/*
 * print out the incoming data from the server
 * i only used this for testing
 */
void printData(char* data, int len) {
  int counter = 0;
  // Print the data returned by the server
  // Note that the data is not null-terminated, may be broken up into smaller packets, and 
  // includes the HTTP header. 
  /*while (len-- > 0) {
      *(data++);
      if (*data == '$')counter++;
      if (counter == 1) string += *data;
      //Serial.print(counter);
  } */
  while (len-- > 0) {
    Serial.print(*(data++));
  }
}

