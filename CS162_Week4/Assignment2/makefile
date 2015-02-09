CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors


SRC1 = list.cpp
SRC2 = Assignment2.cpp
SRCS = ${SRC1} ${SRC2}

OBJ1 = list.o
OBJ2 = Assignment2.o
OBJS = ${OBJ1} ${OBJ2}

HDR1 = list.h
HDR2 = item.h
HDRS = ${HDR1} ${HDR2}

PROG = Ass2

default: ${OBJS} ${PROG}

${OBJS}: ${SRCS} ${HDRS}
	${CXX} ${CXXFLAGS} ${SRCS} ${HDRS} -c $(@.o=.cpp)

${PROG}:
	${CXX} ${CXXFLAGS} ${OBJS} -o ${PROG}

clean:
	rm -f  *.o *~ *.gch  ${PROG}
