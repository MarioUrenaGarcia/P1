#include "defConvertir.h"

/**
 * @brief Convierte un número decimal a su representación en hexadecimal.
 * @param numeroDecimal: Número entero positivo a convertir.
 * @param salida: Puntero a la estructura donde se almacenará el resultado en hexadecimal.
 */

void convertirDecHex(int numeroDecimal, tipoConversion *salida)
{
  char hexadecimalCruda[64]; // Cadena antes de ser volteada
  int i = 0, j = 0;
  int valorModulo; // Residuo de la división por 16

  // CONVERTIR DE DECIMAL A HEXADECIMAL
  while (numeroDecimal > 0)
  {
    valorModulo = numeroDecimal % 16;

    // Convertir a número hexadecimal dependiendo del módulo
    if (valorModulo < 10)
    {
      hexadecimalCruda[i] = valorModulo + '0';
    }
    else
    {
      hexadecimalCruda[i] = valorModulo + 'A' - 10;
    }

    i++;
    numeroDecimal /= 16;

  }

  // Agregar "0x" al inicio de la cadena
  strcat(salida->hexadecimal, "0x");

  // Invertir la cadena y colocarla en la estructura de salida
  for (j = 2; i > 0; j++)
  {
    salida->hexadecimal[j] = hexadecimalCruda[i - 1];
    i--;
  }

  salida->hexadecimal[j] = '\0'; // Finalizar la cadena

  return;
}

/**
 * @brief Convierte un número decimal a su representación en octal.
 * @param numeroDecimal: Número entero positivo a convertir.
 * @param salida: Puntero a la estructura donde se almacenará el resultado en octal.
 */

void convertirDecOct(int numeroDecimal, tipoConversion *salida)
{
  char octalCruda[64]; // Cadena antes de ser volteada
  int i = 0, j = 0;
  int valorModulo; // Residuo de la división por 8

  // CONVERTIR DE DECIMAL A OCTAL
  while (numeroDecimal > 0)
  {
    valorModulo = numeroDecimal % 8;
    octalCruda[i] = valorModulo + '0';
    i++;
    numeroDecimal /= 8;
  }

  // Agregar "0" al inicio de la cadena
  strcat(salida->octal, "0");

  // Invertir la cadena y almacenarla en la estructura de salida
  for (j = 1; i > 0; j++)
  {
    salida->octal[j] = octalCruda[i - 1];
    i--;
  }

  salida->octal[j] = '\0'; // Finalizar la cadena

  return;
}

/**
 * @brief Convierte un número decimal a su representación en binario.
 * @param numeroDecimal: Número entero positivo a convertir.
 * @param salida: Puntero a la estructura donde se almacenará el resultado en binario.
 */

void convertirDecBin(int numeroDecimal, tipoConversion *salida)
{
  char binarioCrudo[64]; // Cadena antes de ser volteada
  int i = 0, j = 0;
  int valorModulo; // Residuo de la división por 2

  // CONVERTIR DE DECIMAL A BINARIO
  while (numeroDecimal > 0)
  {
    valorModulo = numeroDecimal % 2;
    binarioCrudo[i] = valorModulo + '0';
    i++;
    numeroDecimal /= 2;
  }

  // Agregar "0b" al inicio de la cadena
  strcat(salida->binario, "0b");

  // Invertir la cadena y almacenarla en la estructura de salida
  for (j = 2; i > 0; j++)
  {
    salida->binario[j] = binarioCrudo[i - 1];
    i--;
  }

  salida->binario[j] = '\0'; // Finalizar la cadena

  return;
}

/**
 * @brief Convierte una lista de números en sus representaciones en binario, octal y hexadecimal.
 * @param arregloEntradas: Arreglo con los números a convertir.
 * @param arregloSalidas: Arreglo de estructuras donde se almacenarán las conversiones.
 * @param dimensionArreglo: Cantidad de números a convertir.
 */

extern void convertirBasesNumericas(int *arregloEntradas, tipoConversion *arregloSalidas, int dimensionArreglo)
{
  for (int i = 0; i < dimensionArreglo; i++)
  {
    convertirDecHex(arregloEntradas[i], &arregloSalidas[i]); // Convertir a hexadecimal
    convertirDecOct(arregloEntradas[i], &arregloSalidas[i]); // Convertir a octal
    convertirDecBin(arregloEntradas[i], &arregloSalidas[i]); // Convertir a binario
  }
  return;
}

/**
 * @brief Guarda los resultados en un archivo de texto llamado "convertidos.txt".
 * @param arregloEntradas: Arreglo con los números originales.
 * @param arregloSalidas: Arreglo de estructuras con los resultados en distintas bases.
 * @param dimensionArreglo: Cantidad de números a almacenar.
 * @param conversionSolicitada: Tipo de conversión seleccionada (binario, octal o hexadecimal).
 */

void crearArchivo(int *arregloEntradas, tipoConversion *arregloSalidas, int dimensionArreglo, char *conversionSolicitada)
{
  FILE *fp = fopen("convertidos.txt", "w");
  if (fp == NULL)
  {
    printf("\n\n\tNo se pudo crear el archivo.\n\n");
    exit(1);
  }

  // Determinar qué conversión se solicitó y escribir en el archivo
  if (strcmp(conversionSolicitada, "binario") == 0)
  {
    for (int i = 0; i < dimensionArreglo; i++)
      fprintf(fp, "[%d] %d\t\t[%d] %s\n", i, arregloEntradas[i], i, arregloSalidas[i].binario);
  }
  else if (strcmp(conversionSolicitada, "octal") == 0)
  {
    for (int i = 0; i < dimensionArreglo; i++)
      fprintf(fp, "[%d] %d\t\t[%d] %s\n", i, arregloEntradas[i], i, arregloSalidas[i].octal);
  }
  else if (strcmp(conversionSolicitada, "hexadecimal") == 0)
  {
    for (int i = 0; i < dimensionArreglo; i++)
      fprintf(fp, "[%d] %d\t\t[%d] %s\n", i, arregloEntradas[i], i, arregloSalidas[i].hexadecimal);
  }
  else
  {
    printf("\n\n\tEntrada número 3 inválida.\n\n");
  }

  fclose(fp); // Cerrar el archivo

  return;
}

/**
 * @brief Permite al usuario ingresar datos en un arreglo.
 * @param arreglo: Arreglo donde se almacenarán los números ingresados.
 * @param dimensionArreglo: Cantidad de números a ingresar.
 */

extern void ingresarDatos(int *arreglo, int dimensionArreglo)
{
  for (int i = 0; i < dimensionArreglo; i++)
  {
    printf("Ingrese el %d elemento del arreglo 1: ", i + 1);
    scanf("%d", &arreglo[i]);
  }
}
