/**
 *
 * @file convertir.c
 * @brief Breve Descripción 
 * @details Descripción extendida
 * @date 19/febrero/2025
 * @author Mario Ureña García, Ricardo Ponce de León, Emiliano Cisneros
 *
 */

// Bibliotecas --------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// Definiciones -------------------------------------------------------------------------
#define RED "\x1b[31m"
#define WHITE "\x1B[37m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"
#define CYAN "\x1b[36m"

// Declaración de estructuras -------------------------------------------------------------


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

// Funciones ----------------------------------------------------------------------------

/**
 *
 * @brief
 * @date
 * @author
 * @param
 * @return
 * @Ejemplo
 *
 */

void probarArregloUnidimensional(int arreglo[], int size)
{
  int i;
  printf("\n");

  for(i = 0; i < size; i++)
    {
      arreglo[i] = i; 
    }
  
  for(i = 0; i < size; i++)
    {
      printf("%d\n",arreglo[i]);
      
    }
  
  return;
}
