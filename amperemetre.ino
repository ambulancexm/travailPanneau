/*
Measuring Current Using ACS712
*/
const int analogIn = A0;
const int voltIn = A1;
const int luxIn = A2;
static long totalSec =0;
static long totalWatt =0;
int mVperAmp = 100; // use 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 2500; 
double Voltage = 0;
double Amps = 0;

float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0; //  
float R2 = 7500.0; // 
int value = 0;

void setup(){ 
 Serial.begin(9600);
}

void loop(){
 
 RawValue = analogRead(analogIn);
 
 Voltage = (RawValue / 1024.0) * 5000; // Gets you mV
 
 Amps = ((Voltage - ACSoffset) / mVperAmp);

 
 

  value = analogRead(voltIn);
   vout = (value * 5.0) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
 
 totalWatt = totalWatt + (abs(Amps)*vin);
 totalSec++;
 
 Serial.print("Amps = "); // shows the voltage measured 
 Serial.print(abs(Amps),3); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print(" A");
 Serial.print("\tVolt : ");
 
 Serial.print(vin,2);
 Serial.print(" V");
 Serial.print("\tTravail ");
 Serial.print(abs(Amps)*vin,2);
 Serial.print(" Ws ; lux =>");
 Serial.println(analogRead(luxIn));
 Serial.print(" totalWatt : ");
 Serial.print(totalWatt);
 Serial.print(" totalSec : ");
 Serial.println(totalSec);
 delay(1000); 
 
}
