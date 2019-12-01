CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = biquadris
OBJECTS = main.o pieces.o grid.o textdisplay.o levelZero.o trie.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
