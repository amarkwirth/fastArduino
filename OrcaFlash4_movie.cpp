#include "OrcaFlash4_movie.h"

int OrcaFlash4_movie(void)
{
  Serial.println("2,5 µs readout, 1 ms light");
  delay(1000);
  SLM_seq_start_PORT |= (1<<SLM_seq_start_PIN);
//    while(!(SLM_seq_start_INPORT) & (1<<SLM_seq_start_PIN))
//    {
//      SLM_trigger_PORT |= (1<<SLM_trigger_PIN);
//      delayMicroseconds(20);
//      SLM_trigger_PORT &= ~(1<<SLM_trigger_PIN);
//     delay(4);
//    }
  
//    delay(1000);
  uint8_t run=1;
  while(run)
  {
  //    while(!((ORCA_ready_INPORT) & (1<<ORCA_ready_PIN)))
  //   {
  //   }
    uint8_t i=0,j=0;
    cli();
    for(j=0;j<8;j++)
    {
     for(i=0;i<9;i++)
     {
      ORCA_trigger_PORT |= (1<<ORCA_trigger_PIN);
      delayMicroseconds(10);
      ORCA_trigger_PORT &= ~(1<<ORCA_trigger_PIN);
      delayMicroseconds(2151);				/*((512/2 * 9.74 µs)-370 µs - 10 µs)*/ //korrigiert um 37 µs
      SLM_trigger_PORT |= (1<<SLM_trigger_PIN);
      delayMicroseconds(372);
      SLM_trigger_PORT &= ~(1<<SLM_trigger_PIN);
      IO_Laser_PORT |= (1<<IO_Laser_PIN);
      delayMicroseconds(999);
      IO_Laser_PORT &= ~(1<<IO_Laser_PIN);
      delayMicroseconds(1250);
     }
    }
    

    ORCA_trigger_PORT |= (1<<ORCA_trigger_PIN);
    delayMicroseconds(10);
    ORCA_trigger_PORT &= ~(1<<ORCA_trigger_PIN);
    delayMicroseconds(2151);        /*((512/2 * 9.74 µs)-370 µs - 10 µs)*/ //korrigiert um 37 µs
    //SLM_trigger_PORT &= ~(1<<SLM_trigger_PIN);
    delayMicroseconds(372);
    //SLM_trigger_PORT |= (1<<SLM_trigger_PIN);
    TESTLED_PORT |= (1<<TESTLED_PIN);
    delayMicroseconds(999);
    TESTLED_PORT &= ~(1<<TESTLED_PIN);

    ORCA_trigger_PORT |= (1<<ORCA_trigger_PIN);
    delayMicroseconds(10);
    ORCA_trigger_PORT &= ~(1<<ORCA_trigger_PIN);
    delayMicroseconds(2151);        /*((512/2 * 9.74 µs)-370 µs - 10 µs)*/ //korrigiert um 37 µs
    //SLM_trigger_PORT &= ~(1<<SLM_trigger_PIN);
    delayMicroseconds(372);
    //SLM_trigger_PORT |= (1<<SLM_trigger_PIN);
    //TESTLED_PORT &= ~(1<<TESTLED_PIN);
    delayMicroseconds(999);
    //TESTLED_PORT &= ~(1<<TESTLED_PIN);
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
  return 0;
}
