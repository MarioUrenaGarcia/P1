/**
 * @file funcionesPrincipales.c
 * @brief Funciones principales para el programa de conversión de números decimales a binario, octal y hexadecimal.
 * @details Este archivo contiene las funciones necesarias para realizar la conversión de números decimales a binario, octal y hexadecimal.
 * @author Mario Ureña, Emiliano Cisneros y Ricardo Ponce de León
 * @date 27/febrero/2025
 */

#include "defConvertir.h"

/**
 * @brief Convierte un número decimal a su representación en hexadecimal.
 * @author Mario Ureña
 * @param numeroDecimal Número entero positivo a convertir
 * @param salida Puntero a la estructura donde se almacenará el resultado en hexadecimal
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
 * @author Mario Ureña
 * @param numeroDecimal Número entero positivo a convertir
 * @param salida Puntero a la estructura donde se almacenará el resultado en octal
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
 * @author Mario Ureña
 * @param numeroDecimal Número entero positivo a convertir
 * @param salida Puntero a la estructura donde se almacenará el resultado en binario
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
 * @author Mario Ureña
 * @param arregloEntradas Arreglo con los números a convertir
 * @param arregloSalidas Arreglo de estructuras donde se almacenarán las conversiones
 * @param dimensionArreglo Cantidad de números a convertir
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
 * @author Mario Ureña, Emiliano Cisneros y Ricardo Ponce de León
 * @param arregloEntradas Arreglo con los números originales
 * @param arregloSalidas Arreglo de estructuras con los resultados en distintas bases
 * @param dimensionArreglo Cantidad de números a almacenar
 * @param conversionSolicitada Tipo de conversión seleccionada (binario, octal o hexadecimal)
 */

void crearArchivo(int *arregloEntradas, tipoConversion *arregloSalidas, int dimensionArreglo, char *conversionSolicitada)
{
  int i;
  FILE *fp;

  // Determinar qué conversión se solicitó y escribir en el archivo

  // BINARIO
  if (strcmp(conversionSolicitada, "binario") == 0 || strcmp(conversionSolicitada, "bin") == 0)
  {
    fp = fopen("convertidos.txt", "w");
    if (fp == NULL)
    {
      printf(RED "\n\n\tNo se pudo crear el archivo.\n\n" RESET);
      exit(1);
    }

    for (i = 0; i < dimensionArreglo; i++)
    {
      fprintf(fp, "[%d] %d\t\t[%d] %s\n", i, arregloEntradas[i], i, arregloSalidas[i].binario);
    }

    printf(GREEN "\n\n\t\tArchivo Guardado\n\n" RESET);
    printf("Los resultados de esta operación fueron anexados en el archivo convertidos.txt en binario\n\n");

    fclose(fp);
  }

  // OCTAL
  else if (strcmp(conversionSolicitada, "octal") == 0 || strcmp(conversionSolicitada, "oct") == 0)
  {
    fp = fopen("convertidos.txt", "w");
    if (fp == NULL)
    {
      printf(RED "\n\n\tNo se pudo crear el archivo.\n\n" RESET);
      exit(1);
    }

    for (i = 0; i < dimensionArreglo; i++)
    {
      fprintf(fp, "[%d] %d\t\t[%d] %s\n", i, arregloEntradas[i], i, arregloSalidas[i].octal);
    }

    printf(GREEN "\n\n\t\tArchivo Guardado\n\n" RESET);
    printf("\n\n\tLos resultados de esta operación fueron anexados en el archivo convertidos.txt en octal\n\n");

    fclose(fp);
  }

  // HEXADECIMAL
  else if (strcmp(conversionSolicitada, "hexadecimal") == 0 || strcmp(conversionSolicitada, "hex") == 0)
  {
    fp = fopen("convertidos.txt", "w");
    if (fp == NULL)
    {
      printf(RED "\n\n\tNo se pudo crear el archivo.\n\n" RESET);
      exit(1);
    }

    for (i = 0; i < dimensionArreglo; i++)
    {
      fprintf(fp, "[%d] %d\t\t[%d] %s\n", i, arregloEntradas[i], i, arregloSalidas[i].hexadecimal);
    }

    printf(GREEN "\n\n\t\tArchivo Guardado\n\n" RESET);
    printf("\n\n\tLos resultados de esta operación fueron anexados en el archivo convertidos.txt en hexadecimal\n\n");

    fclose(fp);
  }

  // TODAS LAS BASES
  else if (strcmp(conversionSolicitada, "todos") == 0 || strcmp(conversionSolicitada, "all") == 0 || strcmp(conversionSolicitada, "todas") == 0)
  {
    fp = fopen("convertidos.txt", "w");
    if (fp == NULL)
    {
      printf(RED "\n\n\tNo se pudo crear el archivo.\n\n" RESET);
      exit(1);
    }

    for (i = 0; i < dimensionArreglo; i++)
    {
      fprintf(fp, "[%d] %d\t\t[%d] %s,\t\t%s,\t\t%s\n", i, arregloEntradas[i], i, arregloSalidas[i].binario, arregloSalidas[i].octal, arregloSalidas[i].hexadecimal);
    }

    printf(GREEN "\n\n\t\tArchivo Guardado\n\n" RESET);
    printf("\n\n\tLos resultados de esta operación fueron anexados en el archivo convertidos.txt en todas las bases disponibles\n\n");

    fclose(fp);
  }
  else
  {
    printf("\n\n\tEntrada número 3 " RED "inválida" RESET ". No se ha creado el archivo\n\n");
  }

  return;
}

/**
 * @brief Permite al usuario ingresar datos en un arreglo.
 * @author Emiliano Cisneros
 * @param arreglo: Arreglo donde se almacenarán los números ingresados
 * @param dimensionArreglo: Cantidad de números a ingresar
 */

extern void ingresarDatos(int *arreglo, int dimensionArreglo)
{
  for (int i = 0; i < dimensionArreglo; i++)
  {
    // Solicitar al usuario que ingrese un número
    printf("Ingrese el número %d: ", i + 1);
    scanf("%d", &arreglo[i]);

    // Validar que el número ingresado sea positivo
    while (arreglo[i] < 0)
    {
      printf(RED "\n\n\tError: " RESET "El número debe ser positivo.\n");
      printf("Ingrese un valor válido en número %d: ", i + 1);
      scanf("%d", &arreglo[i]);
    }
  }
}

/**
 * @brief Imprime los datos ingresados y sus conversiones en binario, octal y hexadecimal.
 * @author Emiliano Cisneros y Ricardo Ponce de León
 * @param arreglo: Arreglo con los números originales
 * @param arregloSalidas: Arreglo de estructuras con los resultados en distintas bases
 * @param dimensionArreglo: Cantidad de números a imprimir
 */
extern void imprimirDatos(int *arregloEntradas, tipoConversion *arregloSalidas, int dimensionArreglo)
{

  printf("\n\nArreglo Entrada\t\tArreglo Salida\n\n");

  for (int i = 0; i < dimensionArreglo; i++)
  {
    // Muestra el índice del número ingresado y sus conversiones en las distintas bases.
    printf(YELLOW "[%d]" RESET " %d\t\t" YELLOW "[%d]" RESET " %s,\t\t%s,\t\t%s\n", i, arregloEntradas[i], i, arregloSalidas[i].binario, arregloSalidas[i].octal, arregloSalidas[i].hexadecimal);
  }

  return;
}