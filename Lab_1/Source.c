/* Лабораторная работа № 2. Задание № 3.
   Разделить массив на две части, поместив в первую элементы, большие
   среднего арифметического их суммы, а во вторую меньшие (части не сортировать).
*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15  // Если необходима модификация 
#define DIAP 10  // массива.

float averVal(int a[], int size);
void delimiter(int a[], int size, float averageValue);
void delimiter2(int a[], int size, float averageValue);

main()
{
	setlocale(LC_ALL, "Rus");

	int myArray[SIZE];
	int i;
	float averageValue;

	srand(time(NULL)); // Рандомизация значений при каждом запуске программы.

	//Инициализация массива слуачайнымии значениями в диапазоне от 1 до DIAP.
	printf("Сгенерированный массив: ");
	for (i = 0; i < SIZE; i++)
	{
		myArray[i] = 1 + rand() % DIAP;
		printf("%d ", myArray[i]);
	}

	averageValue = averVal(myArray, SIZE);

	printf("\n\nСреднее значение элементов массива: %.2f\n\n", averageValue);

	delimiter(myArray, SIZE, averageValue);//Отдаем массив и среднее арифметическое значение в функцию-разделитель.

	delimiter2(myArray, SIZE, averageValue);//Второй способ решения задачи.

	getchar();
	return 0;
}

float averVal(int a[], int size) //Определяем среднее арифметическое значение элементов массива.
{
	int i;
	float sum = 0;

	for (i = 0; i < size; i++)
		sum += a[i];

	return sum / size;
}

void delimiter(int a[], int size, float averageValue)
{
	int firstPart[SIZE] = { 0 }, secondPart[SIZE] = { 0 };
	int i, j = 0, k = 0;

	for (i = 0; i < size; i++)//Разбиваем исходный массив на два подмассива в соответствии с условием лабораторной.
	{
		if (a[i] <= averageValue)
		{
			firstPart[j] = a[i];
			j++;
		}
		else
		{
			secondPart[k] = a[i];
			k++;
		}
	}

	j = 0, k = 0;//Обнуляем счетчики для дальнейшего использования

	// Выводим на экран результат работы.

	printf("Массив со значениями меньшими среднего арифметического: ");
	while (firstPart[j] != 0)
	{
		printf("%d ", firstPart[j]);
		j++;
	}

	printf("\n\n");

	printf("Массив со значениями большими среднего арифметического: ");
	while (secondPart[k] != 0)
	{
		printf("%d ", secondPart[k]);
		k++;
	}

	printf("\n\n");
}

void delimiter2(int a[], int size, float averageValue)
{
	int i, j, k = 0;

	for (i = 0; i < size; i++)            //Идем по массиву.
	{
		if (a[i] <= averageValue)		  //Если значение элемента меньше среднего 
			for (j = i + 1; j < size; j++)  //начинаем поиск большего значения далее по массиву.
			{
				if (a[j] >= averageValue) //Как только находим большее значение
				{
					k = a[i];			  //меняем местами с меньшим.
					a[i] = a[j];
					a[j] = k;
					break;
				}
			}
	}

	printf("Второй способ решения задачи: ");

	for (i = 0; i <= size - 1; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n\n");
}