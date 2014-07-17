
OBJS = MicrocontrollerEmulator.o Facade.o Macrochip.o Mops.o Rotamola.o Utils.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o MicrocontrollerEmulator

MicrocontrollerEmulator.o : Facade.h Utils.h Microcontroller.h Mops.h Macrochip.h Rotamola.h
	$(CC) $(CFLAGS) MicrocontrollerEmulator.cpp

Facade.o : Facade.cpp Facade.h Utils.h Microcontroller.h Mops.h Macrochip.h Rotamola.h
	$(CC) $(CFLAGS) Facade.cpp

Macrochip.o : Macrochip.cpp Microcontroller.h Utils.h
	$(CC) $(CFLAGS) Macrochip.cpp

Mops.o : Mops.cpp Microcontroller.h Utils.h 
	$(CC) $(CFLAGS) Mops.cpp

Rotamola.o : Rotamola.cpp Microcontroller.h Utils.h 
	$(CC) $(CFLAGS) Rotamola.cpp

Utils.o : Utils.cpp Utils.h 
	$(CC) $(CFLAGS) Utils.cpp



clean:
	\rm *.o MicrocontrollerEmulator