CC = g++
CFLAGS = -g
TARGET = P0
OBJS = main.o buildTree.o traversals.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

buildTree.o: buildTree.cpp
	$(CC) $(CFLAGS) -c buildTree.cpp

traversals.o: traversals.cpp
	$(CC) $(CFLAGS) -c traversals.cpp

clean:
	/bin/rm -f *.o $(TARGET)

