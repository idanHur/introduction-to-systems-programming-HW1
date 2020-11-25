#include <stdio.h>
#include <stdlib.h>
#include "genral.h"

void setMatRand(int* mat,int size,int lower,int upper)
 {
 	for(int i = 0; i < size ; i++,mat++)
 		*mat = (rand() % (upper-lower +1)) + lower;
 }

void setMatSequenc(int* mat,int rows,int cols)
{
	for(int i = 0; i < rows*cols; i++,mat++)
		*mat = i;
}

void printMat(const int* mat,int rows,int cols)
{
	printf("\n");
	for(int i = 0; i < rows;i++)
	{
		for(int j = 0; j < cols;j++)
		{
			printf("%2d ",*(mat + i*cols +j));
		}
		printf("\n");
	}
	printf("\n\n");
}

int seekX(const int* arr,int size,int x)
{
	for(int i = 0; i < size; i++)
		if(*(arr+i) == x)
			return i;
	return -1;
}

int isSorted(const int* arr,int size)
{
	for(int i = 0; i < (size - 1);i++)
		if(*(arr + i) > *(arr+ i +1))
			return 0;
	return 1;
}
