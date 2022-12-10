output: graph.o algorithms.o main.o
	g++ -std=c++17 -g  graph.o algorithms.o main.o -o output

graph.o: graph.cpp
	g++ -std=c++17 -c -g graph.cpp

algorithms.o: algorithms.cpp
	g++ -std=c++17 -c -g algorithms.cpp

main.o: main.cpp
	g++ -std=c++17 -c -g main.cpp

target: dependencies
	action