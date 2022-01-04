#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/crc.c src/driver/eeprom/eeprom.c src/driver/io/io.c src/driver/modbus/ascii/mbascii.c src/driver/modbus/functions/mbfunccoils.c src/driver/modbus/functions/mbfuncdiag.c src/driver/modbus/functions/mbfuncdisc.c src/driver/modbus/functions/mbfuncholding.c src/driver/modbus/functions/mbfuncinput.c src/driver/modbus/functions/mbfuncother.c src/driver/modbus/functions/mbutils.c src/driver/modbus/rtu/mbcrc.c src/driver/modbus/rtu/mbrtu.c src/driver/modbus/tcp/mbtcp.c src/driver/modbus/mb.c src/driver/pid/pid.c src/port/eeprom/hardware.c src/port/io/discrete.c src/port/io/analog.c src/port/modbus/event.c src/port/modbus/serial.c src/port/modbus/timer.c src/port/modbus/data.c src/port/pid/timer.c src/main.c src/configuration_bits.c src/system.c src/qei.c src/pwm.c src/capture.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/crc.o ${OBJECTDIR}/src/driver/eeprom/eeprom.o ${OBJECTDIR}/src/driver/io/io.o ${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o ${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o ${OBJECTDIR}/src/driver/modbus/functions/mbutils.o ${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o ${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o ${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o ${OBJECTDIR}/src/driver/modbus/mb.o ${OBJECTDIR}/src/driver/pid/pid.o ${OBJECTDIR}/src/port/eeprom/hardware.o ${OBJECTDIR}/src/port/io/discrete.o ${OBJECTDIR}/src/port/io/analog.o ${OBJECTDIR}/src/port/modbus/event.o ${OBJECTDIR}/src/port/modbus/serial.o ${OBJECTDIR}/src/port/modbus/timer.o ${OBJECTDIR}/src/port/modbus/data.o ${OBJECTDIR}/src/port/pid/timer.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/configuration_bits.o ${OBJECTDIR}/src/system.o ${OBJECTDIR}/src/qei.o ${OBJECTDIR}/src/pwm.o ${OBJECTDIR}/src/capture.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/crc.o.d ${OBJECTDIR}/src/driver/eeprom/eeprom.o.d ${OBJECTDIR}/src/driver/io/io.o.d ${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o.d ${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o.d ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o.d ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o.d ${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o.d ${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o.d ${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o.d ${OBJECTDIR}/src/driver/modbus/functions/mbutils.o.d ${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o.d ${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o.d ${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o.d ${OBJECTDIR}/src/driver/modbus/mb.o.d ${OBJECTDIR}/src/driver/pid/pid.o.d ${OBJECTDIR}/src/port/eeprom/hardware.o.d ${OBJECTDIR}/src/port/io/discrete.o.d ${OBJECTDIR}/src/port/io/analog.o.d ${OBJECTDIR}/src/port/modbus/event.o.d ${OBJECTDIR}/src/port/modbus/serial.o.d ${OBJECTDIR}/src/port/modbus/timer.o.d ${OBJECTDIR}/src/port/modbus/data.o.d ${OBJECTDIR}/src/port/pid/timer.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/configuration_bits.o.d ${OBJECTDIR}/src/system.o.d ${OBJECTDIR}/src/qei.o.d ${OBJECTDIR}/src/pwm.o.d ${OBJECTDIR}/src/capture.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/crc.o ${OBJECTDIR}/src/driver/eeprom/eeprom.o ${OBJECTDIR}/src/driver/io/io.o ${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o ${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o ${OBJECTDIR}/src/driver/modbus/functions/mbutils.o ${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o ${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o ${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o ${OBJECTDIR}/src/driver/modbus/mb.o ${OBJECTDIR}/src/driver/pid/pid.o ${OBJECTDIR}/src/port/eeprom/hardware.o ${OBJECTDIR}/src/port/io/discrete.o ${OBJECTDIR}/src/port/io/analog.o ${OBJECTDIR}/src/port/modbus/event.o ${OBJECTDIR}/src/port/modbus/serial.o ${OBJECTDIR}/src/port/modbus/timer.o ${OBJECTDIR}/src/port/modbus/data.o ${OBJECTDIR}/src/port/pid/timer.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/configuration_bits.o ${OBJECTDIR}/src/system.o ${OBJECTDIR}/src/qei.o ${OBJECTDIR}/src/pwm.o ${OBJECTDIR}/src/capture.o

