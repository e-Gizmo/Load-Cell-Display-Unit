/*
  e-Gizmo Load Cell Display Unit (LDU)

  *Accepts 3kg to 400kg capacity load cell
  *UART control (TTL level)

  This sample sketch allows you to setup
  the comparators, calibrate the LDU,
  modify the data precision and accuracy,
  to collect weighing data.

  ===================
  Wiring Connections:
  ===================
  Serial LCD II rev2 ~ GizDuino MCU

      TXD  ------------>   RXD
      RXD  ------------>   TXD
      GND  ------------>   GND

  Serial LCD II rev2 ~ XFW-002 Weighing sensor

     GND  ------------>   GND
       0  ------------>   DT
       1  ------------>   SCK
   +5VDC  ------------>   VCC

 XFW-002 Weighing sensor ~ Load cell (3kg to 400kg)
  
      E+  ------------>   RED wire
      E-  ------------>   BLACK wire
      A-  ------------>   WHITE wire
      A+  ------------>   GREEN wire

  by e-Gizmo Mechatronix Central
  November 12, 2015
  hhtp://www.e-gizmo.com

*/

void setup(){
  // Initialize serial:
  Serial.begin(9600);
  
  Serial.write(2);
  Serial.print("C2725"); //Calibrate command ex. 2.725kg "C2725"
  Serial.write(3);

  delay(2000);

  Serial.write(2);
  Serial.print("H3000"); //Set HIGH trigger for comparator ex. 3.000kg "H3000"
  Serial.write(3);

  delay(2000);

  Serial.write(2);
  Serial.print("L1000"); //Set LOW trigger for comparator ex. 3.000kg "L1000"
  Serial.write(3);

  delay(2000);

  Serial.write(2);
  Serial.print("S*"); // Save current settings (to NVRAM) or remember your calibration
  Serial.write(3);

  delay(1000);

  Serial.write(2); //STX
  Serial.print("Z"); //Tare/Zero weight please wait for 5 secs
  Serial.write(3); //ETX

}
void loop(){

// Put your codes here

}