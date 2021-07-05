#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <time.h>

#define CONST_10k 10000
#define CONST__5k -5000

// Sorts O faster than O*N*log(N)
// CountSort
// BucketSort

void swap(int& arg1, int& arg2);

// CountSort
int FindSmallest(int* arr, int size);
int FindBiggest(int* arr, int size);
int* CountSort(int* arr, int size, int biggest, int smallest);

int main()
{
    FILE* fp;
    char filename[] = "file.txt";
    int num;
    int* arr = (int*)malloc(sizeof(int) * CONST_10k);
    fp = fopen(filename, "w+");

    srand(time(NULL));
    for (int i = 0; i < CONST_10k; i++)
    {
        num = CONST__5k + rand() % CONST_10k;
        fprintf(fp, "%d ", num);
        printf("%d ", num);
    }
    puts("\n");
    fclose(fp);

    fp = fopen(filename, "r+");

    for (int i = 0; i < CONST_10k; i++)
    {
        fscanf(fp, "%d ", &arr[i]);
    }

    fclose(fp);

    arr = CountSort(arr, CONST_10k, FindBiggest(arr, CONST_10k), FindSmallest(arr, CONST_10k));

    for (int i = 0; i < CONST_10k; i++)
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

int FindSmallest(int* arr, int size)
{
    int smallest = 0;
    for (int i = 0; i < size; i++)
    {
        if (smallest > arr[i])
        {
            smallest = arr[i];
        }
    }
    return smallest;
}

int FindBiggest(int* arr, int size)
{
    int biggest = 0;
    for (int i = 0; i < size; i++)
    {
        if (biggest < arr[i])
        {
            biggest = arr[i];
        }
    }
    return biggest;
}

int* CountSort(int* arr, int size, int biggest, int smallest)
{
    int* tmp_arr = NULL;
    int iterator = 0;
    int tmp_size = biggest + abs(smallest) + 1;
    if (!(tmp_arr = (int*)calloc(tmp_size, sizeof(int))))
    {
        printf("Not enough memory for array! LINE: %d", __LINE__);
        exit(1);
    }
    for (int i = 0; i < size; i++)
    {
        tmp_arr[arr[i] + abs(smallest)]++;
    }
    for (int i = 0; i < tmp_size; i++)
    {
        for (int j = 0; j < tmp_arr[i]; j++)
        {
            arr[iterator] = smallest + i;
            iterator++;
        }
    }
    free(tmp_arr);
    return arr;
}
