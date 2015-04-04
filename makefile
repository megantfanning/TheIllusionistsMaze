CXX=g++
CFLAGS= -Wall -c
all: clean Final

Final: Final.o Room.o LockedRoom.o MirroredRoom.o Item.o Inventory.o Carosel.o
	${CXX} Final.o Room.o Item.o MirroredRoom.o LockedRoom.o Inventory.o Carosel.o -o Final

Final.o: Final.cpp Room.h Inventory.h MirroredRoom.h LockedRoom.h Carosel.h
	${CXX} Final.cpp ${CFLAGS} -o Final.o

Inventory.o: Inventory.cpp Item.h
	${CXX} Inventory.cpp ${CFLAGS} -o Inventory.o

Room.o: Room.cpp Item.h Inventory.h 
	${CXX} Room.cpp ${CFLAGS} -o Room.o

MirroredRoom.o: Room.o  MirroredRoom.cpp  Item.h
	${CXX} MirroredRoom.cpp ${CFLAGS} -o MirroredRoom.o

LockedRoom.o: LockedRoom.cpp Item.h
	${CXX} LockedRoom.cpp ${CFLAGS} -o LockedRoom.o

Carosel.o: Carosel.cpp Room.h
	${CXX} Carosel.cpp ${CFLAGS} -o Carosel.o


Item.o: Item.cpp
	${CXX} Item.cpp ${CFLAGS} -o Item.o

clean:
	rm -rf *.o
