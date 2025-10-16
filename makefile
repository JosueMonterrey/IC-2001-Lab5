EXECUTABLES := L50
CXX := g++

all: compile

compile:
		${CXX} -o L50 L50.cpp

clean:
		rm -f ${EXECUTABLES}