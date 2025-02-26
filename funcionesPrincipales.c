#include "defConvertir.h"

void convertirDecHex(int numeroDecimal, tipoConversion *salida)
{
  char hexadecimalCruda[64]; // Cadena antes de ser volteada
  int i = 0, j = 0;
  int valorModulo; // Valor adquirido después de usar el módulo.

  // CONVERTIR DE DECIMAL A HEXADECIMAL
  while (numeroDecimal > 0)
  {
    // ValorModulo es el residuo
    valorModulo = numeroDecimal % 16;

    // Convertir a numero hexadecimal dependiendo del módulo
    if (valorModulo < 10)
    {
      hexadecimalCruda[i] = valorModulo + '0';
    }
    else
    {
      hexadecimalCruda[i] = valorModulo + 'A' - 10;
    }

    i++;

    numeroDecimal = numeroDecimal / 16;
  }

  // Agregar el 0x al inicio de la cadena
  strcat(salida->hexadecimal, "0x");

  // Invertir la cadena y colocarla en el arreglo por referencia, iniciando desde el 2 por el 0x

  for (j = 2; i > 0; j++)
  {
    salida->hexadecimal[j] = hexadecimalCruda[i - 1];
    i--;
  }
  // Agregar el fin de la cadena para cerrarla
  salida->hexadecimal[j] = '\0';

  return;
}

void convertirDecOct(int numeroDecimal, tipoConversion *salida)
{
  char octalCruda[64]; // Cadena antes de ser volteada
  int i = 0, j = 0;
  int valorModulo; // Valor adquirido después de usar el módulo.

  // CONVERTIR DE DECIMAL A OCTAL
  while (numeroDecimal > 0)
  {
    // ValorModulo es el residuo
    valorModulo = numeroDecimal % 8;

    // Convertir a numero octal dependiendo del módulo
    octalCruda[i] = valorModulo + '0';

    i++;

    numeroDecimal = numeroDecimal / 8;
  }
  // Agregar el 0 al inicio de la cadena
  strcat(salida->octal, "0");

  // Invertir la cadena y colocarla en el arreglo por referencia
  for (j = 1; i > 0; j++)
  {
    salida->octal[j] = octalCruda[i - 1];
    i--;
  }
  // Agregar el fin de la cadena para cerrarla
  salida->octal[j] = '\0';

  return;
}

void convertirDecBin(int numeroDecimal, tipoConversion *salida)
{
  char binarioCrudo[64]; // Cadena antes de ser volteada
  int i = 0, j = 0;
  int valorModulo; // Valor adquirido después de usar el módulo.

  // CONVERTIR DE DECIMAL A BINARIO
  while (numeroDecimal > 0)
  {
    // ValorModulo es el residuo
    valorModulo = numeroDecimal % 2;

    // Convertir a numero binario dependiendo del módulo
    binarioCrudo[i] = valorModulo + '0';

    i++;

    numeroDecimal = numeroDecimal / 2;
  }

  // Agregar el 0b al inicio de la cadena
  strcat(salida->binario, "0b");

  // Invertir la cadena y colocarla en el arreglo por referencia, iniciando desde el 2 por el 0b
  for (j = 2; i > 0; j++)
  {
    salida->binario[j] = binarioCrudo[i - 1];
    i--;
  }
  // Agregar el fin de la cadena para cerrarla
  salida->binario[j] = '\0';

  return;
}

extern void convertirBasesNumericas(int *arregloEntradas, tipoConversion *arregloSalidas, int dimensionArreglo)
{
  int entrada;
  int i;

  for (i = 0; i < dimensionArreglo; i++)
  {
    // Convertir a hexadecimal
    convertirDecHex(arregloEntradas[i], &arregloSalidas[i]);
    // Convertir a octal
    convertirDecOct(arregloEntradas[i], &arregloSalidas[i]);
    // Convertir a binario
    convertirDecBin(arregloEntradas[i], &arregloSalidas[i]);
  }

  return;
}

void crearArchivo(int *arregloEntradas, tipoConversion *arregloSalidas, int dimensionArreglo, char *conversionSolicitada)
{
  FILE *fp;
  int i;

  fp = fopen("convertidos.txt", "w");
  if (fp == NULL)
  {
    printf("\n\n\tNo se pudo crear el archivo.\n\n");
    exit(1);
  }

  // Determinar que conversion se solicitó
  if (strcmp(conversionSolicitada, "binario") == 0)
  {
    for (i = 0; i < dimensionArreglo; i++)
    {
      fprintf(fp, "[%d] %d\t\t[%d] %s\n", i, arregloEntradas[i], i, arregloSalidas[i].binario);
    }
  }
  else if (strcmp(conversionSolicitada, "octal") == 0)
  {
    for (i = 0; i < dimensionArreglo; i++)
    {
      fprintf(fp, "[%d] %d\t\t[%d] %s\n", i, arregloEntradas[i], i, arregloSalidas[i].octal);
    }
  }
  else if (strcmp(conversionSolicitada, "hexadecimal") == 0)
  {
    for (i = 0; i < dimensionArreglo; i++)
    {
      fprintf(fp, "[%d] %d\t\t[%d] %s\n", i, arregloEntradas[i], i, arregloSalidas[i].hexadecimal);
    }
  }
  else
  {
    printf("\n\n\tEntrada número 3 inválida.\n\n");
  }

  fclose(fp);

  return;
}
// Funcion para ingresar los datos
extern void ingresarDatos(int *arreglo, int dimensionArreglo)
{
  for (int i = 0; i < dimensionArreglo; i++)
  {
    printf("Ingrese el %d elemento del arreglo 1: ", i + 1);
    scanf("%d", &arreglo[i]);
  }
}