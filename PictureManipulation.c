#include <stdio.h>
#include <ctype.h>
#include "PictureManipulation.h"
#include "genral.h"


 void PictureManipulation()
 {
 	int mat[SIZE][SIZE] ={};
 	setMatRand((int*)mat,SIZE*SIZE,LOWER,UPPER);
 	printMat((int*) mat,SIZE,SIZE);	
 	playGame((int*) mat,SIZE);
 }
void playGame(int* mat,int size)
{
	int choice = 0;
 	while(choice != -1)
 	{
 		printMenu();
 		scanf("%d", &choice);
 		makeChoise(mat,size,&choice);
 	}
}

void makeChoise(int* mat,int size,int* choice)
{
	switch(*choice)
 		{
 			case CLOCKWISE:
 				clockwiseFlipMat(mat,size);
 				break;
 			case COUNTER_CLOCKWISE:
 				counterClockwiseFlipMat(mat,size);
 				break;
 			case HORIZONTAL:
 				horizontalFlip(mat,size);
 				break;	
 			case VERTICAL:
 				verticalFlip(mat,size);
 				break;
 		}	
 		if(*choice <= 4 && *choice >= 1)
 		{
 			printf("\n\n--------- picture after manipulation ---------\n");
			printMat(mat,size,size);	
		}
}

void printMenu()
{
	printf("Please choose one of the following options \n");
 	printf("1 - 90 degree clockwise \n");
 	printf("2 - 90 degree counter clockwise \n");
 	printf("3 - Flip Horizontal \n");
 	printf("4 - Flip Vertical \n");
 	printf("-1 - Quit \n");
}

void clockwiseFlipMat(int* mat,int size)
{
 	int temp;
 	for(int i = 0; i < (size/2);i++)
 		 for(int j = i; j < (size - 1 - i);j++)
 		 {
 		 	temp = *(mat + i*(size) + j);
 		 	*(mat + i*(size) + j) = *(mat + size*(size-1-j)+i);
 		 	*(mat + size*(size-1-j)+i) = *(mat + size*(size-i) -1 -j);
 		 	*(mat + size*(size-i) -1 -j) = *(mat + size*(1+j) -1-i);
 		 	*(mat + size*(1+j) -1-i) = temp;
 		 }		
}
void counterClockwiseFlipMat(int* mat,int size)
{
 	int temp;
 	for(int i = 0; i < (size/2);i++)
 		 for(int j = i; j < (size - 1 - i);j++)
 		 {
 		 	temp = *(mat + size*(size-1-j)+i);
 		 	*(mat + size*(size-1-j)+i) = *(mat + i*(size) + j);
 		 	*(mat + i*(size) + j) = *(mat + size*(1+j) -1-i);
 		 	*(mat + size*(1+j) -1-i) = *(mat + size*(size-i) -1 -j);
 		 	*(mat + size*(size-i) -1 -j) = temp;
 		 }		
}

void verticalFlip(int* mat,int size)
{
	int temp;
	for(int i = 0; i < (size/2);i++)
		for(int j = 0; j < size;j++)
		{
			temp = *(mat + j*size + i);
			*(mat + j*size + i) = *(mat + j*size + size -1 -i);
			*(mat + j*size + size -1 -i) = temp;
		}
}	
void horizontalFlip(int* mat,int size)
{
	int temp;
	for(int i = 0; i < (size/2);i++)
		for(int j = 0; j < size;j++)
		{
			temp = *(mat + i*size + j);
			*(mat + i*size + j) = *(mat + size*(size-1-i)+j);
			*(mat + size*(size-1-i)+j) = temp;
		}
}	

