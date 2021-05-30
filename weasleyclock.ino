// This #include statement was automatically added by the Particle IDE.
#include "lib1.h"


Servo myservo;

int button = D1;
int pos = 0;
char previousmoves[10];

void setup() {
    Serial.begin(9600);
    Serial.println("setting up");
    Particle.function("moveclock", moveclock);
    myservo.attach(D2);
    // pinMode(button, INPUT_PULLDOWN);
}

int moveclock(String command) {
    addMoveToPreviousMoves(command[0]);
    return moveServo(command);
}

int moveServo(String command) {
    Serial.println("moving servo with command - " + command);
    int offcampus = 18.3;
    int traveling = 52;
    int mortalperil = 83;
    int holiday = 99.4;
    int oncampus = 126;
    int home = 149.1;
    int lab = 0;
    
    // OFF CAMPUS
    if (command == "1") { 
        myservo.write(offcampus); 
        
        return 1;
    }
    // TRAVELING
    else if (command == "2") {
        myservo.write(traveling);
        //delay(10000);
        //moveServo(String(previousmoves[0]));
        return 2;
    }
    // MORTAL PERIL
    else if (command == "3") {
        myservo.write(mortalperil); 
        //delay(1800000);
        //moveServo(String(previousmoves[0]));
        
        return 3;
    }
    // HOLIDAY
    else if (command == "4") {
        myservo.write(holiday);
        
        return 4;
    }
    // ON CAMPUS
    else if (command == "5") {
        // if (previousmoves[0] == '2') { // if I was traveling in the previous move (i.e. entering MIT)
        //     myservo.write(126);
        //     return 5;
        // } else { // if I was not traveling in the previous move, I was at MIT (i.e. now leaving MIT) 
        //     myservo.write(51);
        //     return 2;
        // }
        myservo.write(oncampus);
        
        return 5;
    }
    // HOME
    else if (command == "6") {
        myservo.write(home);
        
        return 6;
    }
    // LAB
    else if (command == "7") {
        myservo.write(lab);
        
        return 7;
    }
    // for testing, run through all of them
    else if (command == "8") {
        myservo.write(18); 
        delay(10000);
        myservo.write(52);
        delay(10000);
        myservo.write(78.2); 
        delay(10000);
        myservo.write(98.4);
        delay(10000);
        myservo.write(126);
        delay(10000);
        myservo.write(148.5);
        delay(10000);
        myservo.write(165);
    }
}

void addMoveToPreviousMoves(char move) {
    Serial.println("adding move to previous moves " + String(move));
    char tmpArray[10];
    tmpArray[0] = move;
    for (int i = 0; i < 10; i++) {
        tmpArray[i + 1] = previousmoves[i];
    }
    
    memcpy(previousmoves, tmpArray, 10);
}

void loop() {

}