/*********************************************************************
 *
 *       Emulating Data EEPROM for PIC32 microcontrollers
 *
 *********************************************************************
 * FileName:        dee_emulation_pic32.h
 * Dependencies:
 * Processor:       PIC32
 *
 * Complier:        MPLAB C32
 *                  MPLAB IDE
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the ?Company?) for its PIC32 Microcontroller is intended
 * and supplied to you, the Company?s customer, for use solely and
 * exclusively on Microchip PIC32 Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN ?AS IS? CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * $Id: $
 *
 **********************************************************************
 * Description:
 *
 *    DataEE  Flash Pages to use.
 *  ---------------------------
 *  The number of Flash pages to use is set by NUM_DATA_EE_PAGES
 *    The code has been tried with from 1 thru 5 Flash pages.
 *
 *    1.    If constants are stored that will not be updated,
 *        the code may be configured and used with only 1 Flash Page.
 *        A maximum of 680 values + updates may be stored.
 *        No further updates are possible after writing 680 values.
 *
 *    2.    When few values, and/or updates are far between,
 *        2 Flash pages may be configured.
 *        Updates may be done.
 *        When number of values + number of updates == 680, a pack
 *        operation is performed, moving the data to the other Page,
 *        one Write/Erase cycle has then been consumed.
 *
 *    3.    Default configuration,
 *        3 Flash memory Pages of 1024 Words, 4096 Bytes each.
 *        Maximum 680 values may be stored with identifiers 0 to 679
 *        may be stored, and 680 updates may be done,
 *        before a pack operation is performed.
 *         1 Write/Erase cycle has then been consumed for 2 pages.
 *
 *    4.    With 4 Pages configured,
 *        an increased maximum DATA_EE_SIZE  1024 may also be defined.
 *        Maximum 1024 values may be stored with identifiers 0 to 1023.
 *        When number of values + number of updates == 1360, a pack
 *        operation is performed, moving the data to 2 other Pages,
 *        one Write/Erase cycle has then been consumed for 2 pages.
 *
 *    5.    If a larger number of updates are expected,
 *        Any number of Flash memory pages,
 *        not needed for program code and constant data,
 *        may be configured for DataEE_Emulation,
 *        to distribute Flash wear as much as possible.
 *
 *      If 1024 values has been stored, and all 1024 values are updated,
 *      the Pack procedure will be performed 3 times,
 *      erasing 6 pages along the way.
 *      If large updates are performed regularly,
 *      a different algorithm may be more suitable.
 *
 *  Fixed address in Flash memory:
 *  ------------------------------
 *  Using __attribute__((address(...), ...
 *  the array storing the data may be located at a fixed address.
 *  Address may be defined by EEDATA_ADDRESS defined below.
 *  On PIC32MX the Flash page size is 4096 bytes, 1024 words of 32 bit.
 *  Thus, the symbol EEDATA_ADDRESS must be aligned a multiple of 0x1000
 *  With the help of settings for the programmer, it is possible
 *  to keep the emulated EEPROM data intact even when the program
 *  is updated.
 *  See the declaration in dee_emulation_pic32.c
 *  and the forum posting:
 *      http://www.microchip.com/forums/fb.ashx?m=758351
 *  The address may need to be changed according to actual hardware.
 *
 *  Verification of dee_emulation data.
 *  -----------------------------------
 *  In the DataEEInit() function, a check of the Flash memory area
 *  is performed. The memory used by dee_emulation_pic32 must contain:
 *  1.  All zero data,
 *      as when the memory has been initialized by the compiler.
 *      The memory pages will be erased and erase counter
 *      for each page incremented.
 *
 *  2.  All 1 bits 0xFFFFFFFF as when erased by flash programming.
 *      Each page will be initialized for use by dee_emulation
 *      without erasing.
 *
 *  3.  Valid dee_emulation data from a previous run.
 *
 *  If the pages contain random data, DataEEInit function will return
 *  an error status. The dataEEFlags structure may contain more information.
 *
 *    Page Status Bits:
 *    -----------------
 *    Page status bits are described in AN1095 and in source code:
 *    PIC32 use one additional page status bit in addition to what is
 *    documented for PIC24.
 *
 *    bit 17     Page Active
 *            = 1 Page not active
 *            = 0 Page Active
 *
 *    bit 18    Page Available
 *            = 1 Page Available
 *            = 0 Page Not available
 *            I have Never seen this bit used on PIC32.
 *
 *    The definition of Current page status bit is different!
 *    PIC32 may have 2 Active pages, of which only 1 is Current.
 *    For this to work, the definition has to be:
 *    bit 19    Page Current
 *            = 1 Page Current
 *            = 0 Page Not current
 *
 *    bit 20    Page Expired
 *            = 1 Page Not expired
 *            = 0 Page Expired
 *
 *    In previous versions of Microchip dee_emulation_pic32.c,
 *  hardcoded bitmasks did not correspond correctly with symbolic
 *  constants for page status bits defined in dee_emulation_pic32.h,
 *    making for some pretty obscure decoding workaround in the
 *    GetPageStatus(...) function.
 *
 *    Timing:
 *    -------
 *    Measurements from PIC32MX at 80 MHz:
 *    Reading 1 word may take from 2 uS to maybe 100 uS.
 *    This is caused by the linear search in the stored data.
 *    As the number of stored items and updates increase,
 *    the time that may be needed to get a particular word will increase.
 *
 *    Writing 1 word may take from 128 uS upwards,
 *    That is maybe 125 uS for the write itself
 *     + whatever time is needed to read the same word.
 *
 *    Attempting to write a word that already has the same value,
 *    only take the time used to read the word. The write is ignored
 *
 *    Packing 680 words seems to use about 128 Milliseconds
 *     + 45 Milliseconds to Erase the two pages,
 *    making a total of 176 Millisecond.
 *    When a Pack operation has been done,
 *    the average time to read should decrease.
 *    But the data with low addresses will take the longest time to read.
 *
 * Change History:
 *  Author          Date        Comment
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  Dave Bell       2013-11-12  address attribute for eedata_addr array.
 *                              See forum: http://www.microchip.com/forums/fb.ashx?m=758351
 *    Arne Bergseth    2013-11-25    Maximum address 1023 with 4 Flash pages.
 *                              1 Flash page minimum configuration.
 *                                Error counter in dataEEFlags structure.
 **********************************************************************/

