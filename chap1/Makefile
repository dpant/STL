OBJS = chap1.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++0x
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

chap1.o : chap1.cpp
	$(CC) $(CFLAGS) chap1.cpp

clean:
	\rm *.o *~ p1
