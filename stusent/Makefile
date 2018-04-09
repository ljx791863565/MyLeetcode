test : main.o student.o
	gcc -o test main.o student.o
main.o:
	gcc -c main.c student.c student.h
student.o:
	gcc -c student.c student.h
clear :
	rm main.o student.o test
