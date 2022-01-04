#include <xc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#include "system.h
#include "eeprom.h

#include "pid.h


struct PID pidCopy;

void clear_EE( void );


// we need to pull some tricks to get it all done
// structure with all setup constants that is stored in eeprom
// aligned on 32 byte boundary
// seed eeprom with a few default values
//struct PID _EEDATA(32) pidEE2={0.0};
struct PID  pidEE = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100, 1, 2};




//=============================================================================
// Routine to clear eeprom
//
//=============================================================================
void clear_EE( void )
{
    _erase_eedata_all();
    _wait_eedata();
}

//=============================================================================
// Routine to save setup structure into eeprom
//
//=============================================================================
int save_setup( void )
{
    int size = sizeof(pid);
    int *sptr = (int *)&pidCopy;
    int res;
    int offset = 0;
    _prog_addressT p;
      /* method 1 */
      _init_prog_address(p, pidEE);

    memcpy(&pidCopy, &pid, sizeof(pid));

    // compute correct checksum for upper part of array
    // and place it in the checsum variable
    pidCopy.cksum = calc_cksum((sizeof(pid))/sizeof(int),
                             (int*)&pidCopy);

    // this routine attempts to write the entire ram setup structure
    // into the eeprom on board.
    // write 16 words of structure at a time

    clear_EE();

    while (size > 0)
    {

        res = WriteEE(sptr, __builtin_tblpage(&pidEE),
                            __builtin_tbloffset(&pidEE)+offset, ROW);

        //_write_eedata_row(p, (int*) &pid
        if (res)
            printf("write to eeprom failed at offset %d\r\n",offset);

        offset += ROW*2;            // bump offset to destination 32 bytes up
        sptr   += ROW;            // bump source ptr up 16 words
        size   -= ROW*2;        // 16 words or 32 bytes/write
        _wait_eedata();
    }
    eeprom_write_block;

    return res;
}

//=============================================================================
//  routine to restore setup data
//
//=============================================================================
int restore_setup( void )
{
    return 0;
}