NAME=Main

all:
	g++ -Ofast -o ../bin/$(NAME) -I ../include -L ../lib *.cpp -l SDL2main -l SDL2 -l SDL2_image -mwindows

debug:
	g++ -o ../bin/$(NAME)Debug -D DEBUG -I ../include -L ../lib *.cpp -l SDL2main -l SDL2 -l SDL2_image