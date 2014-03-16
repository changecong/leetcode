# get cpp code
SOLUTION=solution.cpp
SOURCE=$(SOLUTION)

TARGET=solution
OBJECT=$(TARGET).o

INCLDIR = -I../000-tools/

CC=g++
CFLAGE=-Wall -ggdb $(INCLDIR)

# VAR=-D BRUTE_FORCE

all: $(TARGET)

$(TARGET):$(OBJECT)
	$(CC) $(CFLAGE) -o $@ $<

$(OBJECT):$(SOURCE)
	$(CC) $(CFLAGE) -c $< -o $@ $(VAR)

test:
	@./$(TARGET)

time:
	@time ./$(TARGET)

clean:
	rm $(OBJECT) $(TARGET)