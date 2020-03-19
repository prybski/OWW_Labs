CPPCOMP = g++

# DEBUG
# OPT = -g -DDEBUG

# O3
OPT = -O3

HEADERS = Headers

DEFINITIONS = Definitions/Array.cpp Definitions/SparseMatrix.cpp \
Definitions/Matrix.cpp Definitions/Random.cpp Definitions/CompressedRowStorage.cpp \
Definitions/pomiar_czasu.cpp

.PHONY: all Source

all: Source
Source: Source.cpp
	@echo "Building 'Source.cpp'..."
	
	${CPPCOMP} ${OPT} -std=c++17 Source.cpp ${DEFINITIONS} -I ${HEADERS} -o Source.o
clean:
	@echo "Cleaning up..."
	
	rm *.o