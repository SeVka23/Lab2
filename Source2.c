#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <time.h>

void PrintMas(float* mas, int N)
{
  int i = 0;
  for (i = 0; i < N; i++)
  {
    printf("mas[%d] = %f\n", i, mas[i]);
  }
}
void bubbleSort(float* mas, int N)
{
  int i, j;
  float temp = 0;
  for (i = 0; i < N; i++)
  {
    for (j = N - 1; j >= i; j--)
    {
      if (mas[j - 1] > mas[j])
      {
        temp = mas[j - 1];
        mas[j - 1] = mas[j];
        mas[j] = temp;
      }
    }
  }
}
void insertionSort(float* mas, int N)
{
  int i, j;
  float temp;
  for (i = 1; i < N; i++)
  {
    temp = mas[i];
    for (j = i - 1; j >= 0; j--)
    {
      if (mas[j] < temp)
        break;
      mas[j + 1] = mas[j];
      mas[j] = temp;
    }
  }
}
void quickSort(float* mas, int f, int l)
{
  int i = f;
  int j = l;
  float temp = 0;
  float x = mas[(int)((f + l) / 2)];
  do
  {
    while (mas[i] < x)
      i++;
    while (mas[j] > x)
      j--;
    if (i <= j)
    {
      temp = mas[i];
      mas[i] = mas[j];
      mas[j] = temp;
      i++;
      j--;
    }
  } while (i <= j);

  if (i < l)
    quickSort(mas, i, l);
  if (f < j)
    quickSort(mas, f, j);
}
void qSort(float* mas, int N)
{
  quickSort(mas, 0, N - 1);
}
int main()
{
  int N = 0, i = 0, a = 0;
  float* mas = 0;
  float* mas2 = 0;
  FILE* file = 0;
  fopen_s(&file, "C:\\Users\\ADMIN\\source\\repos\\Lab2\\Lab2\\Masmain.txt", "r");
  fscanf_s(file, "N = %d\n", &N);
  mas = (float*)malloc(N * sizeof(float));
  mas2 = (float*)malloc(N * sizeof(float));
  for (i = 0; i < N; i++)
  {
    fscanf_s(file, "%f\n", &(mas[i]));
  }
  fclose(file);
  for (i = 0; i < N; i++)
    mas2[i] = mas[i];
  setlocale(LC_ALL, "Russian");
  printf("Выберите действие:\n1)Печать\n2)Сортировка\n3)Сброс\n4)Выход\n");
  while (a != 4)
  {
    scanf_s("%d", &a);
    if (a == 1)
    {
      PrintMas(mas, N);
    }
    else
      if (a == 2)
      {
        printf("Выбери сортировку:\n1)Пузырьком\n2)Вставкой\n3)Быстрая\n");
        scanf_s("%d", &a);
        if (a == 1)
        {
          clock_t t1 = clock();
          bubbleSort(mas, N);
          clock_t t2 = clock();
          PrintMas(mas, N);
          printf("Время работы = %lf\n", ((double)(t2 - t1))/ CLOCKS_PER_SEC);
        }
        else
          if (a == 2)
          {
            clock_t t1 = clock();
            insertionSort(mas, N);
            clock_t t2 = clock();
            PrintMas(mas, N);
            printf("Время работы = %lf\n", ((double)(t2 - t1)) / CLOCKS_PER_SEC);
          }
          else
            if (a == 3)
            {
              clock_t t1 = clock();
              qSort(mas, N);
              clock_t t2 = clock();
              PrintMas(mas, N);
              printf("Время работы = %lf\n", ((double)(t2 - t1))/ CLOCKS_PER_SEC);
            }
            else
              printf("Такой цифры тут нет\n");
      }
      else
        if (a == 3)
        {
          for (i = 0; i < N; i++)
            mas[i] = mas2[i];
          printf("Сброс выполнен\n");
        }

    if (a == 4)
      printf("Выход успешно выполнен");
  }
  free(mas);
  free(mas2);
  return 0;
}