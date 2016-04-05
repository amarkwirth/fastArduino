#include <Arduino.h>

#include "orca.h"

String readString;
uint8_t globalerror=0;
char c = 0;

/////////////////////
//IO-Stuff///////////
/////////////////////
void zero_outputs()
{
    digitalWrite(IO_Laser, LOW);
    digitalWrite(IO_CAM_trigger, LOW);
    digitalWrite(ORCA_trigger, LOW);
    digitalWrite(SLM_trigger, LOW);

}

void setup()
{
    Serial.begin(38400);

    pinMode(TESTLED, OUTPUT);
    TESTLED_PORT &= ~(1<<TESTLED_PIN);

    pinMode(IO_Laser, OUTPUT);
    
    pinMode(IO_CAM_trigger, OUTPUT);

    pinMode(ORCA_trigger, OUTPUT);
    
    pinMode(SLM_trigger, OUTPUT);
    pinMode(SLM_LED_ON, INPUT);    
}


void loop()
{

    Serial.println("---------------------------");
    Serial.println("Hamamatsu Orca Flash 4.0");
    Serial.println("H: record movie");
    Serial.println("h: record sequence");
    Serial.println("---------------------------");

    while(Serial.available() == 0)
    {
        globalerror = 0;
    }
    int inByte = Serial.read();
        
        
        switch (inByte) // do something different depending on the character received.
        {
            case 'h':
            {
                globalerror  = OrcaFlash4_sequence();
                zero_outputs();
                Serial.print("OrcaFlash4_sequence reports "); Serial.println(globalerror);
                zero_outputs();
            }
            break;
            case 'H':
            {
                globalerror  = OrcaFlash4_movie();
                zero_outputs();
                Serial.print("OrcaFlash4_movie reports "); Serial.println(globalerror);
                zero_outputs();
            }
            break;
            default:
            {
                Serial.print("did not understand: "); Serial.println(inByte); Serial.print("\n");
                break;
            }
        }
        while (Serial.available() > 0)
        {
            globalerror = Serial.read();
            Serial.print("  ignored: ");
            Serial.print(globalerror);
        }
        Serial.print("\n");
}
