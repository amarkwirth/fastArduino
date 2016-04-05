#include "OrcaFlash4_sequence.h"

int OrcaFlash4_sequence(void)
{
    Serial.println("2,5 µs readout, 1 ms light");
    int noi=0;
    Serial.println("please specify number of images:");
    if(Serialtoint(&noi) != 0) { return 45; }
    int i, run=1;
    for(i=noi; ((i>0) && (run!=0)); i--)
    {
           cli();
      ORCA_trigger_PORT |= (1<<ORCA_trigger_PIN);
      delayMicroseconds(10);
      ORCA_trigger_PORT &= ~(1<<ORCA_trigger_PIN);
      delayMicroseconds(2151);       /*((512/2 * 9.74 µs)-370 µs - 10 µs)*/ //korrigiert um 37 µs
      SLM_trigger_PORT |= (1<<SLM_trigger_PIN);
      delayMicroseconds(372);
      SLM_trigger_PORT &= ~(1<<SLM_trigger_PIN);
      IO_Laser_PORT |= (1<<IO_Laser_PIN);
      delayMicroseconds(999);
      IO_Laser_PORT &= ~(1<<IO_Laser_PIN);
      sei();
      while (Serial.available() > 0)
      {
        uint8_t foo = Serial.read();
        if ((foo  == 'x') || (foo == 'X'))
          {
              run=0;
          }
      }
  }
  ORCA_trigger_PORT |= (1<<ORCA_trigger_PIN);
    delayMicroseconds(10);
    ORCA_trigger_PORT &= ~(1<<ORCA_trigger_PIN);
    delayMicroseconds(2151);        /*((512/2 * 9.74 µs)-370 µs - 10 µs)*/ //korrigiert um 37 µs
    SLM_trigger_PORT &= ~(1<<SLM_trigger_PIN);
    delayMicroseconds(372);
    SLM_trigger_PORT |= (1<<SLM_trigger_PIN);
    TESTLED_PORT |= (1<<TESTLED_PIN);
    delayMicroseconds(999);
    TESTLED_PORT &= ~(1<<TESTLED_PIN);
    sei();
    while (Serial.available() > 0)
    {
      uint8_t foo = Serial.read();
      if ((foo  == 'x') || (foo == 'X'))
      {
        run=0;
      }
    }
    return i;
}
