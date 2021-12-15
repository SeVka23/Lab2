#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
  int N = 0, min = 0, max = 0, i = 0;
  float* mas = 0;
  printf("N =\t");
  scanf_s("%d", &N);
  if (N <= 0)
  {
    printf("ERROR N<=0!!!");
    return 0;
  }
  printf("Min =\t");
  scanf_s("%d", &min);
  printf("Max =\t");
  scanf_s("%d", &max);
  if (max < min)
  {
    printf("ERROR max<min!!!");
    return 0;
  }
  mas = (float*)malloc(N * sizeof(float));
  if (mas == 0)
  {
    printf("ERROR mas1 == 0!!!");
    return 0;
  }
  for (i = 0; i < N; i++)
  {
    mas[i] = ((float)rand() / RAND_MAX) * (max - min) + min;
    //printf("mas[%d] = %f\n", i, mas[i]);
  }
  FILE* file = 0;
  fopen_s(&file, "Masmain.txt", "w");
  fprintf(file, "N = %d\n", N);
  for (i = 0; i < N; i++)
  {
    fprintf(file, "%f\n", mas[i]);
  }
  fclose(file);
  free(mas);
  return 0;
}