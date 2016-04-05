#include "Serialtoint.h"

int Serialtoint(int *outint)
{
    String inString = "";    // string to hold input
    while (Serial.available() == 0)
    {
      delay(2);
    }
    while (Serial.available() > 0)
    {
      delay(2);
      int inChar = Serial.read();
      if (isDigit(inChar))
      {
        inString += (char)inChar;
      }
    }
   *outint = inString.toInt();
   return 0;
}
