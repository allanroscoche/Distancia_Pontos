all: paralelo sequencial

trabalho: paralelo.cpp
	g++ -Lphtreads -o paralelo paralelo.cpp

sequencial: sequencial.o utilidades.o
	g++ -o sequencial sequencial.o utilidades.o

sequencial.o: sequencial.cpp
	g++ -c -o sequencial.o sequencial.cpp

utilidades.o: utilidades.cpp
	g++ -c -o utilidades.o utilidades.cpp

clean:
	rm paralelo sequencial *.o *~
