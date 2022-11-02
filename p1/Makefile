output: algorithms.o  matrix_operations.o main.o
	g++-11 -g algorithms.o matrix_operations.o main.o -o output

algorithms.o: algorithms.cpp
	g++-11 -c -g algorithms.cpp

matrix_operations.o: matrix_operations.cpp
	g++-11 -c -g matrix_operations.cpp

main.o: main.cpp
	g++-11 -c -g main.cpp

target: dependencies
	action