// User defined constants
#define DATA_EE_SIZE        (1024) // Total maximum number of 32-bit data
#define NUM_DATA_EE_PAGES   (5) // Total number of pages reserved for the operation
#define EEDATA_ADDRESS                  (0x9D0FA000) // Must be aligned a multiple of 0x800 on PIC32MK

// Internal constants
#define ERASE_WRITE_CYCLE_MAX           (1000) // Maximum erase cycle per page
#define NUMBER_OF_INSTRUCTIONS_IN_PAGE  (1024) // Number of 32-bit word instructions per page

#define DATA_OFFSET                     (1360) // The point where address starts
#define PIC32MX_PAGE_SIZE               (NUMBER_OF_INSTRUCTIONS_IN_PAGE*4) // Total page size in bytes

#define NUMBER_OF_INSTRUCTIONS_IN_PAGE  (1024) // number of 32-bit word instructions per page
#define DATA_OFFSET                     (1360) // The point where address starts
#define PIC32MX_PAGE_SIZE               (NUMBER_OF_INSTRUCTIONS_IN_PAGE*4) // Total page size in bytes

#define PAGE_CURRENT                    1 // Indicate the page status
#define PAGE_NOT_CURRENT                0 // Indicate the page status
#define PAGE_EXPIRED                    0 // Indicate the page status
#define PAGE_NOT_EXPIRED                1 // Indicate the page status
#define PAGE_AVAILABLE                  1 // Indicate the page status
#define PAGE_NOT_AVAILABLE              0 // Indicate the page status
#define PAGE_ACTIVE                     0 // Indicate the page status
#define PAGE_NOT_ACTIVE                 1 // Indicate the page status

#define STATUS_ACTIVE                   17 // Indicate the page status
#define STATUS_AVAILABLE                18 // Indicate the page status
#define STATUS_CURRENT                  19 // Indicate the page status
#define STATUS_EXPIRED                  20 // Indicate the page status

//Flags for the error/warning conditions.
typedef union
{
   unsigned int val; // a non-zero value indicate error/warning
   struct
   {
      unsigned addrNotFound:1;       // Return 0x1
      unsigned expiredPage:1;        // Return 0x2
      unsigned packBeforePageFull:1; // Not a return condition
      unsigned packBeforeInit:1;     // Return 0x3
      unsigned packSkipped:1;        // Return 0x4
      unsigned IllegalAddress:1;     // Return 0x5
      unsigned pageCorrupt:1;        // Return 0x6
      unsigned writeError:1;         // Return 0x7
      unsigned lowVoltageError:1;    // Return 0x8
      unsigned checkSumError:1;      // Return 0x9
      unsigned reserved:6;           // Reserved for future use
      unsigned errorCount:16;        // Error counter
   };
} DATA_EE_FLAGS;

