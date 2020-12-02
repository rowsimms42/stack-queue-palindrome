objects = main.o Buffer.o Menu.o Palindrome.o

Lab9: $(objects)
	g++ -std=c++11 -g -o Lab9 $(objects)

main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
Buffer.o: Buffer.cpp Buffer.hpp
	g++ -std=c++11 -c Buffer.cpp
	
Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp

Palindrome.o: Palindrome.cpp Palindrome.hpp
	g++ -std=c++11 -c Palindrome.cpp


.PHONY: clean
clean:
	rm Lab9 $(objects)
