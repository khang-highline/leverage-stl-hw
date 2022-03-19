CC = g++
.PHONY = test clean

app.exe: Main.o Car.o Utility.o
	$(CC) Utility.o Car.o Main.o -o app.exe

Main.o: Main.cpp Car.h Utility.h
	$(CC) -c Main.cpp

Car.o: Car.cpp Car.h
	$(CC) -c Car.cpp

Utility.o: Utility.cpp Car.h
	$(CC) -c Utility.cpp

test: app.exe
	./app.exe > output.txt

clean:
	rm -rf *.o *.exe output.txt
