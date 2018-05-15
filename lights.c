#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#include <random.h>
#endif

#define PIN            9
#define NUMPIXELS      5

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

int buttonStatusRed;
int buttonStatusGrn;
int buttonStatusBlu;
int buttonStatusWht;
int red=0;
int green=0;
int blue=0;
int rando;

void setup() {
  //declare pinmodes
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(9, OUTPUT);
  //intialize serial comms
  Serial.begin(9600); //comm rate
  pixels.begin(); // This initializes the NeoPixel library.
  

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonStatusRed=digitalRead(2);
  buttonStatusGrn=digitalRead(3);
  buttonStatusBlu=digitalRead(4);
  buttonStatusWht=digitalRead(5);
  Serial.println(buttonStatusRed);
  Serial.println(buttonStatusGrn);
  Serial.println(buttonStatusBlu);
  
  if(buttonStatusRed == HIGH){
      red = 255;
  }else{
      red = 0;
  };
  if(buttonStatusGrn == HIGH){
     green = 255;
  }else{
    green = 0;
  };

   if(buttonStatusBlu == HIGH){
      blue = 255;
  }else{
    blue = 0;
  };
  if(buttonStatusWht == HIGH){
      //rando=randInt(0,255); 
      red = 255;
      green= 255;
      blue = 255;
  };
  for(int i=0; i<NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(red,green,blue));
  pixels.show();
  
  }

}