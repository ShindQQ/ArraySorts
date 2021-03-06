#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define CONST_ARRAY_SIZE 10000
#define CONST_10k 10000
#define CONST__5k -5000

// Sorts O(N^2)
// Insert
// Bubble
// Choice
// Shaker

void swap(int& arg1, int& arg2);

// InsertSort

int* insertSort(int* arr, int size);

// BubbleSort

int* bubbleSort(int* arr, int size);

// ChoiceSort

int* choiceSort(int* arr, int size);

// ShakerSort

int* shakerSort(int* arr, int size);

int main()
{
    FILE* fp;
    char filename[] = "file.txt";
    int num;
    int arr_size = CONST_ARRAY_SIZE;
    int* arr = (int*)malloc(sizeof(int) * arr_size);
    fp = fopen(filename, "w+");

    srand(time(NULL));

    printf("Unsorted array:\n\n");
    for (int i = 0; i < arr_size; i++)
    {
        num = CONST__5k + rand() % CONST_10k;
        fprintf(fp, "%d ", num);
        printf("%d ", num);
    }
    puts("\n");
    fclose(fp);

    fp = fopen(filename, "r+");

    for (int i = 0; i < arr_size; i++)
    {
        fscanf(fp, "%d ", &arr[i]);
    }

    fclose(fp);

    clock_t begin = clock();

    // insertSort(arr, arr_size); // time 0.603000
    // bubbleSort(arr, arr_size); // time  1.231000
    // choiceSort(arr, arr_size); // time 0.174000
    shakerSort(arr, arr_size); // time 0.990000

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time spent on sorting: %lf;\n\n", time_spent);
    printf("Sorted array:\n\n");

    for (int i = 0; i < arr_size; i++)
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

int* insertSort(int* arr, int size)
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

int* bubbleSort(int* arr, int size)
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

int* choiceSort(int* arr, int size)
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

int* shakerSort(int* arr, int size)
{
    int left_border = 0;
    int right_border = size - 1;

    while (left_border <= right_border)
    {
        for (int i = right_border; i > left_border; i--)
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
