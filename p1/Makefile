output: algorithms.o  matrix_operations.o main.o
	g++ -std=c++11 -g algorithms.o matrix_operations.o main.o -o output

algorithms.o: algorithms.cpp
	g++ -std=c++11 -c -g algorithms.cpp

matrix_operations.o: matrix_operations.cpp
	g++ -std=c++11 -c -g matrix_operations.cpp

main.o: main.cpp
	g++ -std=c++11 -c -g main.cpp

target: dependencies
	action