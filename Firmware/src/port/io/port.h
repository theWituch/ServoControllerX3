#ifndef _IOPORT_H
#define _IOPORT_H


#define ANALOG      1
#define DIGITAL     0

#define INPUT       1
#define OUTPUT      0

#define ON       1
#define OFF      0

#define IOPortTYPE_GET(x, y, z)         z = ANSEL##x##bits.ANS##x##y
#define IOPortTYPE_SET(x, y, z)         ANSEL##x##bits.ANS##x##y = z

#define IOPortDIRECTION_GET(x, y, z)    z = TRIS##x##bits.TRIS##x##y
#define IOPortDIRECTION_SET(x, y, z)    TRIS##x##bits.TRIS##x##y = z

#define IOPortSTATE_GET(x, y, z)        z = ~PORT##x##bits.R##x##y
#define IOPortSTATE_SET(x, y, z)        LAT##x##bits.LAT##x##y = z

#endif