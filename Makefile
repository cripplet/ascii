CC=g++
CFLAGS=-Wall -Werror -O3 -std=c++11 -g -Wl,--no-as-needed -ldl -rdynamic -fstack-protector-all

INCLUDE=-Iinclude/ -Iinclude/libs/

LIBS=-pthread -lncurses

S_SOURCES+=src/*cc
S_OBJECTS=$(S_SOURCES:.cc=.o)

S_EXECUTABLE=ascii.app

.PHONY: all clean

all: $(S_SOURCES) $(S_EXECUTABLE)

$(S_EXECUTABLE): $(S_OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(S_OBJECTS) -o $@ $(LIBS)

clean:
	@rm -f $(S_EXECUTABLE) *.o *.log core
