OBJS = chap2.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++0x
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

chap2.o : chap2.cpp
	$(CC) $(CFLAGS) chap2.cpp

clean:
	\rm *.o *~ p1
