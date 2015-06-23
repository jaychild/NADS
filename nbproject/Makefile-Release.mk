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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AddNodeState.o \
	${OBJECTDIR}/AllDevicesState.o \
	${OBJECTDIR}/AllNodes.o \
	${OBJECTDIR}/Controller.o \
	${OBJECTDIR}/EndState.o \
	${OBJECTDIR}/ErrorMessager.o \
	${OBJECTDIR}/FileManager.o \
	${OBJECTDIR}/HelpState.o \
	${OBJECTDIR}/LiveState.o \
	${OBJECTDIR}/MenuState.o \
	${OBJECTDIR}/MonitorState.o \
	${OBJECTDIR}/NetworkTester.o \
	${OBJECTDIR}/NetworkTesterState.o \
	${OBJECTDIR}/Node.o \
	${OBJECTDIR}/Observer.o \
	${OBJECTDIR}/Ping.o \
	${OBJECTDIR}/PingObservable.o \
	${OBJECTDIR}/RemoveNodeState.o \
	${OBJECTDIR}/RunIO.o \
	${OBJECTDIR}/SaveState.o \
	${OBJECTDIR}/StatStates.o \
	${OBJECTDIR}/StateInterface.o \
	${OBJECTDIR}/Statistics.o \
	${OBJECTDIR}/TimeStamp.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nrd_proto_8

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nrd_proto_8: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nrd_proto_8 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/AddNodeState.o: AddNodeState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AddNodeState.o AddNodeState.cpp

${OBJECTDIR}/AllDevicesState.o: AllDevicesState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AllDevicesState.o AllDevicesState.cpp

${OBJECTDIR}/AllNodes.o: AllNodes.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AllNodes.o AllNodes.cpp

${OBJECTDIR}/Controller.o: Controller.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Controller.o Controller.cpp

${OBJECTDIR}/EndState.o: EndState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EndState.o EndState.cpp

${OBJECTDIR}/ErrorMessager.o: ErrorMessager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ErrorMessager.o ErrorMessager.cpp

${OBJECTDIR}/FileManager.o: FileManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FileManager.o FileManager.cpp

${OBJECTDIR}/HelpState.o: HelpState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HelpState.o HelpState.cpp

${OBJECTDIR}/LiveState.o: LiveState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LiveState.o LiveState.cpp

${OBJECTDIR}/MenuState.o: MenuState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MenuState.o MenuState.cpp

${OBJECTDIR}/MonitorState.o: MonitorState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MonitorState.o MonitorState.cpp

${OBJECTDIR}/NetworkTester.o: NetworkTester.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NetworkTester.o NetworkTester.cpp

${OBJECTDIR}/NetworkTesterState.o: NetworkTesterState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NetworkTesterState.o NetworkTesterState.cpp

${OBJECTDIR}/Node.o: Node.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Node.o Node.cpp

${OBJECTDIR}/Observer.o: Observer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Observer.o Observer.cpp

${OBJECTDIR}/Ping.o: Ping.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ping.o Ping.cpp

${OBJECTDIR}/PingObservable.o: PingObservable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PingObservable.o PingObservable.cpp

${OBJECTDIR}/RemoveNodeState.o: RemoveNodeState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RemoveNodeState.o RemoveNodeState.cpp

${OBJECTDIR}/RunIO.o: RunIO.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RunIO.o RunIO.cpp

${OBJECTDIR}/SaveState.o: SaveState.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SaveState.o SaveState.cpp

${OBJECTDIR}/StatStates.o: StatStates.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StatStates.o StatStates.cpp

${OBJECTDIR}/StateInterface.o: StateInterface.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StateInterface.o StateInterface.cpp

${OBJECTDIR}/Statistics.o: Statistics.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Statistics.o Statistics.cpp

${OBJECTDIR}/TimeStamp.o: TimeStamp.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TimeStamp.o TimeStamp.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nrd_proto_8

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
