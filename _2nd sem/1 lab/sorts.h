#pragma once
#include <stdio.h>
#include <stdlib.h>


void mergeSort(int *arr, int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);   
        mergeSort(arr, m + 1, r);

		int i, j, k;

		int n1 = m - l + 1;
		int n2 = r - m;
		
		int *L, *R;
		L=(int*)malloc(n1*sizeof(int));
		R=(int*)malloc(n2*sizeof(int));
		
		for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
		for (j = 0; j < n2; j++)            
		R[j] = arr[m + 1 + j];           
		
		i = 0; 
		j = 0; 
		k = l; 
		while (i < n1 && j < n2) 
		{
			if (L[i] <= R[j]) 
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

		free(L);
		free(R);
    }
}


void HoarSort(int *arr, int l, int r) 
{
    int i, j, temp;
    int sr = arr[(l + r) / 2]; 
    i = l; 
    j = r; 
    
    do
    {
    	while (arr[i] < sr) 
        i++;                        // ищем слева элемент больше среднего
        	while (arr[j] > sr) 
            j--;                    // ищем справа элемент меньше среднего
            	if (i <= j)         // если левая граница не прошла за правую
            	{
        	    	temp = arr[i]; 
        		    arr[i] = arr[j];
        		    arr[j] = temp;
                    i++; 
                    j--; 
        	    }
    } 
    while (i <= j);                 // пока границы не совпали
        
        if (i < r) 
        	HoarSort(arr, i, r); 
        if (j>l)  
        	HoarSort(arr, l, j); 
}


void ShellSort(int *arr,int size)
{   
    int flg;
    int buff;
    for(int gap = size/2; gap > 0; gap /= 2)
        do 
        {
            flg = 0;
            for(int i = 0, j = gap; j < size; i++, j++)
                if(arr[i] > arr[j])         // сравниваем отстоящие на gap 	элементы
                { 
                    buff = arr[j];
                    arr[j] = arr[i];
                    arr[i]= buff;
                    flg = 1;                // есть еще не рассортированные данные
                }
        } 
        while (flg!=0);                     // окончание этапа сортировки
}


void insertionSort(int *arr,int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void selectionSort(int *arr,int size)
{
    int buff;
    int min;
    for(int i=0;i<size; i++)              // выбор исходного элемента к сравнению
    { 
        min=i; 
        for(int j=i+1; j<size; j++)         // просмотр массива ”снизу” ”вверх”
            if(arr[min]>arr[j]) 
                min=j;                      // фиксируем координату элемента в массиве
                buff=arr[i];                // замена min и i элементов
                arr[i]=arr[min];
                arr[min]=buff;
    }
}


void bubbleSort(int *arr,int size)
{
    int buff=0;
    for(int i=0;i<size;i++)                 // выбор верхней границы массива
    {
        for(int j=size-1;j>i;--j)           // просмотр массива ”снизу” ”вверх”
	    {
            if(arr[j-1]>arr[j])             // условие замены выполнено
            {
                buff=arr[j-1];                  // замена j-1 и j элементов
                arr[j-1]=arr[j];
                arr[j]=buff;
            }
        }
    }
}

// void MergeSort(int *arr,int l,int r) {
// if(l<r) {
//     int m=(l+r)/2;
//     MergeSort(arr,l,m);
//     MergeSort(arr,m+1,r);
//     int n1=m-l+1;
//     int n2=r-m;
//     int i=0,j=0,k=l;
//     int *L,*R;
//     L=(int*)malloc(n1*sizeof(int));
//     R=(int*)malloc(n2*sizeof(int));
//     for(int a=0;a<n1;a++)
//         L[a]=arr[l+a];
//     for(int b=0;b<n2;b++)
//         R[b]=arr[m+1+b];
//     while(i<n1 && j<n2) {
//         if(L[i]<=R[j]) {
//             arr[k]=L[i];
//             i++; }
//         else {
//             arr[k]=R[j];
//             j++; }
//         k++; }
//     while(i<n1) {
//         arr[k]=L[i];
//         i++; 
//         k++; }
//     while(j<n2) {
//         arr[k]=R[j];
//         j++; 
//         k++; } } }

// void HoarSort(int *arr,int l,int r) {
//     int sr=arr[(l+r)/2];
//     int i=l, j=r, temp;
//     while(arr[i]<sr) { i++;
//         while(arr[j]>sr) { j--;
//             if(i<=j) {
//                 temp=arr[i];
//                 arr[i]=arr[j];
//                 arr[j]=temp;
//                 i++;
//                 j--; } }
//     if(i<r) HoarSort(arr,i,r);
//     if(j>l) HoarSort(arr,l,j);
//     }
// }

// void ShellSort(int *arr,int size) {
//     int flg,temp;
//     for(int gap=size/2;gap>0;gap/=2) {
//         do { flg=0;
//         for(int i=0,j=gap;j<size;i++,j++) 
//         if(arr[i]>arr[j]){
//             temp=arr[i];
//             arr[i]=arr[j];
//             arr[j]=temp;
//             flg=1; }
//         } while(flg!=0) } }

// void InsertSort(int *arr,int size) {
//     int key;
//     for(int i=0;i<size;i++) {
//         key=arr[i];
//         j=i-1;
//         while(j>=0 && arr[j]>key) {
//             arr[j+1]=arr[j];
//             j--; }
//         arr[j+1]=key; } }