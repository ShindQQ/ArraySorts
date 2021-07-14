#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <time.h>

#define CONST_ARRAY_SIZE 10000
#define CONST_10k 10000
#define CONST__5k -5000

// Sorts O(N*log(N))
// Shell
// Quick
// Merge

void swap(int& arg1, int& arg2);

// ShellSort
int* shellSort(int* arr, int size);

// QuickSort
int* quickSort(int* arr, int left_border, int right_border);

// MergeSort

int* mergeSort(int* arr, int begin_position, int end_position);
int* merge(int* arr, int begin_position, int middle_position, int end_position);

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

    // shellSort(arr, arr_size); // time 0.344000
    // quickSort(arr, 0, arr_size); // time 0.002000
    mergeSort(arr, 0, arr_size - 1); // time 0.020000

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

int* shellSort(int* arr, int size)
{
    for (int k = size / 2; k > 0; k /= 2)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + k; j < size; j += k)
            {
                if (arr[i] > arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    return arr;
}

int* quickSort(int* arr, int left_border, int right_border)
{
    int i = left_border;
    int j = right_border - 1;
    int middle_of_array = arr[(left_border + right_border) / 2];

    while (i <= j)
    {
        while (arr[i] < middle_of_array)
        {
            i++;
        }
        while (arr[j] > middle_of_array)
        {
            j--;
        }
        if (i <= j)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
            i++;
            j--;
        }
    }

    if (left_border < j)
    {
        arr = quickSort(arr, left_border, j);
    }
    else if (i < right_border)
    {
        arr = quickSort(arr, i, right_border);
    }

    return arr;
}

int* mergeSort(int* arr, int begin_border, int end_border)
{
    int middle_position = (begin_border + end_border) / 2;
    
    if (begin_border < end_border)
    {
        arr = mergeSort(arr, begin_border, middle_position);
        arr = mergeSort(arr, middle_position + 1, end_border);
        arr = merge(arr, begin_border, middle_position, end_border);
    }

    return arr;
}

int* merge(int* arr, int begin_position, int middle_position, int end_position)
{
    int left = begin_position;
    int centre = middle_position + 1;
    int index = begin_position;
    int size = end_position + 1;
    int* temp = (int*)malloc(sizeof(int) * size);

    while (left <= middle_position && centre <= end_position)
    {
        if (arr[left] < arr[centre])
        {
            temp[index] = arr[left];
            left++;
        }
        else if (arr[left] >= arr[centre])
        {
            temp[index] = arr[centre];
            centre++;
        }
        index++;
    }

    if (left > middle_position)
    {
        while (centre <= end_position)
        {
            temp[index] = arr[centre];
            centre++;
            index++;
        }
    }
    else if (left <= middle_position)
    {
        while (left <= middle_position)
        {
            temp[index] = arr[left];
            left++;
            index++;
        }
    }

    for (int i = begin_position; i < index; i++)
    {
        arr[i] = temp[i];
    }

    free(temp);

    return arr;
}