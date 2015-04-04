CC=gcc
CFLAGS=-I.
APP=dotDashToInt

all: $(APP)

.o: .c .h
	$(CC) -c -o $@ $< $(CFLAGS)

$(APP): $(APP).o
	$(CC) -o $@ $< $(CFLAGS)

clean:
	@rm -f *.o $(APP)

