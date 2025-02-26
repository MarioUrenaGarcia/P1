#include "defConvertir.h"

// Función para convertir un número a binario, octal y hexadecimal
void convertirNumeroBases(int numero, tipoConversion *resultado)
{
  // Convertir a binario
  for (int i = 63; i >= 0; i--)
  {
    resultado->binario[63 - i] = (numero & (1LL << i)) ? '1' : '0';
  }
  resultado->binario[64] = '\0';

  // Convertir a octal
  sprintf(resultado->octal, "%#lo", (long)numero);

  // Convertir a hexadecimal
  sprintf(resultado->hexadecimal, "%#lX", (long)numero);
}

// Funcion para ingresar los datos
void ingresarDatos(int *arreglo, int dimensionArreglo)
{
  for (int i = 0; i < dimensionArreglo; i++)
  {
    printf("Ingrese el %d elemento del arreglo 1: ", i + 1);
    scanf("%d", &arreglo[i]);
  }
}