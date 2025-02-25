
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
void ingresarDatos(int *arreglo1, int dimensionArreglo);
void crearArreglo1(int *arreglo1, int dimensionArreglo);
// Main ---------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
  //-------------------------------------------------------------------------------------
  // Variables
  int *entradas;
  int dimensionArreglo;
  
  // Procesos
  if(argc == 1)
    {
      printf("\n\n\tIngresaste solo un argumento.\n\n");
      exit(2);
    }
  
  sscanf(argv[1],"%d",&dimensionArreglo);

  //Crear el arreglo 1 donde se almacenaran los datos ingresados
  /////////////////////////
  entradas = (int *) malloc(dimensionArreglo  * sizeof(int));
  if(entradas == NULL)
    {
      printf("\n\n\tNo hay memoria disponible.\n\n");
      exit(1);
    }

  //probarArregloUnidimensional(entradas, dimensionArreglo);
  ingresarDatos(entradas, dimensionArreglo);
  crearArreglo1(entradas, dimensionArreglo);
  /////////////////////////


  //LIBERAR MEMORIA
  free(entradas);
  
  // FINALIZACIÓN DEL PROGRAMA
  printf("\n\n\tPrograma Finalizado con ÉXITO\n\n");
  return 0;
}
