TARGET = pomodorox
LIBS = -lm
CFLAGS = -ggdb -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c)) \
          $(patsubst %.c, %.o, $(wildcard deps/*/*.c))
HEADERS = $(wildcard deps/*/*.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o bin/$@

clean:
	-rm -f bin/$(TARGET)
	-rm -f bin/*.o
	-rm -f deps/*/*.o
