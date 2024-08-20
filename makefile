FLAGS=-O2

all: test_Optimizer

Optimizer.o: Optimizer.h Optimizer.cpp
	g++ ${FLAGS} -c Optimizer.cpp

test_Optimizer: Optimizer.o test_Optimizer.cpp
	g++ ${FLAGS} Optimizer.o test_Optimizer.cpp -o test_Optimizer