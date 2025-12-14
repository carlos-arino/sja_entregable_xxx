/* Ejercicio entregable 001
 Deben de utilizar este archivo los alumnos con c<5, d<5, u>=5
 siendo c,d,u las tres últimas cifras del DNI 22000cdu -W
 Luminosidad y motor paso a paso con potenciometro
 Para cambiar Luminosidad o haz click sobre el sensor NTC durante la simulacion
 rellenar vuestro nombre y DNI
 NOMBRE ALUMNO: XXXXX
 DNI: XXXXX
 ENLACE WOKWI: XXXXXXX
*/
#include <Stepper.h>
#include <Arduino.h>

Stepper myStepper(200, 14, 27, 26, 25);

const int potPin = 34; // Pin analógico para el potenciómetro
const int luxPin = 35; // Pin analógico para el sensor de luminosidad

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  myStepper.setSpeed(10);
}

void loop()
{
  // put your main code here, to run repeatedly:

  myStepper.step(100);
  delay(500);
  Serial.print(analogRead(potPin)); // siempre posición 180 del potenciómetro
  Serial.print(", ");
  Serial.println(analogRead(luxPin));
  myStepper.step(-100);
  Serial.print(analogRead(potPin)); // siempre posición 0 del potenciómetro
  Serial.print(", ");
  Serial.println(analogRead(luxPin));
  delay(500);
}