FLAGS=-O2

all: test_Optimizer test_Image test_ImageProcesor

Optimizer.o: Optimizer.h Optimizer.cpp
	g++ ${FLAGS} -c Optimizer.cpp

Image.o: Image.h Image.cpp
	g++ ${FLAGS} -c Image.cpp

ImageProcesor.o: ImageProcesor.h ImageProcesor.cpp
	g++ ${FLAGS} -c ImageProcesor.cpp

Problem.o: Problem.h Problem.cpp
	g++ ${FLAGS} -c Problem.cpp


test_Optimizer: Optimizer.o test_Optimizer.cpp
	g++ ${FLAGS} Optimizer.o test_Optimizer.cpp -o test_Optimizer

test_Image: Image.o test_Image.cpp
	g++ ${FLAGS} Image.o test_Image.cpp -o test_Image

test_ImageProcesor: ImageProcesor.o Image.o test_ImageProcesor.cpp
	g++ ${FLAGS} ImageProcesor.o Image.o test_ImageProcesor.cpp -o test_ImageProcesor

clean:
	rm -f *.o test_Optimizer test_Image test_ImageProcesor