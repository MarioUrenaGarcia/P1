convertir.exe: convertir.o
	gcc convertir.o -o convertir.exe

convertir.o: convertir.c
	gcc -c convertir.c
