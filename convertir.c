/**
 *
 * @file convertir.c
 * @brief Programa que convierte números decimales a binario, octal y hexadecimal.
 * @details Este programa recibe una cantidad de números decimales, los convierte a distintas bases
 *          y muestra los resultados en pantalla. Si el usuario lo especifica, también los guarda en
 *          un archivo de texto.
 * @date 19/febrero/2025
 * @author Mario Ureña García, Ricardo Ponce de León, Emiliano Cisneros
 *
 */

// Bibliotecas --------------------------------------------------------------------------
#include "defConvertir.h"

// Declaración de funciones --------------------------------------------------------------
// Estas funciones se encuentran en "funcionesPrincipales.c".

void ingresarDatos(int *arreglo, int dimensionArreglo);
void convertirBasesNumericas(int *arregloEntradas, tipoConversion *arregloSalidas, int dimensionArreglo);
void crearArchivo(int *arregloEntradas, tipoConversion *arregloSalidas, int dimensionArreglo, char *conversionSolicitada);
void imprimirDatos(int *arregloEntradas, tipoConversion *arregloSalidas, int dimensionArreglo);
// Main ---------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
  //-------------------------------------------------------------------------------------
  // VARIABLES
  int *arregloEntradas;           // Puntero al arreglo donde se almacenarán los números ingresados por el usuario.
  tipoConversion *arregloSalidas; // Puntero al arreglo donde se almacenarán los resultados de conversión.
  int dimensionArreglo;           // Número total de valores a convertir.
  int i;                          // Variable de control para iteraciones.

  //-------------------------------------------------------------------------------------
  // VALIDACIÓN DE ARGUMENTOS
  // Se verifica que el usuario haya ingresado al menos el tamaño del arreglo en la línea de comandos.
  if (argc < 2)
  {
    printf(RED "\n\n\tError: " RESET "No ingresaste suficientes argumentos.\n\n");
    printf("\tUso: %s <cantidad de números> [opcional: binario, octal, hexadecimal]\n\n", argv[0]);
    exit(2);
  }

  // Convertir el argumento (cantidad de números) de cadena a entero.
  sscanf(argv[1], "%d", &dimensionArreglo);

  //-------------------------------------------------------------------------------------
  // RESERVA DE MEMORIA PARA LOS NÚMEROS INGRESADOS
  arregloEntradas = (int *)malloc(dimensionArreglo * sizeof(int));
  if (arregloEntradas == NULL) // Si la memoria no se pudo asignar, mostrar error y salir.
  {
    printf(RED "\n\n\tError: " RESET "No hay suficiente memoria disponible.\n\n");
    exit(1);
  }

  //-------------------------------------------------------------------------------------
  // INGRESO DE DATOS POR EL USUARIO
  ingresarDatos(arregloEntradas, dimensionArreglo);

  //-------------------------------------------------------------------------------------
  // RESERVA DE MEMORIA PARA LOS RESULTADOS DE CONVERSIÓN
  arregloSalidas = (tipoConversion *)malloc(dimensionArreglo * sizeof(tipoConversion));
  if (arregloSalidas == NULL) // Si la memoria no se pudo asignar, mostrar error y salir.
  {
    printf(RED "\n\n\tError: " RESET "No hay suficiente memoria disponible.\n\n");
    free(arregloEntradas); // Liberar la memoria previamente asignada antes de salir.
    exit(1);
  }

  //-------------------------------------------------------------------------------------
  // CONVERSIÓN DE LOS NÚMEROS INGRESADOS A BINARIO, OCTAL Y HEXADECIMAL
  convertirBasesNumericas(arregloEntradas, arregloSalidas, dimensionArreglo);

  //-------------------------------------------------------------------------------------
  // GUARDADO DE RESULTADOS EN ARCHIVO (SI EL USUARIO LO SOLICITÓ)
  // Si el usuario ingresó un tercer argumento (base de conversión), se guarda la conversión en un archivo.
  if (argc == 3)
  {
    crearArchivo(arregloEntradas, arregloSalidas, dimensionArreglo, argv[2]);
  }

  //-------------------------------------------------------------------------------------
  // IMPRESIÓN DE LOS RESULTADOS EN PANTALLA
  imprimirDatos(arregloEntradas, arregloSalidas, dimensionArreglo);
  //-------------------------------------------------------------------------------------
  // LIBERACIÓN DE MEMORIA DINÁMICA
  // Se libera la memoria asignada dinámicamente para evitar fugas de memoria.
  free(arregloEntradas);
  free(arregloSalidas);

  //-------------------------------------------------------------------------------------
  // FINALIZACIÓN DEL PROGRAMA
  printf("\n\n\tPrograma Finalizado con " GREEN "ÉXITO\n\n" RESET);
  return 0;
}
