// MASTER FUNCTION CODE 

/* FOR 3 JOTSTICKS Which passes 'a' - 'e' and '1' - '6' charcters 
   to the SLAVE bluetooth module */

int joy1X = A0;
int joy1Y = A1;
int joy2X = A2;
int joy2Y = A3;
int joy3X = A4;
int joy3Y = A5;
int val1 , val2 , val3 , val4 , val5 , val6;
int nval1 , nval2 , nval3 , nval4 , nval5 , nval6;
   
void setup() {
 pinMode(joy1X,INPUT);  // motor for left and right
 pinMode(joy1Y,INPUT);  // motor for front and back
 pinMode(joy2X,INPUT);  // servo for base
 pinMode(joy2Y,INPUT);  // servo for HAND primary
 pinMode(joy3X,INPUT);  // picking the objects
 pinMode(joy3Y,INPUT);  // servo for HAND secondary
 Serial.begin(38400);
}

void loop() {
// motor for front and back
  val1 = analogRead(joy1X);
  nval1 = map( val1 , 0 , 1023 , 0 , 180 );
  //Serial.print(nval1);
  if ( nval1 > 110 )
  Serial.print('a');
  else if ( nval1 < 80 )
  Serial.print('1');
  else if ( nval1 > 80 && nval1 < 110 )
  Serial.print('s');
  
  
// motor for left and right
  val2 = analogRead(joy1Y);
  nval2 = map( val2 , 0 , 1023 , 0 , 180 );
  //Serial.print(nval2);
  if ( nval2 > 110 )
  Serial.print('b');
  else if ( nval2 < 80 )
  Serial.print('2');

// servo for base
  val3 = analogRead(joy2X);
  nval3 = map( val3 , 0 , 1023 , 0 , 180 );
  //Serial.print(nval3);
  if ( nval3 > 110 )
  Serial.print('c');
  else if ( nval3 < 80 )
  Serial.print('3');

// servo for HAND primary
  val4 = analogRead(joy2Y);
  nval4 = map( val4 , 0 , 1023 , 0 , 180 );
  //Serial.print(nval4);
  if ( nval4 > 110 )
  Serial.print('d');
  else if ( nval4 < 80 )
  Serial.print('4');

// picking the objects
 val5 = analogRead(joy3X);
  nval5 = map( val5 , 0 , 1023 , 0 , 180 );
  //Serial.print(nval5);
  if ( nval5 > 110 )
  Serial.print('e');
  else if ( nval5 < 80 )
  Serial.print('5');

// servo for HAND secondary4
  val6 = analogRead(joy3Y);
  nval6 = map( val6 , 0 , 1023 , 0 , 180 );
  //Serial.print(nval6);
  if ( nval6 > 110 )
  Serial.print('f');
  else if ( nval6 < 80 )
  Serial.print('6');
  delay(1000);
  //Serial.print('z');
// To clear the queue using the switch in the joystick
  
}





