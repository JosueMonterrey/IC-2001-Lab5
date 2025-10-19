EXECUTABLES := L50 L51 52
CXX := g++

all: compile

compile:
		${CXX} -o L50 L50.cpp
		${CXX} -o L51 L51.cpp
		${CXX} -o L52 L52.cpp

clean:
		rm -f ${EXECUTABLES}