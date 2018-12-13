
CC = g++

CPPFLAGS = `sdl2-config --cflags` -g -W -Wall -Werror -std=c++11 -Weffc++ \
	-Wextra -pedantic -O0 -I `sdl2-config --prefix`/include/

LDFLAGS = `sdl2-config --libs` -lm -lexpat -lSDL2_ttf -lSDL2_image -lSDL2_mixer

OBJS = \
	obj/Clock.o \
	obj/Drawable.o \
	obj/Game_Data.o \
	obj/Main.o \
	obj/Vector.o

default : $(OBJS)
	$(CC) $(CPPFLAGS) -o run $(OBJS) $(LDFLAGS)

obj/%.o : src/%.cpp src/%.h
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)
	rm -rf run
