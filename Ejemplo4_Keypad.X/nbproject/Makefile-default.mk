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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo4_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo4_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Configuracion.c Main_Keypad.c Keypad_dsPIC.c LCD_dspic.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Configuracion.o ${OBJECTDIR}/Main_Keypad.o ${OBJECTDIR}/Keypad_dsPIC.o ${OBJECTDIR}/LCD_dspic.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Configuracion.o.d ${OBJECTDIR}/Main_Keypad.o.d ${OBJECTDIR}/Keypad_dsPIC.o.d ${OBJECTDIR}/LCD_dspic.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Configuracion.o ${OBJECTDIR}/Main_Keypad.o ${OBJECTDIR}/Keypad_dsPIC.o ${OBJECTDIR}/LCD_dspic.o

# Source Files
SOURCEFILES=Configuracion.c Main_Keypad.c Keypad_dsPIC.c LCD_dspic.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo4_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ32MC202
MP_LINKER_FILE_OPTION=,--script=p33FJ32MC202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Configuracion.o: Configuracion.c  .generated_files/flags/default/fc88887feac0e14147ebe100a2002e0720cd5c2f .generated_files/flags/default/b2871fc5c40dac04fec5588c1c3986c6f6b8f11e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Configuracion.o.d 
	@${RM} ${OBJECTDIR}/Configuracion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Configuracion.c  -o ${OBJECTDIR}/Configuracion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Configuracion.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Main_Keypad.o: Main_Keypad.c  .generated_files/flags/default/9278d3be20d55283c22c37af85736abd285058d2 .generated_files/flags/default/b2871fc5c40dac04fec5588c1c3986c6f6b8f11e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Main_Keypad.o.d 
	@${RM} ${OBJECTDIR}/Main_Keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Main_Keypad.c  -o ${OBJECTDIR}/Main_Keypad.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Main_Keypad.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Keypad_dsPIC.o: Keypad_dsPIC.c  .generated_files/flags/default/12a0a56839d67a9b3f2a181922ead3cc66295bd3 .generated_files/flags/default/b2871fc5c40dac04fec5588c1c3986c6f6b8f11e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Keypad_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/Keypad_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Keypad_dsPIC.c  -o ${OBJECTDIR}/Keypad_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Keypad_dsPIC.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/LCD_dspic.o: LCD_dspic.c  .generated_files/flags/default/ae8bbe88ffb64254f14c6f015e59e2121fdc7273 .generated_files/flags/default/b2871fc5c40dac04fec5588c1c3986c6f6b8f11e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_dspic.o.d 
	@${RM} ${OBJECTDIR}/LCD_dspic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LCD_dspic.c  -o ${OBJECTDIR}/LCD_dspic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/LCD_dspic.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/Configuracion.o: Configuracion.c  .generated_files/flags/default/b15e34b29557bb64bff49f615f375ad01a3bf85a .generated_files/flags/default/b2871fc5c40dac04fec5588c1c3986c6f6b8f11e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Configuracion.o.d 
	@${RM} ${OBJECTDIR}/Configuracion.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Configuracion.c  -o ${OBJECTDIR}/Configuracion.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Configuracion.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Main_Keypad.o: Main_Keypad.c  .generated_files/flags/default/629dcfa5079a9b0648d6fca45f73202adb56e0d5 .generated_files/flags/default/b2871fc5c40dac04fec5588c1c3986c6f6b8f11e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Main_Keypad.o.d 
	@${RM} ${OBJECTDIR}/Main_Keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Main_Keypad.c  -o ${OBJECTDIR}/Main_Keypad.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Main_Keypad.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/Keypad_dsPIC.o: Keypad_dsPIC.c  .generated_files/flags/default/471929642fad9cfbea07bf2a01b93b5093e14213 .generated_files/flags/default/b2871fc5c40dac04fec5588c1c3986c6f6b8f11e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Keypad_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/Keypad_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Keypad_dsPIC.c  -o ${OBJECTDIR}/Keypad_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Keypad_dsPIC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/LCD_dspic.o: LCD_dspic.c  .generated_files/flags/default/628923c10f01f83cccd73e91e8a9d34643a5301b .generated_files/flags/default/b2871fc5c40dac04fec5588c1c3986c6f6b8f11e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD_dspic.o.d 
	@${RM} ${OBJECTDIR}/LCD_dspic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LCD_dspic.c  -o ${OBJECTDIR}/LCD_dspic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/LCD_dspic.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo4_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo4_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo4_Keypad.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo4_Keypad.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Ejemplo4_Keypad.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
