output: utils.o graph.o algorithms.o main.o
	g++ -std=c++17 -g  utils.o graph.o algorithms.o main.o -o output

graph.o: graph.cpp
	g++ -std=c++17 -c -g graph.cpp

algorithms.o: algorithms.cpp
	g++ -std=c++17 -c -g algorithms.cpp

main.o: main.cpp
	g++ -std=c++17 -c -g main.cpp

utils.o: utils.cpp
	g++ -std=c++17 -c -g utils.cpp

target: dependencies
	action