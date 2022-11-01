output: algorithms.o  matrix_operations.o main.o
	g++-11 algorithms.o matrix_operations.o main.o -o output

algorithms.o: algorithms.cpp
	g++-11 -c algorithms.cpp

matrix_operations.o: matrix_operations.cpp
	g++-11 -c matrix_operations.cpp

main.o: main.cpp
	g++-11 -c main.cpp

target: dependencies
	action