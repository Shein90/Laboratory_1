/* ������������ ������ � 2. ������� � 3.
   ��������� ������ �� ��� �����, �������� � ������ ��������, �������
   �������� ��������������� �� �����, � �� ������ ������� (����� �� �����������).
*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15  // ���� ���������� ����������� 
#define DIAP 10  // �������.

float averVal(int a[], int size);
void delimiter(int a[], int size, float averageValue);
void delimiter2(int a[], int size, float averageValue);

main()
{
	setlocale(LC_ALL, "Rus");

	int myArray[SIZE];
	int i;
	float averageValue;

	srand(time(NULL)); // ������������ �������� ��� ������ ������� ���������.

	//������������� ������� ������������ ���������� � ��������� �� 1 �� DIAP.
	printf("��������������� ������: ");
	for (i = 0; i < SIZE; i++)
	{
		myArray[i] = 1 + rand() % DIAP;
		printf("%d ", myArray[i]);
	}

	averageValue = averVal(myArray, SIZE);

	printf("\n\n������� �������� ��������� �������: %.2f\n\n", averageValue);

	delimiter(myArray, SIZE, averageValue);//������ ������ � ������� �������������� �������� � �������-�����������.

	delimiter2(myArray, SIZE, averageValue);//������ ������ ������� ������.

	getchar();
	return 0;
}

float averVal(int a[], int size) //���������� ������� �������������� �������� ��������� �������.
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

	for (i = 0; i < size; i++)//��������� �������� ������ �� ��� ���������� � ������������ � �������� ������������.
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

	j = 0, k = 0;//�������� �������� ��� ����������� �������������

	// ������� �� ����� ��������� ������.

	printf("������ �� ���������� �������� �������� ���������������: ");
	while (firstPart[j] != 0)
	{
		printf("%d ", firstPart[j]);
		j++;
	}

	printf("\n\n");

	printf("������ �� ���������� �������� �������� ���������������: ");
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

	for (i = 0; i < size; i++)            //���� �� �������.
	{
		if (a[i] <= averageValue)		  //���� �������� �������� ������ �������� 
			for (j = i + 1; j < size; j++)  //�������� ����� �������� �������� ����� �� �������.
			{
				if (a[j] >= averageValue) //��� ������ ������� ������� ��������
				{
					k = a[i];			  //������ ������� � �������.
					a[i] = a[j];
					a[j] = k;
					break;
				}
			}
	}

	printf("������ ������ ������� ������: ");

	for (i = 0; i <= size - 1; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n\n");
}