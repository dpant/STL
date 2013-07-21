OBJS = chap9.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++0x
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

chap9.o : chap9.cpp
	$(CC) $(CFLAGS) chap9.cpp

clean:
	\rm *.o *~ p1
