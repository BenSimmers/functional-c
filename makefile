CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBRARY = functional.so # or functional.dll
WINDOWSLIBRARY = functional.dll
PROGRAM = program

all: $(PROGRAM)

$(PROGRAM): main.o $(LIBRARY)
  # $(CC) $(CFLAGS) main.o -o $(PROGRAM) -L. -lfunctional
	$(CC) $(CFLAGS) main.o -o $(PROGRAM) -ldl


main.o: main.c functional.h
	$(CC) $(CFLAGS) -c main.c

$(LIBRARY): main.c functional.h
	$(CC) $(CFLAGS) -shared -o $(LIBRARY) main.c

windows: main.c functional.h
	$(CC) $(CFLAGS) -shared -o $(WINDOWSLIBRARY) main.c


run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f *.o $(PROGRAM) $(LIBRARY) $(WINDOWSLIBRARY)
