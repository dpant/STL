OBJS = chap6.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++0x
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

chap6.o : chap6.cpp
	$(CC) $(CFLAGS) chap6.cpp

clean:
	\rm *.o *~ p1
