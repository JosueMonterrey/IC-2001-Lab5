EXECUTABLES := L50 L51
CXX := g++

all: compile

compile:
		${CXX} -o L50 L50.cpp
		${CXX} -o L51 L51.cpp

clean:
		rm -f ${EXECUTABLES}