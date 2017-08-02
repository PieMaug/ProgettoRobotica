#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=None-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/MotionControl_v6/absolute_rotation.o \
	${OBJECTDIR}/MotionControl_v6/can_interface.o \
	${OBJECTDIR}/MotionControl_v6/circ_rotation.o \
	${OBJECTDIR}/MotionControl_v6/clocking.o \
	${OBJECTDIR}/MotionControl_v6/follow_line.o \
	${OBJECTDIR}/MotionControl_v6/geometry.o \
	${OBJECTDIR}/MotionControl_v6/goto_point.o \
	${OBJECTDIR}/MotionControl_v6/kinematics.o \
	${OBJECTDIR}/MotionControl_v6/main.o \
	${OBJECTDIR}/MotionControl_v6/path_control.o \
	${OBJECTDIR}/MotionControl_v6/pwm.o \
	${OBJECTDIR}/MotionControl_v6/qei.o \
	${OBJECTDIR}/MotionControl_v6/relative_rotation.o \
	${OBJECTDIR}/MotionControl_v6/speed_control.o \
	${OBJECTDIR}/MotionControl_v6/timers.o \
	${OBJECTDIR}/libs/controllib/chebyshev.o \
	${OBJECTDIR}/libs/controllib/low_pass.o \
	${OBJECTDIR}/libs/controllib/periodic_task.o \
	${OBJECTDIR}/libs/controllib/pid.o \
	${OBJECTDIR}/libs/timer/SoftTimer.o \
	${OBJECTDIR}/libs/timer/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/progettorobotica.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/progettorobotica.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/progettorobotica ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/MotionControl_v6/absolute_rotation.o: MotionControl_v6/absolute_rotation.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/absolute_rotation.o MotionControl_v6/absolute_rotation.cpp

${OBJECTDIR}/MotionControl_v6/can_interface.o: MotionControl_v6/can_interface.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/can_interface.o MotionControl_v6/can_interface.cpp

${OBJECTDIR}/MotionControl_v6/circ_rotation.o: MotionControl_v6/circ_rotation.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/circ_rotation.o MotionControl_v6/circ_rotation.cpp

${OBJECTDIR}/MotionControl_v6/clocking.o: MotionControl_v6/clocking.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/clocking.o MotionControl_v6/clocking.cpp

${OBJECTDIR}/MotionControl_v6/follow_line.o: MotionControl_v6/follow_line.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/follow_line.o MotionControl_v6/follow_line.cpp

${OBJECTDIR}/MotionControl_v6/geometry.o: MotionControl_v6/geometry.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/geometry.o MotionControl_v6/geometry.cpp

${OBJECTDIR}/MotionControl_v6/goto_point.o: MotionControl_v6/goto_point.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/goto_point.o MotionControl_v6/goto_point.cpp

${OBJECTDIR}/MotionControl_v6/kinematics.o: MotionControl_v6/kinematics.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/kinematics.o MotionControl_v6/kinematics.cpp

${OBJECTDIR}/MotionControl_v6/main.o: MotionControl_v6/main.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/main.o MotionControl_v6/main.cpp

${OBJECTDIR}/MotionControl_v6/path_control.o: MotionControl_v6/path_control.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/path_control.o MotionControl_v6/path_control.cpp

${OBJECTDIR}/MotionControl_v6/pwm.o: MotionControl_v6/pwm.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/pwm.o MotionControl_v6/pwm.cpp

${OBJECTDIR}/MotionControl_v6/qei.o: MotionControl_v6/qei.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/qei.o MotionControl_v6/qei.cpp

${OBJECTDIR}/MotionControl_v6/relative_rotation.o: MotionControl_v6/relative_rotation.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/relative_rotation.o MotionControl_v6/relative_rotation.cpp

${OBJECTDIR}/MotionControl_v6/speed_control.o: MotionControl_v6/speed_control.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/speed_control.o MotionControl_v6/speed_control.cpp

${OBJECTDIR}/MotionControl_v6/timers.o: MotionControl_v6/timers.cpp
	${MKDIR} -p ${OBJECTDIR}/MotionControl_v6
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MotionControl_v6/timers.o MotionControl_v6/timers.cpp

${OBJECTDIR}/libs/controllib/chebyshev.o: libs/controllib/chebyshev.cpp
	${MKDIR} -p ${OBJECTDIR}/libs/controllib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/libs/controllib/chebyshev.o libs/controllib/chebyshev.cpp

${OBJECTDIR}/libs/controllib/low_pass.o: libs/controllib/low_pass.cpp
	${MKDIR} -p ${OBJECTDIR}/libs/controllib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/libs/controllib/low_pass.o libs/controllib/low_pass.cpp

${OBJECTDIR}/libs/controllib/periodic_task.o: libs/controllib/periodic_task.cpp
	${MKDIR} -p ${OBJECTDIR}/libs/controllib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/libs/controllib/periodic_task.o libs/controllib/periodic_task.cpp

${OBJECTDIR}/libs/controllib/pid.o: libs/controllib/pid.cpp
	${MKDIR} -p ${OBJECTDIR}/libs/controllib
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/libs/controllib/pid.o libs/controllib/pid.cpp

${OBJECTDIR}/libs/timer/SoftTimer.o: libs/timer/SoftTimer.cpp
	${MKDIR} -p ${OBJECTDIR}/libs/timer
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/libs/timer/SoftTimer.o libs/timer/SoftTimer.cpp

${OBJECTDIR}/libs/timer/main.o: libs/timer/main.cpp
	${MKDIR} -p ${OBJECTDIR}/libs/timer
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/libs/timer/main.o libs/timer/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
