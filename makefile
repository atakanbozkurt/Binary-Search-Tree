ass6: map.o testMap.o

	g++ map.o testMap.o -o ass6

map.o: map.cpp
	g++ -c -std=c++11 map.cpp

testMap.o: testMap.cpp
	g++ -c -std=c++11 testMap.cpp
