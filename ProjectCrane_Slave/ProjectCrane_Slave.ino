// SLAVE FUNCTION CODE
//For the servos and the motor controller
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int m1_red = 2;
int m1_black = 4;
int m2_red = 7;
int m2_black = 8;

int pos;
char state;
int current_pos1;
int current_pos2;
int current_pos3;
int current_pos4;

void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  pinMode( m1_red , OUTPUT );
  pinMode( m1_black , OUTPUT );
  pinMode( m2_red , OUTPUT );
  pinMode( m2_black , OUTPUT );
  Serial.begin(38400);
}

void loop() {
  if (Serial.available() > 0){
    state = Serial.read();
  }
  switch (state){
  case 'a' :
      // motor for front
            digitalWrite(m1_red , HIGH );   
            digitalWrite(m1_black , LOW );
            digitalWrite(m2_black , LOW );
            digitalWrite(m2_red , HIGH );
            break;
  case '1' :
     // motor for back
            digitalWrite(m1_red , LOW );   
            digitalWrite(m1_black , HIGH );
            digitalWrite(m2_black , HIGH );
            digitalWrite(m2_red , LOW );
            
            break;
  case 'b' :
     // motor for left
            digitalWrite(m2_black , LOW );
            digitalWrite(m2_red , HIGH );
            break;
  case '2' :
     // motor for right
            digitalWrite(m1_red , HIGH );   
            digitalWrite(m1_black , LOW );
            break;
     //perfect till above       
  case 'c' :
            current_pos1=servo1.read();
            Serial.println(current_pos1);
            if(current_pos1<170)
            servo1.write(current_pos1 + 10);
            else
            servo1.write(180);
            delay(1000);
            break;
  case '3' :
            current_pos1=servo1.read();
            Serial.println(current_pos1);
            if(current_pos1>10)
            servo1.write(current_pos1 - 10);
            else
            servo1.write(0);
            delay(1000);
            break;                              
  case 'd' :
            current_pos2=servo2.read();
            Serial.println(current_pos2);
            if(current_pos2<170)
            servo2.write(current_pos2 + 10);
            else
            servo2.write(180);
            delay(1000);
            break;
  case '4' :
            current_pos2=servo2.read();
            Serial.println(current_pos2);
            if(current_pos2>10)
            servo2.write(current_pos2 - 10);
            else
            servo2.write(0);
            delay(1000);
            break;
            /* for moving the secondary arm */ 
  case 'e' :
            current_pos3=servo3.read();
            Serial.println(current_pos3);
            if(current_pos3<170)
            servo3.write(current_pos3 + 10);
            else
            servo3.write(180);
            delay(1000);
            break;
  case '5' :
            current_pos3=servo3.read();
            Serial.println(current_pos3);
            if(current_pos3>10)
            servo3.write(current_pos3 - 10);
            else
            servo3.write(0);
            delay(1000);
            break;
            /* for picking the object */  
  case 'f' :
            current_pos4=servo4.read();
            Serial.println(current_pos4);
            if(current_pos4<170)
            servo4.write(current_pos4 + 10);
            else
            servo4.write(180);
            delay(1000);
            break;
  case '6' :
            current_pos4=servo4.read();
            Serial.println(current_pos4);
            if(current_pos4>10)
            servo4.write(current_pos4 - 10);
            else
            servo4.write(0);
            delay(1000);
            break;
  case 's' : digitalWrite(m1_red , LOW );   
            digitalWrite(m1_black , LOW );
            digitalWrite(m2_black , LOW );
            digitalWrite(m2_red , LOW ); 
            break;
 defalut :  current_pos1=servo1.read();
            servo1.write(current_pos1);
            current_pos2=servo2.read();
            servo2.write(current_pos2);
            current_pos3=servo3.read();
            servo3.write(current_pos3);
            current_pos4=servo4.read();
            servo4.write(current_pos4);
            } 
}
