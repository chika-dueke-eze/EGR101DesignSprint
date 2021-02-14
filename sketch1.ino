const int buzzer = 9; 

#define trigPin 13

#define echoPin 12 

#define motor 6

void setup() {
  // put your setup code here, to run once:
 
  
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  
  pinMode (echoPin, INPUT);
  
  pinMode(buzzer, OUTPUT);

  pinMode(motor, OUTPUT);
  
  /*pinMode(5, OUTPUT);
  
  pinMode(6, OUTPUT);
  
  pinMode(7, OUTPUT);*/
  
  }

void loop() {
  // put your main code here, to run repeatedly:
    long duration, distance; 
  digitalWrite(trigPin, LOW);
  
  delay(2);
  
  digitalWrite(trigPin, HIGH);
  
  delay(10);
  
  digitalWrite(trigPin, LOW);
  
  duration= pulseIn(echoPin, HIGH);
  
  distance=(duration/2)/29.1;  /*This equation is used to accurately determine
                                 distance by using the time taken for waves to 
                                 bounce from the transducer to the responder
                               */
   Serial.println(distance);
   if(distance<=40){           //conditional that only executes if we come within 40cm of the sensor
   
   tone(buzzer, 3000);         // buzzer beeps if conditional is true

   digitalWrite(motor, HIGH); 
   delay(20000);              // delay for 20 seconds (we can always update this if we want a longer time for the motor to spin before reset)
    
   digitalWrite(motor, LOW);
   delay(100);

   
   }
   
   else{      
                
   noTone(buzzer);
    delay(1000);
   }
  
   ;
  
}
