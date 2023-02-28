all: a1

a1: main.o Date.o Room.o Student.o Reservation.o Library.o
	g++ -o a1 main.o Date.o Room.o Student.o Reservation.o Library.o

main.o: main.cc a1-global.cc Date.h Room.h Student.h Reservation.h Library.h
	g++ -c main.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc

Room.o:	Room.h Room.cc
	g++ -c Room.cc

Student.o:	Student.h Student.cc
	g++ -c Student.cc

Library.o:	Library.cc Library.h Reservation.h Room.h Student.h Date.h
	g++ -c Library.cc

Reservation.o:	Reservation.cc Reservation.h Room.h Student.h Date.h
	g++ -c Reservation.cc

clean:
	rm -f a1 *.o
