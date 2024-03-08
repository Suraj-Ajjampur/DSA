# Author: Suraj Ajjampur
# ref : 1.https://makefiletutorial.com/
#       2.https://phoenixnap.com/kb/shebang-bash
#		3.https://makefiletutorial.com/#make-clean

CC=gcc
CFLAGS=-I.
DEPS = main.h ll_apps.h
OBJ = main.o ll_apps.o stack.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

program: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f program main *.o
