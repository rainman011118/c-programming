OBJECTS=bts.c bts_functions.o 
CC=gcc
TARGET=bts
#.DEFAULT_GOAL:= mytarget

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

%.o: %.c %.h
	$(CC) -c $< -o $@

.PHONY: clean
clean:	
	rm -f *.o $(TARGET)
