# Commands all have the following format:
#    file_to_be_created: list_of_files_the_file_to_left_is_create_from
#    <tab>the command that generates this file
#
# Compiler options
#    the arguments after g++ specify specific options for the compiler
#    -Wall        ==> print all warnings
#    -pedantic    ==> print warnings when non-standard C++ is used
#    -g           ==> keep additional information to aid in debugging
#    -o           ==> specify the output filename
#    -c           ==> compile only (create a .o file)
#    -std=c++11   ==> use the C++11 standard

run: main.o card.o deck.o baccarat_hand.o
	g++ -pedantic -Wall -g main.o card.o deck.o baccarat_hand.o -o run

main.o: main.cpp card.cpp deck.cpp baccarat_hand.cpp
	g++ -pedantic -Wall -g -c main.cpp

deck.o: deck.h deck.cpp card.h
	g++ -pedantic -Wall -g -c deck.cpp

card.o: card.h card.cpp
	g++ -pedantic -Wall -g -c card.cpp

baccarat_hand.o: card.h card.cpp baccarat_hand.h
	g++ -pedantic -Wall -g -c baccarat_hand.cpp

clean:
	rm -f run main.o card.o deck.o baccarat_hand.o