extern DATA_EE_FLAGS dataEEFlags; //Flags for the error/warning condition.
#ifdef __DEBUG
extern unsigned int GetPageStatusCount;
extern unsigned int TestCount;
extern volatile unsigned int TickP;
extern volatile unsigned int TickE;
#endif

#define GetaddrNotFound() dataEEFlags.addrNotFound  //Get the flag address not found
#define SetaddrNotFound(x) dataEEFlags.addrNotFound = x // Set the flag address not found

#define GetPageExpiredPage() dataEEFlags.expiredPage  //Get the flag for expired page
#define SetPageExpiredPage(x) dataEEFlags.expiredPage = x // Set the flag for expired page

#define GetPagePackBeforePageFull() dataEEFlags.packBeforePageFull  //Get the flag for pack before page full
#define SetPagePackBeforePageFull(x) dataEEFlags.packBeforePageFull = x //Set the flag for pack before page full

#define GetPagePackBeforeInit() dataEEFlags.packBeforeInit  //Get the flag for pack before initialize
#define SetPagePackBeforeInit(x) dataEEFlags.packBeforeInit = x //Set the flag for pack before initialize

#define GetPagePackSkipped() dataEEFlags.packSkipped //Get the flag pack skipped
#define SetPagePackSkipped(x) dataEEFlags.packSkipped = x //Set the flag pack skipped

#define GetPageIllegalAddress() dataEEFlags.IllegalAddress  //Get the flag for illegal address
#define SetPageIllegalAddress(x) dataEEFlags.IllegalAddress = x //Set the flag for illegal address

#define GetPageCorruptStatus() dataEEFlags.pageCorrupt  //Get the flag page Corrupt
#define SetPageCorruptStatus(x) dataEEFlags.pageCorrupt = x // Set the flag page corrupt

#define GetPageWriteError() dataEEFlags.writeError //Get the flag for write error
#define SetPageWriteError(x) dataEEFlags.writeError = x //Set the flag for write error

#define GetLowVoltageError() dataEEFlags.lowVoltageError//Get the flag for low voltage error
#define SetLowVoltageError(x) dataEEFlags.lowVoltageError = x //Set the flag for low voltage error

#define GetCheckSumError() dataEEFlags.checkSumError  //Get the data verificationError flag
#define SetCheckSumError(x) dataEEFlags.checkSumError = x // Set the verificationError flag


/****************************************************************************
 * Function:        GetNextAvailCount
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          Page offset to next available location
 *
 * Side Effects:    None
 *
 * Overview:        This routine finds the current page and performs a backward search to find
 *                  the first available location. The available location is determined by
 *                  reading a 0xFFFF in the address region. The returned value can be added
 *                  to the first address in page to compute the available address. A return
 *                  value of 0xFFFF means the entire page was filled which is an error condition.
 *                  This routine can be called by the user to determine how full the current
 *                  page is prior to a pack.
 *
 * Note:            This is a public function.
 *****************************************************************************/
unsigned int GetNextAvailCount(void);

/****************************************************************************
 * Function:        DataEEInit
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          Check the dataEEFlags for the error status.
 *                  value 0 for success.
 *                  Value 2 for expired page.
 *                  Value 6 for page corrupt status.
 *                  Value 7 for write error.
 *                  Value 8 for Low voltage operation.
 *                  Value 9 for Checksum error.
 *
 * Side Effects:    Data EE flags may be updated.
 *
 * Overview:        This routine finds an unexpired page to become an active page. It then
 *                  counts the number of active pages. If no active pages are found, the
 *                  first unexpired page is initialized for emulation. If one or two active pages
 *                  found, it assumes a reset occurred and the function does nothing. If
 *                  three active pages are found, it is assumes a reset occurred during a pack.
 *                  The page after current is erased and a pack is called. This
 *                  function must be called prior to any other operation.
 *
 * Note:            This is a public function.
 *****************************************************************************/
unsigned int   DataEEInit(void);

/****************************************************************************
 * Function:        DataEERead
 *
 * PreCondition:    None
 *
 * Input:           Read pointer and Data EE address
 *
 * Output:          Check the dataEEFlags for the error status.
 *                  value 0 for success.
 *                  Value 1 for address not found.
 *                  Value 5 for Illegal address.
 *                  Value 6 for page corrupt status.
 *                  Value 9 for Checksum error.
 *
 * Side Effects:    Data EE flags may be updated.
 *
 * Overview:        This routine verifies whether the address is valid. If not, the Illegal Address
 *                  flag is set and 0 is returned. It then finds the active page. If an
 *                  active page can not be found, the Page Corrupt status bit is set and
 *                  0 is returned. A reverse search of the active page attempts to find
 *                  the matching address in the program memory. If a match is found,
 *                  the corresponding data EEPROM data is returned, otherwise 0
 *                  is returned. This function can be called by the user.
 *
 * Note:            This is a public function.
 *****************************************************************************/
