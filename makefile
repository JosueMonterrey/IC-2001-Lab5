EXECUTABLES := L50 L51 L52 L53
CXX := g++

all: compile

compile:
		${CXX} -o L50 L50.cpp
		${CXX} -o L51 L51.cpp
		${CXX} -o L52 L52.cpp
		${CXX} -o L53 L53.cpp

clean:
		rm -f ${EXECUTABLES}