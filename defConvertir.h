#include <stdio.h>
#include <stdlib.h>

// Definiciones -------------------------------------------------------------------------

//Colores
#define RED "\x1b[31m"
#define WHITE "\x1B[37m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"
#define CYAN "\x1b[36m"

//Estructuras
struct conversiones
{
  char binario[64];
  char octal[64];
  char hexadecimal[64];
};

typedef struct conversiones tipoConversion;