unsigned int DataEERead( int *data, unsigned int addr);

/****************************************************************************
 * Function:        DataEEWrite
 *
 * PreCondition:    None
 *
 * Input:           Data EE address and data
 *
 * Output:          Check the dataEEFlags for the error status.
 *                  value 0 for success.
 *                  Value 2 for expired page.
 *                  Value 4 for pack skipped.
 *                  Value 5 for Illegal address.
 *                  Value 6 for page corrupt status.
 *                  Value 7 for write error.
 *                  Value 8 for Low voltage operation.
 *
 * Side Effects:    Data EE flags may be updated. CPU stall occurs for flash
 *                  programming. Pack may be generated.
 *
 * Overview:        This routine verifies the address is valid. If not, the Illegal Address
 *                  flag is set and an error code is returned. It then finds the active page.
 *                  If an active page can not be found, the Page Corrupt status bit is set
 *                  and an error code is returned. A read is performed, if the data was not
 *                  changed, the function exits. If the last location is programmed, the Pack
 *                  Skipped error flag is set (one location should always be available). The
 *                  data EE information address and data is programmed and verified. The data
 *                  checksum is written along with the address. 10 LSBits are allocated for
 *                  address and 6 bits are allotted for checksum. If the verify fails,
 *                  the Write Error flag is set. If the write went into the last location
 *                  of the page, pack is called. This function can be called by the user.
 *
 * Note:            This is a public function.
 *****************************************************************************/
unsigned int DataEEWrite(unsigned int data, unsigned int addr);

/****************************************************************************
 * Function:        PackEE
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          Check the dataEEFlags for the error status.
 *                  value 0 for success.
 *                  Value 6 for page corrupt status.
 *                  Value 7 for write error.
 *                  Value 8 for Low voltage operation.
 *
 * Side Effects:    Generates CPU stall during program/erase operations
 *                  Data EE flags may be updated
 *
 * Overview:        This routine finds the active page and an unexpired packed page. The most
 *                  recent data EEPROM values are located for each address will be read and
 *                  written into pack page. Page status is read from active
 *                  page and erase/write count is incremented if page 0 is packed. After all
 *                  information is programmed and verified, the current page is erased. The
 *                  packed page becomes the current page. This function can be called at any-
 *                  time by the user to schedule the CPU stall.
 *
 * Note:            This is a public function.
 *****************************************************************************/
unsigned int PackEE(void);

/****************************************************************************
 * Function:        DataEEWriteArray
 *
 * PreCondition:    None
 *
 * Input:           char array pointer, address to be started and the size of array
 *
 * Output:          Check the dataEEFlags for the error status.
 *                  value 0 for success.
 *                  Value 2 for expired page.
 *                  Value 4 for pack skipped.
 *                  Value 5 for Illegal address.
 *                  Value 6 for page corrupt status.
 *                  Value 7 for write error.
 *                  Value 8 for Low voltage operation.
 *
 * Side Effects:    Data EE flags may be updated. CPU stall occurs for flash
 *                  programming. Pack may be generated.
 *
 * Overview:        This routine will write a char array of data with a given
 *                  starting address upto the array size specified by the user.
 *                  Use DataEEWriteArray function to read the data written using this function
 *                  This is solely designed to write char array.
 *
 * Note:            This is a public function.
 *****************************************************************************/
unsigned int DataEEWriteArray(unsigned char *data, unsigned int addr, unsigned int size);

/****************************************************************************
 * Function:        DataEEReadArray
 *
 * PreCondition:    None
 *
 * Input:           data pointer, address to be started and the size of array
 *
 * Output:          Check the dataEEFlags for the error status.
 *                  value 0 for success.
 *                  Value 1 for address not found.
 *                  Value 5 for Illegal address.
 *                  Value 6 for page corrupt status.
 *
 * Side Effects:    Data EE flags may be updated. Reading the data in between the
 *                  array address will cause incorrect data return.
 *
 * Overview:        This function will read a byte array of values starting from addr
 *                  and will copy to the array pointer "data". User should read the
 *                  data from the starting address of the array.
 *
 * Note:            This is a public function.
 *****************************************************************************/
unsigned int DataEEReadArray(unsigned char *data, unsigned int addr, unsigned int size);

