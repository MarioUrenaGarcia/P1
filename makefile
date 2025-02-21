convertir.exe: convertir.o funcionesPrincipales.o funcionesPrueba.o
	gcc convertir.o funcionesPrincipales.o funcionesPrueba.o -o convertir.exe

funcionesPrincipales.o: funcionesPrincipales.c defConvertir.h
	gcc -c funcionesPrincipales.c

funcionesPrueba.o: funcionesPrueba.c defConvertir.h
	gcc -c funcionesPrueba.c

convertir.o: convertir.c defConvertir.h
	gcc -c convertir.c
