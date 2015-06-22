/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h>

#define SERVO_ID  5

#define VERTICAL_ESQ_TRAS              0
#define LATERAL_DIAGONAL_PRINCIPAL     1
#define LATERAL_DIAGONAL_SECUNDARIA    2
#define VERTICAL_DIR_TRAS              3
#define VERTICAL_ESQ_FRENTE            4
#define VERTICAL_DIR_FRENTE            5

const int SERVO_PINS[6] = {3, 5, 6, 9, 10, 11};
const int START_ANGLES[6] = {135, 90, 160, 120, 120, 135};

int maxAngles[6] = {0, 0, 0, 0, 0, 0};
int minAngles[6] = {180, 180, 180, 180, 180, 180};
 
Servo servos[6];

//======================================================================================

void printAng(int servoId, int ang){
    Serial.print("servoId=");
    Serial.print(servoId);
    Serial.print(", ang (input)=");
    Serial.print(ang);  
    Serial.print(", ang (result)=");
    Serial.println(servos[servoId].read());  
}

void serAngle(int servoId, int ang){
    servos[servoId].write(ang);
    printAng(servoId, ang);
}
 
void setup() 
{ 
  Serial.begin(9600);
  
//  for(int i = 0 ; i < 6 ; i++){
//      servos[i].attach(SERVO_PINS[i]);
//      delay(200);
//      
//      servos[i].write(START_ANGLES[i]);
//      printAng(i, START_ANGLES[i]);
//      delay(1000);
//  }

    servos[VERTICAL_ESQ_TRAS].attach(SERVO_PINS[VERTICAL_ESQ_TRAS]);
    delay(200);
    serAngle(VERTICAL_ESQ_TRAS, 180);
    delay(1000);
    serAngle(VERTICAL_ESQ_TRAS, 0);
    delay(1000);
    serAngle(VERTICAL_ESQ_TRAS, START_ANGLES[VERTICAL_ESQ_TRAS]);
    delay(1000);
    
    servos[VERTICAL_DIR_TRAS].attach(SERVO_PINS[VERTICAL_DIR_TRAS]);
    delay(200);
    serAngle(VERTICAL_DIR_TRAS, 0);
    delay(1000);
    serAngle(VERTICAL_DIR_TRAS, 180);
    delay(1000);
    serAngle(VERTICAL_DIR_TRAS, START_ANGLES[VERTICAL_DIR_TRAS]);
    delay(1000);
    
    servos[VERTICAL_ESQ_FRENTE].attach(SERVO_PINS[VERTICAL_ESQ_FRENTE]);
    delay(200);
    serAngle(VERTICAL_ESQ_FRENTE, 0);
    delay(1000);
    serAngle(VERTICAL_ESQ_FRENTE, 180);
    delay(1000);
    serAngle(VERTICAL_ESQ_FRENTE, START_ANGLES[VERTICAL_ESQ_FRENTE]);
    delay(1000);
    
    servos[VERTICAL_DIR_FRENTE].attach(SERVO_PINS[VERTICAL_DIR_FRENTE]);
    delay(200);
    serAngle(VERTICAL_DIR_FRENTE, 180);
    delay(1000);
    serAngle(VERTICAL_DIR_FRENTE, 0);
    delay(1000);
    serAngle(VERTICAL_DIR_FRENTE, START_ANGLES[VERTICAL_DIR_FRENTE]);
    delay(1000);
    
//    int ang = 190;
//    while(servos[0].read() > 0){
//      serAngle(0, ang);
//      ang -= 2;
//      delay(200);
//    }
//    
//    ang = 0;
//    while(servos[0].read() < 360){
//      serAngle(0, ang);
//      ang += 2;
//      delay(200);
//    }

} 

int ang = START_ANGLES[0];
void loop() 
{
  
  int incomingByte;
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);
    
    if(incomingByte == '1'){
      ang += 15;
    }else{
      ang -= 15;
    }
      
    serAngle(SERVO_ID, ang);
    delay(100);
  }
} 

