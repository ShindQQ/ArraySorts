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

// Sorts O faster than O*N*log(N)
// CountSort
// BucketSort

void swap(int& arg1, int& arg2);

// CountSort

int findSmallest(int* arr, int size);
int findBiggest(int* arr, int size);
int* countSort(int* arr, int size, int biggest, int smallest);

//BucketSort

struct Bucket
{
    int count;
    int* values;
};

int compareIntegers(const void* first, const void* second);
int* bucketSort(int* arr, int size);

int main()
{
    FILE* fp;
    char filename[] = "file.txt";
    int num;
    int arr_size = CONST_ARRAY_SIZE;
    int* arr = (int*)malloc(sizeof(int) * arr_size);
    fp = fopen(filename, "w+");

    srand(time(NULL));
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

    //countSort(arr, arr_size, findBiggest(arr, arr_size), findSmallest(arr, arr_size));
    bucketSort(arr, arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

int compareIntegers(const void* first, const void* second)
{
    const int a = *((const int*)first);
    const int b = *((const int*)second);
    if (a == b)
    {
        return 0;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int* bucketSort(int* arr, int size)
{
    struct Bucket buckets[2];
    for (int i = 0; i < 2; i++)
    {
        buckets[i].count = 0;
        if (!(buckets[i].values = (int*)malloc(sizeof(int) * size)))
        {
            return NULL;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            buckets[0].values[buckets[0].count++] = arr[i];
        }
        else
        {
            buckets[1].values[buckets[1].count++] = arr[i];
        }
    }
    for (int i = 0, j = 0; i < 2; i++)
    {
        qsort(buckets[i].values, buckets[i].count, sizeof(int), &compareIntegers);
        for (int k = 0; k < buckets[i].count; k++)
        {
            arr[j + k] = buckets[i].values[k];
        }
        j += buckets[i].count;
        free(buckets[i].values);
    }
    return arr;
}

void swap(int& arg1, int& arg2)
{
    int tmp = arg1;
    arg1 = arg2;
    arg2 = tmp;
}

int findSmallest(int* arr, int size)
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

int findBiggest(int* arr, int size)
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

int* countSort(int* arr, int size, int biggest, int smallest)
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
