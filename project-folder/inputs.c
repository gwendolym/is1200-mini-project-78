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