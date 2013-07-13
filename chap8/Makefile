OBJS = chap8.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++0x
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

chap8.o : chap8.cpp
	$(CC) $(CFLAGS) chap8.cpp

clean:
	\rm *.o *~ p1
