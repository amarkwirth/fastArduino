#ifndef __MAIN_H__
#define __MAIN_H__

#include <Arduino.h>

#include "OrcaFlash4_sequence.h"
#include "OrcaFlash4_movie.h"

// #define __AVR_ATmega328P__


// ATMEL ATMEGA328 / ARDUINO
//
//                            +-\/-+
//                      PC6  1|    |28  PC5 (AI 5)
//                (D 0) PD0  2|    |27  PC4 (AI 4)
//                (D 1) PD1  3|    |26  PC3 (AI 3)
//                (D 2) PD2  4|    |25  PC2 (AI 2)
//                (D 3) PD3  5|    |24  PC1 (AI 1)
//                (D 4) PD4  6|    |23  PC0 (AI 0)
//                      VCC  7|    |22  GND
//                      GND  8|    |21  AREF
//                      PB6  9|    |20  AVCC
//                      PB7 10|    |19  PB5 (D 13)
//                (D 5) PD5 11|    |18  PB4 (D 12)
//                (D 6) PD6 12|    |17  PB3 (D 11) PWM
//                (D 7) PD7 13|    |16  PB2 (D 10) PWM
//                (D 8) PB0 14|    |15  PB1 (D 9)  PWM
//                            +----+
//


//
//                            +-\/-+
//    RESET                  1|    |28  (AI 5)
//                           2|    |27  (AI 4)  SLM_trigger
//                           3|    |26  (AI 3)  SLM_finish
//    IO_CAM_trigger  (D 2)  4|    |25  (AI 2)  SLM_SPO3
//        ORCA_ready  (D 3)  5|    |24  (AI 1)  SLM_SPO2
//    IO_CAM_exposing (D 4)  6|    |23  (AI 0)  SLM_SPO1 SLM_seq_start
//                      VCC  7|    |22  GND
//                      GND  8|    |21  AREF
//    XTAL1             PB6  9|    |20  AVCC
//    XTAL2             PB7 10|    |19  (D 13)  IO_Laser
//    ORCA_trigger    (D 5) 11|    |18  (D 12)  SLM_ready
//    IO_CAM_shutter  (D 6) 12|    |17
//    IO_CAM_PowerOn  (D 7) 13|    |16
//    SLM_LED_ON      (D 8) 14|    |15
//                            +----+
//

#define TESTLED A1
#define TESTLED_PORT PORTC
#define TESTLED_PIN PC1

#define IO_Laser 13
#define IO_Laser_PORT PORTB
#define IO_Laser_PIN PB5

#define ORCA_trigger 5
#define ORCA_trigger_PORT PORTD
#define ORCA_trigger_PIN PD5

#define ORCA_ready_PORT   PORTD
#define ORCA_ready_INPORT PIND
#define ORCA_ready_PIN    PD3

#define IO_CAM_trigger 2
#define IO_CAM_trigger_PORT PORTD
#define IO_CAM_trigger_PIN PD2


#define SLM_trigger A4 
#define SLM_trigger_PORT PORTC
#define SLM_trigger_PIN PC4

#define SLM_LED_ON 8
#define SLM_LED_ON_PORT PORTB
#define SLM_LED_ON_PIN PB0

#define SLM_seq_start_PORT   PORTC
#define SLM_seq_start_INPORT PINC
#define SLM_seq_start_PIN PC0

#endif
