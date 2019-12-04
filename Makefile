CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = biquadris
OBJECTS = main.o exception.o pieces.o grid.o window.o textdisplay.o graphicsdisplay.o levelZero.o levelOne.o levelTwo.o levelThree.o levelFour.o trie.o player.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
