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

void convertirDecHex(int numeroDecimal, char hexadecimalSalida[])
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

  // Agregar el 0x, tiene que ser puesto al revés porque se invertirá la cadena
  strcat(hexadecimalCruda, "x0");
  // Invertir la cadena

  for (i = strlen(hexadecimalCruda) - 1; i >= 0; i--)
  {
    hexadecimalSalida[j] = hexadecimalCruda[i];
    j++;
  }

  hexadecimalSalida[j] = '\0'; // Confirmar que la cadena termine

  return;
}
