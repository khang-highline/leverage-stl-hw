CC = g++
.PHONY = run clean

app.exe: Main.o Car.o Utility.o
	$(CC) Utility.o Car.o Main.o -o app.exe

Main.o: Main.cpp Car.h Utility.h
	$(CC) -c Main.cpp

Car.o: Car.cpp Car.h
	$(CC) -c Car.cpp

Utility.o: Utility.cpp Car.h
	$(CC) -c Utility.cpp

run: app.exe
	./app

clean:
	rm -rf *.o *.exe
