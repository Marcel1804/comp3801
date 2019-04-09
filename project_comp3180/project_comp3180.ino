//time
unsigned long time = 0;
//speed
float speed;

// front section
int  FpinRL = 4;
int  FpinGL = 3;
int  FpinUSecho = 9;
int  FpinUStri = 13;
int  FpinBuzzer =5;
int  FArray[10];
int i=0;
int ans=0;

// left section 
int  LpinRL = A0;//Analog pin
int  LpinGL = A3;//Analog pin
int  LpinUSecho = 8;
int  LpinUStri = 12;


// right section
int  RpinRL = A1;//Analog pin
int  RpinGL = A4;//Analog pin
int  RpinUSecho = 7;
int  RpinUStri = 11;

// back section
int  BpinRL = A2;//Analog pin
int  BpinGL = A5;//Analog pin
int  BpinUSecho = 6;
int  BpinUStri = 10;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);   
    //front  board
        pinMode(FpinUStri,OUTPUT);
        pinMode(FpinBuzzer ,OUTPUT);
        pinMode(FpinUSecho ,INPUT);
        pinMode(FpinGL,OUTPUT);
        pinMode(FpinRL,OUTPUT);
    
     //left  board

     //rigth board

     //back board
                     
}

void loop() {
  // put your main code here, to run repeatedly:
  
    //front  board
     
    
     
     digitalWrite(FpinUStri,LOW);
     delayMicroseconds(2);

     digitalWrite(FpinUStri,HIGH);
     delayMicroseconds(10);

     digitalWrite(FpinUStri,LOW);
     
     int duration =pulseIn(FpinUSecho,HIGH);

     // in cm 
     int distance = duration/58.2;
     
       if( distance >0 ){
           if (i<10 ){
             digitalWrite(FpinRL,LOW);
             digitalWrite(FpinGL,HIGH);
     
               FArray[i]=distance;
               ans=ans+FArray[i];
               //Serial.println(ans);
               i++;
               }
               if (i==10){
                i=0; 
               ans=ans/10;
               //Serial.print(ans);
               //Serial.println("cm");
               ans=0;
               }
       }
      if (distance < 0){
             digitalWrite(FpinGL,LOW);
             digitalWrite(FpinRL,HIGH);
            }
     float test=(float)distance/100;
     float test2= (float)(millis() - time)/1000;
     Serial.print(distance);
     Serial.println("cm"); 
       
     //Serial.println(test);
     
     Serial.println(test/test2-speed);
     float v = test/test2-speed;
     speed=test/test2;     
     time= millis();
     Serial.println(v);

      if (distance<50 && v >0.2){
        tone(FpinBuzzer,1000,500);
      }     
     delay(50);

     

    //delay(1500);

    //left  board

    //rigth board

    //back board
}
