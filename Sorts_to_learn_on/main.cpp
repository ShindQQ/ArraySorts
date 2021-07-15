#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define CONST_HIGH_RAND_VALUE 100
#define CONST_LOW_RAND_VALUE -50
#define CONST_ARRAY_SIZE 10

// Sorts created for learning
// BogoSort O(N*N!)

void swap(int& arg1, int& arg2);

// BogoSort

int isArraySorted(int* arr, int size);
int* shuffle(int* arr, int size);
int* bogoSort(int* arr, int size);

int main()
{
	int* arr = (int*)malloc(sizeof(int) * CONST_ARRAY_SIZE);
	int num;

	srand(time(NULL));

	printf("Unsorted array:\n\n");
	for (int i = 0; i < CONST_ARRAY_SIZE; i++)
	{
		 num = CONST_LOW_RAND_VALUE + rand() % CONST_HIGH_RAND_VALUE;
		 printf("%d ", num);
		 arr[i] = num;
	}
	puts("\n");

	clock_t begin = clock();
	
	bogoSort(arr, CONST_ARRAY_SIZE); // time from 0 to 8.665000

	clock_t end = clock();

	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time spent on sorting: %lf;\n\n", time_spent);
	printf("Sorted array:\n\n");

	for (int i = 0; i < CONST_ARRAY_SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("");

	free(arr);
	return 0;
}

void swap(int& arg1, int& arg2)
{
	int tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

int isArraySorted(int* arr, int size)
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

int* shuffle(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		swap(arr[i], arr[(rand() % size)]);
	}

	return arr;
}

int* bogoSort(int* arr, int size)
{
	while (!isArraySorted(arr, size))
	{
		arr = shuffle(arr, size);
	}

	return arr;
}