#ifndef _MPL3115A2_H_
#define _MPL3115A2_H_

#include <stdint.h>

typedef enum {
    MPL3115A2_BAROMETER,
    MPL3115A2_ALTIMETER
} mpl3115a2_mode_t;

void MPL3115A2_Init(void);
float MPL3115A2_ReadTemp(void);
float MPL3115A2_ReadPressure(void);

#endif
