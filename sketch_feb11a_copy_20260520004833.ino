

//Ultrasonic
#define trigPin 9
#define echoPin 10

//RGB LED
#define RED 5
#define BLUE 6
#define GREEN 7

//Buzzer
#define buzzer 4


//Distance Function
int getDistance(){

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  long duration=pulseIn(echoPin,HIGH,20000);

  int distance=duration*0.034/2;

  return distance;

}

//RGB Control

void setColor(bool r,bool g,bool b){

  digitalWrite(RED,r);
  digitalWrite(GREEN,g);
  digitalWrite(BLUE,b);
}

void setup(){

  Serial.begin(9600);

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);

  pinMode(buzzer,OUTPUT);

  
  
}

void loop(){

 int d=getDistance();
 Serial.println(d);

 //VERY CLOSE(50cm)
 if(d>0&&d<50){

  //RED
  setColor(HIGH,LOW,LOW);

  //FAST BEEPS
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  delay(50);

  
 }
  
  //OBJECT DETECTED(100cm)
  else if(d>=50&&d<100){

    //YELLOW
    setColor(HIGH,HIGH,LOW);

    //SHORT BEEPS
    digitalWrite(buzzer,HIGH);
    delay(40);
    digitalWrite(buzzer,LOW);
    delay(250);

    
  }

  //SAFE
  else{

    //GREEN
    setColor(LOW,HIGH,LOW);
    digitalWrite(buzzer,LOW);


  }
}
 

  
