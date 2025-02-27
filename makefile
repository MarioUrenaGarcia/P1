convertir.exe: convertir.o funcionesPrincipales.o
	gcc convertir.o funcionesPrincipales.o -o convertir.exe

funcionesPrincipales.o: funcionesPrincipales.c defConvertir.h
	gcc -c funcionesPrincipales.c

convertir.o: convertir.c defConvertir.h
	gcc -c convertir.c
