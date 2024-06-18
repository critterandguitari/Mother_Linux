#ifndef CM4OG4_H
#define CM4OG4_H

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <wiringShift.h>
#include <wiringPiI2C.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "../OledScreen.h"
#include "../OSC/OSCMessage.h"
#include "../OSC/SimpleWriter.h"
#include "../SLIPEncodedSerial.h"
#include "../Serial.h"

class CM4OG4
{
    public:
        CM4OG4();
        void init();
        void poll();
        void pollKnobs();
        void updateOLED(OledScreen &s);
        void ping();
        void shutdown();
        void setLED(unsigned c);
        void clearFlags();

        uint32_t encBut;
        uint32_t encButFlag;
        uint32_t encTurn;
        uint32_t encTurnFlag;
        uint32_t knobFlag;
        uint32_t adcs[8];
        uint32_t footswitch;
        uint32_t footswitchFlag;
        uint32_t keyStates;
        uint32_t keyStatesLast;
        uint32_t keyFlag;
        
        // organelle m specific stuff
        uint32_t pwrStatus;
        uint32_t micSelSwitch;
	    float batteryVoltage;
	    uint32_t batteryBars;
        bool lowBatteryShutdown;

    private:        
        int getEncoder();
        void getKeys();
        uint32_t adcRead(uint8_t adcnum);
        void displayPinValues();
	    void checkFootSwitch ();
         
        // pin values from io expanders
        uint8_t io0l;
        uint8_t io0h;
        uint8_t io1l;
        uint8_t io1h;
    
        uint8_t lrmem;
	    int lrsum;
	    int num;
        uint8_t int0;
        uint8_t int1;
        int fd0;
        int fd1;

};


#endif
