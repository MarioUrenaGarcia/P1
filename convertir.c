
/**
 *
 * @file convertir.c
 * @brief
 * @details
 * @date 19/febrero/2025
 * @author Mario Ureña García, Ricardo Ponce de León, Emiliano Cisneros
 *
 */

// Bibliotecas --------------------------------------------------------------------------
#include "defConvertir.h"

// Declaración de funciones --------------------------------------------------------------

void probarArregloUnidimensional(int arreglo[], int size);
void ingresarDatos(int *arreglo, int dimensionArreglo);
void convertirBasesNumericas(int *arregloEntradas, tipoConversion *arregloSalidas, int dimensionArreglo);

// Main ---------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
  //-------------------------------------------------------------------------------------
  // Variables
  int *arregloEntradas;
  tipoConversion *arregloSalidas;
  int dimensionArreglo;
  int i;

  // Procesos
  if (argc == 1)
  {
    printf("\n\n\tIngresaste solo un argumento.\n\n");
    exit(2);
  }

  sscanf(argv[1], "%d", &dimensionArreglo);

  // Fase de Ingreso de Datos------------------------------------------------------------

  arregloEntradas = (int *)malloc(dimensionArreglo * sizeof(int)); // Crear el arregloEntradas donde se almacenaran los datos ingresados
  if (arregloEntradas == NULL)
  {
    printf("\n\n\tNo hay memoria disponible.\n\n");
    exit(1);
  }

  ingresarDatos(arregloEntradas, dimensionArreglo); // Usuario ingresa los datos

  // Fin de la Fase de Ingreso de Datos-------------------------------------------------
  // Inicio de la Fase de Conversión------------------------------------------------------

  arregloSalidas = (tipoConversion *)malloc(dimensionArreglo * sizeof(tipoConversion)); // Crear el arregloSalidas donde se almacenaran los datos convertidos
  if (arregloSalidas == NULL)
  {
    printf("\n\n\tNo hay memoria disponible.\n\n");
    exit(1);
  }

  convertirBasesNumericas(arregloEntradas, arregloSalidas, dimensionArreglo); // Convertir los datos

  // Fin de la Fase de Conversión---------------------------------------------------------

  // Impresión de los datos ingresados y convertidos---------------------------------------
  printf("\n\nArreglo Entrada\t\tArreglo Salida\n\n");

  for (i = 0; i < dimensionArreglo; i++)
  {
    printf("[%d] %d\t\t [%d] %s, %s, %s\n", i, arregloEntradas[i], i, arregloSalidas[i].binario, arregloSalidas[i].octal, arregloSalidas[i].hexadecimal);
  }

  // Antes de finalizar el programa, liberar la memoria
  free(arregloEntradas);
  free(arregloSalidas);
  // FINALIZACIÓN DEL PROGRAMA
  printf("\n\n\tPrograma Finalizado con ÉXITO\n\n");
  return 0;
}
