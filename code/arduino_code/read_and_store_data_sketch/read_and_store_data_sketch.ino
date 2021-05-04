// This sketch is intended to read data from the MKR ENV shield and 
// store it in a CSV file using Python

#include <Arduino_MKRENV.h> // includes ready-made library for MKR ENV shield

// global variables to hold data headers
String label1 = "Temperature";
String label2 = "Humidity";
String label3 = "Illuminance";

// variable to hold boolean to only run header loop once
bool label = true;
// variables to hold sensor values
float temp, tempF, humidity, lux; 
int freq = 1000; // data collection frequency (1 seconds)

void setup() {
  //initialize serial and wait for port to open:
  Serial.begin(9600);
  
  while (!Serial);
  
   if (!ENV.begin()) {
    // prints the line below if there was no connection established to the shield
    Serial.println("Failed to initialize MKR ENV shield!");

    while (1);
  }
  Serial.print(label1);
  Serial.print(",");
  Serial.print(label2);
  Serial.print(",");
  Serial.println(label3);
}

void loop() {

  //print out column headers, only once
  /*
  while(label) {
    Serial.print(label1);
    Serial.print(",");
    Serial.print(label2);
    Serial.print(",");
    Serial.println(label3);
    label = false;
  }
  */
  temp = ENV.readTemperature();
  tempF = temp * (9.0/5.0) + 32.0;
  humidity = ENV.readHumidity();
  lux = ENV.readIlluminance();

  //Display data to serial monitor in CSV format
  Serial.print(tempF);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.println(lux);
  delay(freq);
}
