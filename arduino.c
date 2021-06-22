#include <Ultrasonic.h> 
#define TRIGGER_PIN 12 
#define ECHO_PIN 13 
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN); 

void setup(){
    Serial.begin(9600);
    for (int i=2; i<5; i++) { 
        pinMode(i, OUTPUT); 
        Serial.print(i);
    }
}

void loop(){
    float cmMsec, inMsec; 
    long microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); 
    Serial.print("MS: "); 
    Serial.print(microsec); 
    Serial.print(", CM: "); 
    Serial.println(cmMsec); 
    delay(150); 

    if (cmMsec <= 10) { 
        digitalWrite(4, HIGH); 
        tone(5, 1000, 300);
        delay(100);
    }

    else if (cmMsec <= 25) { 
        digitalWrite(3, HIGH); 
        tone(5, 1000, 300);
        delay(250);
    }

    else if (cmMsec <= 40) { 
        digitalWrite(2, HIGH); 
        tone(5, 1000, 300);
        delay(400);
    }

    else { 
        for (int i=2; i<5; i++) {
            digitalWrite(i, LOW); 
        }
        noTone(5);
    }
}