OBJS = chap3.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++0x
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

chap3.o : chap3.cpp
	$(CC) $(CFLAGS) chap3.cpp

clean:
	\rm *.o *~ p1
