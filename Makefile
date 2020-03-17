CPP = g++
DEPENDENCIES = Headers
DEFINITIONS = Definitions/Array.cpp Definitions/SparseMatrix.cpp \
Definitions/Matrix.cpp Definitions/Random.cpp Definitions/CompressedRowStorage.cpp

.PHONY: all Source

all: Source
Source: Source.cpp
	@echo "Building 'Source.cpp'..."
	
	${CPP} -std=c++17 -g Source.cpp ${DEFINITIONS} -I ${DEPENDENCIES} -o Source.o
clean:
	@echo "Cleaning up..."
	
	rm *.o
