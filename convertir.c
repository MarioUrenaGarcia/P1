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
// Main ---------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
  //-------------------------------------------------------------------------------------
  // Variables
  int *datosIngresados;
  int dimensionArreglo;
  
  // Procesos
  if(argc == 1)
    {
      printf("\n\n\tIngresaste solo un argumento.\n\n");
      exit(1);
    }
  
  sscanf(argv[1],"%d",&dimensionArreglo);

  //Crear el arreglo donde se almacenaran los datos ingresados
  /////////////////////////
  datosIngresados = (int *) malloc(dimensionArreglo  * sizeof(int));
  if(datosIngresados == NULL)
    {
      printf("\n\n\tNo hay memoria disponible.\n\n");
      exit(1);
    }

  probarArregloUnidimensional(datosIngresados, dimensionArreglo);
  /////////////////////////


  //LIBERAR MEMORIA
  free(datosIngresados);
  
  // FINALIZACIÓN DEL PROGRAMA
  printf("\n\n\tPrograma Finalizado con ÉXITO\n\n");
  return 0;
}