# Source Files
SOURCEFILES=src/crc.c src/driver/eeprom/eeprom.c src/driver/io/io.c src/driver/modbus/ascii/mbascii.c src/driver/modbus/functions/mbfunccoils.c src/driver/modbus/functions/mbfuncdiag.c src/driver/modbus/functions/mbfuncdisc.c src/driver/modbus/functions/mbfuncholding.c src/driver/modbus/functions/mbfuncinput.c src/driver/modbus/functions/mbfuncother.c src/driver/modbus/functions/mbutils.c src/driver/modbus/rtu/mbcrc.c src/driver/modbus/rtu/mbrtu.c src/driver/modbus/tcp/mbtcp.c src/driver/modbus/mb.c src/driver/pid/pid.c src/port/eeprom/hardware.c src/port/io/discrete.c src/port/io/analog.c src/port/modbus/event.c src/port/modbus/serial.c src/port/modbus/timer.c src/port/modbus/data.c src/port/pid/timer.c src/main.c src/configuration_bits.c src/system.c src/qei.c src/pwm.c src/capture.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/SC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MK1024MCF064
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/crc.o: src/crc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/crc.o.d 
	@${RM} ${OBJECTDIR}/src/crc.o 
	@${FIXDEPS} "${OBJECTDIR}/src/crc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/crc.o.d" -o ${OBJECTDIR}/src/crc.o src/crc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/eeprom/eeprom.o: src/driver/eeprom/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/eeprom" 
	@${RM} ${OBJECTDIR}/src/driver/eeprom/eeprom.o.d 
	@${RM} ${OBJECTDIR}/src/driver/eeprom/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/eeprom/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/eeprom/eeprom.o.d" -o ${OBJECTDIR}/src/driver/eeprom/eeprom.o src/driver/eeprom/eeprom.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/io/io.o: src/driver/io/io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/io" 
	@${RM} ${OBJECTDIR}/src/driver/io/io.o.d 
	@${RM} ${OBJECTDIR}/src/driver/io/io.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/io/io.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/io/io.o.d" -o ${OBJECTDIR}/src/driver/io/io.o src/driver/io/io.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o: src/driver/modbus/ascii/mbascii.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/ascii" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o.d" -o ${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o src/driver/modbus/ascii/mbascii.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o: src/driver/modbus/functions/mbfunccoils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o src/driver/modbus/functions/mbfunccoils.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o: src/driver/modbus/functions/mbfuncdiag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o src/driver/modbus/functions/mbfuncdiag.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o: src/driver/modbus/functions/mbfuncdisc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o src/driver/modbus/functions/mbfuncdisc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o: src/driver/modbus/functions/mbfuncholding.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o src/driver/modbus/functions/mbfuncholding.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o: src/driver/modbus/functions/mbfuncinput.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o src/driver/modbus/functions/mbfuncinput.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o: src/driver/modbus/functions/mbfuncother.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o src/driver/modbus/functions/mbfuncother.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbutils.o: src/driver/modbus/functions/mbutils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbutils.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbutils.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbutils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbutils.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbutils.o src/driver/modbus/functions/mbutils.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o: src/driver/modbus/rtu/mbcrc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/rtu" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o.d" -o ${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o src/driver/modbus/rtu/mbcrc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o: src/driver/modbus/rtu/mbrtu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/rtu" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o.d" -o ${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o src/driver/modbus/rtu/mbrtu.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o: src/driver/modbus/tcp/mbtcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/tcp" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o.d" -o ${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o src/driver/modbus/tcp/mbtcp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/mb.o: src/driver/modbus/mb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/mb.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/mb.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/mb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/mb.o.d" -o ${OBJECTDIR}/src/driver/modbus/mb.o src/driver/modbus/mb.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/pid/pid.o: src/driver/pid/pid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/pid" 
	@${RM} ${OBJECTDIR}/src/driver/pid/pid.o.d 
	@${RM} ${OBJECTDIR}/src/driver/pid/pid.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/pid/pid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/pid/pid.o.d" -o ${OBJECTDIR}/src/driver/pid/pid.o src/driver/pid/pid.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/eeprom/hardware.o: src/port/eeprom/hardware.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/eeprom" 
	@${RM} ${OBJECTDIR}/src/port/eeprom/hardware.o.d 
	@${RM} ${OBJECTDIR}/src/port/eeprom/hardware.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/eeprom/hardware.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/eeprom/hardware.o.d" -o ${OBJECTDIR}/src/port/eeprom/hardware.o src/port/eeprom/hardware.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/io/discrete.o: src/port/io/discrete.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/io" 
	@${RM} ${OBJECTDIR}/src/port/io/discrete.o.d 
	@${RM} ${OBJECTDIR}/src/port/io/discrete.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/io/discrete.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/io/discrete.o.d" -o ${OBJECTDIR}/src/port/io/discrete.o src/port/io/discrete.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/io/analog.o: src/port/io/analog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/io" 
	@${RM} ${OBJECTDIR}/src/port/io/analog.o.d 
	@${RM} ${OBJECTDIR}/src/port/io/analog.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/io/analog.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/io/analog.o.d" -o ${OBJECTDIR}/src/port/io/analog.o src/port/io/analog.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/modbus/event.o: src/port/modbus/event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/modbus" 
	@${RM} ${OBJECTDIR}/src/port/modbus/event.o.d 
	@${RM} ${OBJECTDIR}/src/port/modbus/event.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/modbus/event.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/modbus/event.o.d" -o ${OBJECTDIR}/src/port/modbus/event.o src/port/modbus/event.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/modbus/serial.o: src/port/modbus/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/modbus" 
	@${RM} ${OBJECTDIR}/src/port/modbus/serial.o.d 
	@${RM} ${OBJECTDIR}/src/port/modbus/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/modbus/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/modbus/serial.o.d" -o ${OBJECTDIR}/src/port/modbus/serial.o src/port/modbus/serial.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/modbus/timer.o: src/port/modbus/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/modbus" 
	@${RM} ${OBJECTDIR}/src/port/modbus/timer.o.d 
	@${RM} ${OBJECTDIR}/src/port/modbus/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/modbus/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/modbus/timer.o.d" -o ${OBJECTDIR}/src/port/modbus/timer.o src/port/modbus/timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/modbus/data.o: src/port/modbus/data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/modbus" 
	@${RM} ${OBJECTDIR}/src/port/modbus/data.o.d 
	@${RM} ${OBJECTDIR}/src/port/modbus/data.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/modbus/data.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/modbus/data.o.d" -o ${OBJECTDIR}/src/port/modbus/data.o src/port/modbus/data.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/pid/timer.o: src/port/pid/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/pid" 
	@${RM} ${OBJECTDIR}/src/port/pid/timer.o.d 
	@${RM} ${OBJECTDIR}/src/port/pid/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/pid/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/pid/timer.o.d" -o ${OBJECTDIR}/src/port/pid/timer.o src/port/pid/timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	@${FIXDEPS} "${OBJECTDIR}/src/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/configuration_bits.o: src/configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/src/configuration_bits.o 
	@${FIXDEPS} "${OBJECTDIR}/src/configuration_bits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/configuration_bits.o.d" -o ${OBJECTDIR}/src/configuration_bits.o src/configuration_bits.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/system.o: src/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/system.o.d 
	@${RM} ${OBJECTDIR}/src/system.o 
	@${FIXDEPS} "${OBJECTDIR}/src/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/system.o.d" -o ${OBJECTDIR}/src/system.o src/system.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/qei.o: src/qei.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/qei.o.d 
	@${RM} ${OBJECTDIR}/src/qei.o 
	@${FIXDEPS} "${OBJECTDIR}/src/qei.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/qei.o.d" -o ${OBJECTDIR}/src/qei.o src/qei.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/src/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/pwm.o.d" -o ${OBJECTDIR}/src/pwm.o src/pwm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/capture.o: src/capture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/capture.o.d 
	@${RM} ${OBJECTDIR}/src/capture.o 
	@${FIXDEPS} "${OBJECTDIR}/src/capture.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/capture.o.d" -o ${OBJECTDIR}/src/capture.o src/capture.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/crc.o: src/crc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/crc.o.d 
	@${RM} ${OBJECTDIR}/src/crc.o 
	@${FIXDEPS} "${OBJECTDIR}/src/crc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/crc.o.d" -o ${OBJECTDIR}/src/crc.o src/crc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/eeprom/eeprom.o: src/driver/eeprom/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/eeprom" 
	@${RM} ${OBJECTDIR}/src/driver/eeprom/eeprom.o.d 
	@${RM} ${OBJECTDIR}/src/driver/eeprom/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/eeprom/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/eeprom/eeprom.o.d" -o ${OBJECTDIR}/src/driver/eeprom/eeprom.o src/driver/eeprom/eeprom.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/io/io.o: src/driver/io/io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/io" 
	@${RM} ${OBJECTDIR}/src/driver/io/io.o.d 
	@${RM} ${OBJECTDIR}/src/driver/io/io.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/io/io.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/io/io.o.d" -o ${OBJECTDIR}/src/driver/io/io.o src/driver/io/io.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o: src/driver/modbus/ascii/mbascii.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/ascii" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o.d" -o ${OBJECTDIR}/src/driver/modbus/ascii/mbascii.o src/driver/modbus/ascii/mbascii.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o: src/driver/modbus/functions/mbfunccoils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfunccoils.o src/driver/modbus/functions/mbfunccoils.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o: src/driver/modbus/functions/mbfuncdiag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdiag.o src/driver/modbus/functions/mbfuncdiag.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o: src/driver/modbus/functions/mbfuncdisc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncdisc.o src/driver/modbus/functions/mbfuncdisc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o: src/driver/modbus/functions/mbfuncholding.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncholding.o src/driver/modbus/functions/mbfuncholding.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o: src/driver/modbus/functions/mbfuncinput.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncinput.o src/driver/modbus/functions/mbfuncinput.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o: src/driver/modbus/functions/mbfuncother.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbfuncother.o src/driver/modbus/functions/mbfuncother.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/functions/mbutils.o: src/driver/modbus/functions/mbutils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/functions" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbutils.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/functions/mbutils.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/functions/mbutils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/functions/mbutils.o.d" -o ${OBJECTDIR}/src/driver/modbus/functions/mbutils.o src/driver/modbus/functions/mbutils.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o: src/driver/modbus/rtu/mbcrc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/rtu" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o.d" -o ${OBJECTDIR}/src/driver/modbus/rtu/mbcrc.o src/driver/modbus/rtu/mbcrc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o: src/driver/modbus/rtu/mbrtu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/rtu" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o.d" -o ${OBJECTDIR}/src/driver/modbus/rtu/mbrtu.o src/driver/modbus/rtu/mbrtu.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o: src/driver/modbus/tcp/mbtcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus/tcp" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o.d" -o ${OBJECTDIR}/src/driver/modbus/tcp/mbtcp.o src/driver/modbus/tcp/mbtcp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/modbus/mb.o: src/driver/modbus/mb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/modbus" 
	@${RM} ${OBJECTDIR}/src/driver/modbus/mb.o.d 
	@${RM} ${OBJECTDIR}/src/driver/modbus/mb.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/modbus/mb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/modbus/mb.o.d" -o ${OBJECTDIR}/src/driver/modbus/mb.o src/driver/modbus/mb.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/driver/pid/pid.o: src/driver/pid/pid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/driver/pid" 
	@${RM} ${OBJECTDIR}/src/driver/pid/pid.o.d 
	@${RM} ${OBJECTDIR}/src/driver/pid/pid.o 
	@${FIXDEPS} "${OBJECTDIR}/src/driver/pid/pid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/driver/pid/pid.o.d" -o ${OBJECTDIR}/src/driver/pid/pid.o src/driver/pid/pid.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/eeprom/hardware.o: src/port/eeprom/hardware.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/eeprom" 
	@${RM} ${OBJECTDIR}/src/port/eeprom/hardware.o.d 
	@${RM} ${OBJECTDIR}/src/port/eeprom/hardware.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/eeprom/hardware.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/eeprom/hardware.o.d" -o ${OBJECTDIR}/src/port/eeprom/hardware.o src/port/eeprom/hardware.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/io/discrete.o: src/port/io/discrete.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/io" 
	@${RM} ${OBJECTDIR}/src/port/io/discrete.o.d 
	@${RM} ${OBJECTDIR}/src/port/io/discrete.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/io/discrete.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/io/discrete.o.d" -o ${OBJECTDIR}/src/port/io/discrete.o src/port/io/discrete.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/io/analog.o: src/port/io/analog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/io" 
	@${RM} ${OBJECTDIR}/src/port/io/analog.o.d 
	@${RM} ${OBJECTDIR}/src/port/io/analog.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/io/analog.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/io/analog.o.d" -o ${OBJECTDIR}/src/port/io/analog.o src/port/io/analog.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/modbus/event.o: src/port/modbus/event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/modbus" 
	@${RM} ${OBJECTDIR}/src/port/modbus/event.o.d 
	@${RM} ${OBJECTDIR}/src/port/modbus/event.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/modbus/event.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/modbus/event.o.d" -o ${OBJECTDIR}/src/port/modbus/event.o src/port/modbus/event.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/modbus/serial.o: src/port/modbus/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/modbus" 
	@${RM} ${OBJECTDIR}/src/port/modbus/serial.o.d 
	@${RM} ${OBJECTDIR}/src/port/modbus/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/modbus/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/modbus/serial.o.d" -o ${OBJECTDIR}/src/port/modbus/serial.o src/port/modbus/serial.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/modbus/timer.o: src/port/modbus/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/modbus" 
	@${RM} ${OBJECTDIR}/src/port/modbus/timer.o.d 
	@${RM} ${OBJECTDIR}/src/port/modbus/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/modbus/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/modbus/timer.o.d" -o ${OBJECTDIR}/src/port/modbus/timer.o src/port/modbus/timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/modbus/data.o: src/port/modbus/data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/modbus" 
	@${RM} ${OBJECTDIR}/src/port/modbus/data.o.d 
	@${RM} ${OBJECTDIR}/src/port/modbus/data.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/modbus/data.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/modbus/data.o.d" -o ${OBJECTDIR}/src/port/modbus/data.o src/port/modbus/data.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/port/pid/timer.o: src/port/pid/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src/port/pid" 
	@${RM} ${OBJECTDIR}/src/port/pid/timer.o.d 
	@${RM} ${OBJECTDIR}/src/port/pid/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/src/port/pid/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/port/pid/timer.o.d" -o ${OBJECTDIR}/src/port/pid/timer.o src/port/pid/timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/main.o: src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	@${FIXDEPS} "${OBJECTDIR}/src/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/configuration_bits.o: src/configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/src/configuration_bits.o 
	@${FIXDEPS} "${OBJECTDIR}/src/configuration_bits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/configuration_bits.o.d" -o ${OBJECTDIR}/src/configuration_bits.o src/configuration_bits.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/system.o: src/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/system.o.d 
	@${RM} ${OBJECTDIR}/src/system.o 
	@${FIXDEPS} "${OBJECTDIR}/src/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/system.o.d" -o ${OBJECTDIR}/src/system.o src/system.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/qei.o: src/qei.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/qei.o.d 
	@${RM} ${OBJECTDIR}/src/qei.o 
	@${FIXDEPS} "${OBJECTDIR}/src/qei.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/qei.o.d" -o ${OBJECTDIR}/src/qei.o src/qei.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/src/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/pwm.o.d" -o ${OBJECTDIR}/src/pwm.o src/pwm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/capture.o: src/capture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/capture.o.d 
	@${RM} ${OBJECTDIR}/src/capture.o 
	@${FIXDEPS} "${OBJECTDIR}/src/capture.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"src" -I"src/driver" -I"src/port" -MMD -MF "${OBJECTDIR}/src/capture.o.d" -o ${OBJECTDIR}/src/capture.o src/capture.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/SC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/SC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x36F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/SC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/SC.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/SC.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
