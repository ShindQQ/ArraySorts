#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <time.h>

#define CONST_HIGH_RAND_VALUE 100
#define CONST_LOW_RAND_VALUE -50
#define CONST_ARRAY_SIZE 10

// Sorts created for learning
// BogoSort O(N*N!)

void swap(int& arg1, int& arg2);

// BogoSort
int Correct(int* arr, int size);
int* Shuffle(int* arr, int size);
int* BogoSort(int* arr, int size);

int main()
{
	int* arr = (int*)malloc(sizeof(int) * CONST_ARRAY_SIZE);
	int num;

	srand(time(NULL));

	for (int i = 0; i < CONST_ARRAY_SIZE; i++)
	{
		 num = CONST_LOW_RAND_VALUE + rand() % CONST_HIGH_RAND_VALUE;
		 printf("%d ", num);
		 arr[i] = num;
	}
	puts("");

	BogoSort(arr, CONST_ARRAY_SIZE);

	for (int i = 0; i < CONST_ARRAY_SIZE; i++)
	{
		printf("%d ", arr[i]);
	}

	free(arr);
	return 0;
}

void swap(int& arg1, int& arg2)
{
	int tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

int Correct(int* arr, int size)
{
	while (size-- > 0)
	{
		if (arr[size - 1] > arr[size])
		{
			return 0;
		}
	}
	return 1;
}

int* Shuffle(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		swap(arr[i], arr[(rand() % size)]);
	}
	return arr;
}

int* BogoSort(int* arr, int size)
{
	while (!Correct(arr, size))
	{
		arr = Shuffle(arr, size);
	}
	return arr;
}
