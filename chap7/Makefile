OBJS = chap7.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++0x
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

chap7.o : chap7.cpp
	$(CC) $(CFLAGS) chap7.cpp

clean:
	\rm *.o *~ p1
