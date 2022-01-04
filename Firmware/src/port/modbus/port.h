/*
 * FreeModbus Libary: BARE Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: port.h,v 1.1 2006/08/22 21:35:13 wolti Exp $
 */

#ifndef _MODBUSPORT_H
#define _MODBUSPORT_H

#include <xc.h>

#include <stdbool.h>
#include <assert.h>

#define    INLINE                      inline
#define PR_BEGIN_EXTERN_C           extern "C" {
#define    PR_END_EXTERN_C             }

#define ENTER_CRITICAL_SECTION()    asm volatile ("di")
#define EXIT_CRITICAL_SECTION()     asm volatile ("ei")

#define    SLAVEID                     {0xAA, 0xBB, 0xCC}
#define    SLAVEID_LENGTH              3

typedef bool BOOL;

typedef unsigned char UCHAR;
typedef char CHAR;

typedef uint16_t USHORT;
typedef int16_t SHORT;

typedef uint32_t ULONG;
typedef int32_t LONG;

#ifndef TRUE
#define TRUE            true
#endif

#ifndef FALSE
#define FALSE           false
#endif

#endif