
/*
  Fundacion Kinal
  Centro Educativo Tecnico Kinal
  Electronica
  Grado: Quinto
  Curso: Taller de Electronica Digital
  Alumno: Roberto Antonio Monterroso Aguilar
  Seccion: A
  Carne: 2019507
  Proyecto:   Acelerometro.
*/

#include <SparkFun_ADXL345.h>
#include <SPI.h>
#include <Wire.h>
#include <LedControl.h>   
int x;

//Directivas de preprocesador
#define Dpin0   11   //pin 12 conectado al pin de datos 
#define Dclock0 10   //pin 11 conectado al pin de clock 
#define DLoad0  12    //pin 10 conectado al pin de carga 

LedControl matriz_led = LedControl(Dpin0,Dclock0,DLoad0,1);
ADXL345 adxl_sensor = ADXL345();

void sensor_values(void); // funcion a utilizar
void Matriz(void); // funcion a utilizar

byte Figura_1[8]= { 
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01010100
};
byte Figura_2[8]= { 
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01010100,
  B01000100
};
byte Figura_3[8]= {  
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01010100,
  B01000100,
  B01000100
};
byte Figura_4[8]= { 
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01010100,
  B01000100,
  B01000100,
  B01000100
};
byte Figura_5[8]= { 
  B01000100,
  B01000100,
  B01000100,
  B01010100,
  B01000100,
  B01000100,
  B01000100,
  B01000100
};
byte Figura_6[8]= { 
  B01000100,
  B01000100,
  B01010100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100
};
byte Figura_7[8]= { 
  B01000100,
  B01010100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100
};
byte Figura_8[8]= { 
  B01111100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100
};

void setup() {
  Serial.begin(9600);
  matriz_led.shutdown(0,false); //Activo el max7219 para poder mostrar los digitos.
  matriz_led.setIntensity(0,15); //Brilo a la mitad 
  matriz_led.clearDisplay(0);//limpio el display
  adxl_sensor.powerOn();
  adxl_sensor.setRangeSetting(8);
}

void loop() {
  sensor_values();
  Matriz(); 
}

void sensor_values(void){  
  adxl_sensor.readAccel(&x);
  Serial.print("x= ");
  Serial.println(x);
  delay(200);
}

void Matriz(void){
  if(x >= -3 && x <= 3){
    matriz_led.clearDisplay(0);
      for(int i=0; i<8;i++)
      {
        matriz_led.setRow(0,i,Figura_4[i]);
      }
  }
  if(x >= -13 && x <=-4 ){
    matriz_led.clearDisplay(0);
      for(int i=0; i<8;i++)
      {
        matriz_led.setRow(0,i,Figura_3[i]);
      }
  }
  if(x >= -23 && x <=-14){
    matriz_led.clearDisplay(0);
      for(int i=0; i<8;i++)
      {
        matriz_led.setRow(0,i,Figura_2[i]);
      }
  }
  if(x >= -34 && x <=-24 ){
    matriz_led.clearDisplay(0);
      for(int i=0; i<8;i++)
      {
        matriz_led.setRow(0,i,Figura_1[i]);
      }
  }
  if(x >= 4 && x <=10 ){
    matriz_led.clearDisplay(0);
      for(int i=0; i<8;i++)
      {
        matriz_led.setRow(0,i,Figura_5[i]);
      }
  }
  if(x >= 11 && x <=17){
    matriz_led.clearDisplay(0);
      for(int i=0; i<8;i++)
      {
        matriz_led.setRow(0,i,Figura_6[i]);
      }
  }
  if(x >= 18 && x <=24 ){
    matriz_led.clearDisplay(0);
      for(int i=0; i<8;i++)
      {
        matriz_led.setRow(0,i,Figura_7[i]);
      }
  }
  if(x >= 25 && x <=33 ){
    matriz_led.clearDisplay(0);
      for(int i=0; i<8;i++)
      {
        matriz_led.setRow(0,i,Figura_8[i]);
      }
  }
  
}
