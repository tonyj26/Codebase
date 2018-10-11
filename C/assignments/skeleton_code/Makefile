CC=gcc
CFLAGS=-c
CMATH=-lm

all: clean myOS 

myOS: myOS.o shell.o helper.o launch.o builtin.o
	$(CC) -o $@ $^ $(CMATH)

myOS.o: myOS.c myOS.h
	$(CC) $(CFLAGS) -o $@ $<

shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -o $@ $< 

helper.o: helper.c helper.h 
	$(CC) $(CFLAGS) -o $@ $<

launch.o: launch.c launch.h
	$(CC) $(CFLAGS) -o $@ $<

builtin.o: builtin.c builtin.h
	$(CC) $(CFLAGS) -o $@ $<

test: clean myOS
	bash ./tests/run.sh

clean:
	rm -f *.o myOS report.txt
