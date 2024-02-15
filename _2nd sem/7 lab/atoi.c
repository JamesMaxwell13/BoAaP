#include "funcs.h"

int main()
{
	int *arr = (int*)malloc(sizeof(int));
	int size = getArr(arr);

	printf("size - %d\n", size);
	for(int i = 0; i < size; i++)	
	{
		printf("  %d", arr[i]);
	}
	getch();
	return 0;
}



// if(str[i] > '0' && str[i] < '9')
// 			if(num == false)
// 			{
// 				bgn = i;
// 				end = i;
// 				num = true;
// 			}
// 			else
// 				end++;
// 		else
// 			if(num == true)
// 			{
// 				buff[size] = (char*)malloc((end-bgn+2)*sizeof(char));
// 				int k = 0;
// 				for(int j = bgn; j <= end; j++, k++)
// 					buff[size][k] = str[j];
// 				buff[size][k + 1] = '\0';
// 				num = false;
// 				size++;

// 				if(endArr(str, i) == false)
// 					buff = (char**)realloc(buff, (size + 1)*sizeof(char*));
// 				free(buff);
// 			}
// 		i++;
// 	}

// 	arr = (int*)malloc(size*sizeof(int));
// 	for(int j = 0; j < size; j++)
// 		arr[j] = atoi(buff[j]);