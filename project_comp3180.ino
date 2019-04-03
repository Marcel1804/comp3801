
// front section
int  FpinRL = 0;
int  FpinGL = 0;
int  FpinUSgnd = 0;
int  FpinUSvcc = 0;
int  FpinUSec = 0;
int  FpinUStri = 0;
int  FpinBgnd = 0;
int  FpinB = 0;


// back section
int  BpinRL = 0;
int  BpinGL = 0;
int  BpinUSgnd = 0;
int  BpinUSvcc = 0;
int  BpinUSec = 0;
int  BpinUStri = 0;


// right section
int  RpinRL = 0;
int  RpinGL = 0;
int  RpinUSgnd = 0;
int  RpinUSvcc = 0;
int  RpinUSec = 0;
int  RpinUStri = 0;
int  RpinBgnd = 0;
int  RpinB = 0;

// left scetion 
int  LpinRL = 0;
int  LpinGL = 0;
int  LpinUSgnd = 0;
int  LpinUSvcc = 0;
int  LpinUSec = 0;
int  LpinUStri = 0;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);   
    pinMode(8,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(13,OUTPUT);
    pinMode(9,INPUT);
                     
}

void loop() {
  // put your main code here, to run repeatedly:
     tone(13,1000,500);
     digitalWrite(7,HIGH);
     
     digitalWrite(8,LOW);
     delayMicroseconds(2);

     digitalWrite(8,HIGH);
     delayMicroseconds(10);

     digitalWrite(8,LOW);
     
     int duration =pulseIn(9,HIGH);

     // in cm 

     int distance = duration/58.2;
     Serial.print(distance);
     Serial.println("cm");
     delay(50);
    
    
     
    //delay(1500);
}
