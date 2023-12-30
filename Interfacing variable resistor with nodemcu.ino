/*pot 1st_pin-vcc 2nd_pin-A0 3rd_pin-gnd
There will be a Analog to digital converter(ADC) in nodemcu which convert the analog signal to voltage signal
Analog value ranges from 0-1023
formula to find the equivalent voltage value is 0.003225*stepvalue
If the stepvalue is 1023 then the voltage is 3.3V which is the max V of the nodemcu.
*/
void setup() {
  Serial.begin(9600); 
}
int stepvalue;
void loop()
{
  stepvalue=analogRead(A0);
  Serial.print("potvalue: ");
  Serial.println(stepvalue);
  delay(1000);
}
