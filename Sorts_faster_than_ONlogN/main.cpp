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
// CountSort
// BucketSort

void swap(int& arg1, int& arg2);

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
