output: main.o animal.o tiger.o zoo.o penguin.o turtle.o
	g++ main.o animal.o tiger.o zoo.o penguin.o turtle.o -o output

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

animal.o: animal.cpp animal.hpp
	g++ -std=c++11 -g -Wall -c animal.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -std=c++11 -g -Wall -c tiger.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -std=c++11 -g -Wall -c penguin.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -std=c++11 -g -Wall -c turtle.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ -std=c++11 -g -Wall -c zoo.cpp

clean: 
	rm *.o output
	