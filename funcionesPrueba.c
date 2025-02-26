#include "defConvertir.h"

extern void probarArregloUnidimensional(int arreglo[], int size)
{
  int i;
  printf("\n");

  for (i = 0; i < size; i++)
  {
    arreglo[i] = i;
  }

  for (i = 0; i < size; i++)
  {
    printf("%d\n", arreglo[i]);
  }

  return;
}
