CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = biquadris
OBJECTS = main.o cell.o grid.o textdisplay.o levelzero.o effects.o changepos.o changelvl.o changeblocks.o randrestart.o
		iblock.o jblock.o lblock.o tblock.o zblock.o sblock.o oblock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
