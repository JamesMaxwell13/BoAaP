#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "header.h"

// В одномерном массиве выполнить сортировку четных элементов методом выбора

void selectionEvenSort(int *arr,int size)
{
    int buff;
    int min;
    for(int i=0;i<size-1; i++) // выбор исходного элемента к сравнению
    { 
        if(arr[i]%2==0)
        {
            min=i; 
            for(int j=i+1; j<size; j++) // просмотр массива ”снизу вверх”
                if(arr[min]>arr[j] && arr[j]%2==0) 
                    min=j; // фиксируем координату элемента в массиве
                    buff=arr[i]; // замена min и i элементов
                    arr[i]=arr[min];
                    arr[min]=buff;
        }
    }
}

void task_1()
{
	int size;
	int *arr;
    printf("Enter the size of array: ");
	size=inputPosInt();

    arr=(int*)malloc(size*sizeof(int));

    fillArr(arr,size);

    selectionEvenSort(arr,size);

	printf("\n");
    for(int i=0;i<size;i++)
    {
        if(arr[i]%2==0)
            printf("\033[35m%4d\033[0m",arr[i]);
        else
            printf("%4d",arr[i]);
    }
    free(arr);
}

// В матрице размером NxM выполнить сортировку строк по возрастанию суммы четных элементов методом слияния

void merge(int **arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int **L, **R;
 
	L=(int**)malloc(n1*sizeof(int*));
	R=(int**)malloc(n2*sizeof(int*));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i][0] <= R[j][0]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int **arr, int l, int r)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void task_2()
{
    int size1,size2;
    int **arr;

    printf("Enter the height of matrix: ");
	size1=inputPosInt();

    printf("Enter the width of matrix: ");
	size2=inputPosInt();

    //making and filling array
    arr=(int**)malloc(size1*sizeof(int*));
    for(int i=0;i<size1;i++)
        arr[i]=(int*)malloc(size2*sizeof(int));
    fillMatrix(arr,size1,size2);

	size2++;
    for(int i=0;i<size1;i++)
        arr[i]=(int*)realloc(arr[i],size2*sizeof(int));

    for(int i=0;i<size1;i++)
    {
        for(int j=size2-1;j>0;j--)
            arr[i][j]=arr[i][j-1];
    }

    for(int i=0;i<size1;i++)
    {
        arr[i][0]=0;
        for(int j=1;j<size2;j++)
        {    
			if(arr[i][j]%2==0)
                arr[i][0]+=arr[i][j];
		}
	}

    for(int i=0;i<size1;i++)
    {
        printf("Sum[%d]: \033[35m%4d\033[0m",i,arr[i][0]); 
        printf("\n");
    }

    mergeSort(arr,0,size1-1);   

	printf("\n");
    for(int i=0;i<size1;i++)
    {
        for(int j=1;j<size2;j++)
            printf("%4d",arr[i][j]); 
        printf("\n");
    }
}

int main()
{
    int task=0;
    while(task!=-1)
    {
    printf("Choose number of task(enter -1 for exit): ");
    scanf("%d",&task);
    {
        switch (task)
        {
        case 1:
        {
            printf("\nIn a one-dimensional array, sort the even elements using the selection method\n\n");
            task_1();
            break;
        }
        case 2:
        {
            printf("\nIn an NxM matrix, sort the rows in ascending order by the sum of even elements\n\
using the merge method\n\n");
            task_2();
            break;
        }
        case -1:
        {
            exit(0);
        }
        default:
        printf("Incorrect input number of task, try again");
        }
        getch();
        system("cls");
    }
    }
    getch();
    return 0;
}







// void merge(int arr[], int l, int m, int r)
// {
//     int i, j, k;
//     int n1 = m - l + 1;
//     int n2 = r - m;
 
//     // Create temp arrays
//     int L[n1], R[n2];
 
//     // Copy data to temp arrays 
//     // L[] and R[] 
//     for (i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];
 
//     // Merge the temp arrays back 
//     // into arr[l..r]
//     // Initial index of first subarray
//     i = 0; 
 
//     // Initial index of second subarray
//     j = 0; 
 
//     // Initial index of merged subarray
//     k = l; 
//     while (i < n1 && j < n2) 
//     {
//         if (L[i] <= R[j]) 
//         {
//             arr[k] = L[i];
//             i++;
//         }
//         else 
//         {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
 
//     // Copy the remaining elements 
//     // of L[], if there are any
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
 
//     // Copy the remaining elements of 
//     // R[], if there are any 
//     while (j < n2) 
//     {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }
 
// // l is for left index and r is 
// // right index of the sub-array 
// // of arr to be sorted 
// void mergeSort(int arr[], int l, int r)
// {
//     if (l < r) 
//     {
//         // Same as (l+r)/2, but avoids 
//         // overflow for large l and h
//         int m = l + (r - l) / 2;
 
//         // Sort first and second halves
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);
 
//         merge(arr, l, m, r);
//     }
// }