/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 *******************************************************************************/

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    bool bcdFormat;
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t weekday;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} RTCC_DATETIME;

void RTCC_Initialize(RTCC_DATETIME * value);
void RTCC_TimeGet(RTCC_DATETIME * value);
void RTCC_BuildTimeGet(RTCC_DATETIME *dateTime, bool bcdFormat);

/* Deprecated API.  Will be removed in future release. */
#define BSP_RTCC_DATETIME RTCC_DATETIME
void __attribute__((deprecated)) BSP_RTCC_Initialize(BSP_RTCC_DATETIME * value);
void __attribute__((deprecated)) BSP_RTCC_TimeGet(BSP_RTCC_DATETIME * value);






