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

// Sorts O(N^2)
// Insert
// Bubble
// Choice
// Shaker

void swap(int& arg1, int& arg2);
int* InsertSort(int* arr, int size);
int* BubbleSort(int* arr, int size);
int* ChoiceSort(int* arr, int size);
int* ShakerSort(int* arr, int size);

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

    //InsertSort(arr, CONST_10k);
    //BubbleSort(arr, CONST_10k);
    //ChoiceSort(arr, CONST_10k);
    ShakerSort(arr, CONST_10k);

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

int* InsertSort(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
        {
            swap(arr[j - 1], arr[j]);
        }
    }
    return arr;
}

int* BubbleSort(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

int* ChoiceSort(int* arr, int size)
{
    int min = 0;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    return arr;
}

int* ShakerSort(int* arr, int size)
{
    int left_border = 0;
    int right_border = size - 1;
    while (left_border <= right_border)
    {
        for (int i = right_border; i >= left_border; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
            }
        }
        left_border++;
        for (int j = left_border; j <= right_border; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
        right_border--;
    }
    return arr;
}