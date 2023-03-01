#include <stdint.h>
#include <pic32mx.h>
#include "projcode.h"

int pressSw() {
    return (PORTD >> 8) & 0xf;
}

int pressBt() {
    int ret = (PORTF >> 1) & 0x1;
    return ((PORTD >> 4) & 0xe) | ret;
}

void sw4Enable(){
    IECSET(0) = 0x80000; // INT4IF is at bit 19 (1000 0000 0000 0000 0000). bit 19 enables intterupt 4
    IPC(4) = (IPC(4) & 0x00ffffff) | 0x1a000000; // 000(1 10)(10). give intterupt 4 1 less main prio and sub prio than timer 2
}

void sw3Enable(){
    IECSET(0) = 0x8000;
    IPC(3) = (IPC(3) & 0x00ffffff) | 0x18000000; // 0001 0110
}

void sw2Enable() {
    IECSET(0) = 0x800;
    IPC(2) = (IPC(2) & 0x00ffffff) | 0x12000000; // 0001 0010
}

void sw1Enable() {
    IECSET(0) = 0x80;
    IPC(1) = (IPC(1) & 0x00ffffff) | 0x0e000000; // 0000 1110
}

void sw4Disable(){
    IECCLR(0) = 0x080000; // disable INT4
}

void sw3Disable(){
    IECCLR(0) = 0x08000; // disable INT3
}

void sw2Disable(){
    IECCLR(0) = 0x800; // disable INT4
}

void sw1Disable(){
    IECCLR(0) = 0x80; // disable INT3
}