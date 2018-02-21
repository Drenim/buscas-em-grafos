all: main

main: main.o TADgrafo.o TADfila.o TADpilha.o
	gcc -o main main.o TADgrafo.o TADfila.o TADpilha.o

main.o: main.c TADgrafo.h
	gcc -o main.o -c main.c

TADgrafo.o: TADpilha.h TADfila.h TADgrafo.c
	gcc -o TADgrafo.o -c TADgrafo.c 

TADpilha.o: TADgrafo.h TADpilha.c TADpilha.h
	gcc -o TADpilha.o -c TADpilha.c

TADfila.o: TADgrafo.h TADfila.c TADfila.h
	gcc -o TADfila.o -c TADfila.c

clean:
	rm -rf *.o
