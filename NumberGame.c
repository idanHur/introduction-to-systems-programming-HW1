#include <stdio.h>
#include <stdlib.h>
#include "NumberGame.h"
#include "genral.h"

void NumberGame()
{
	int mat[ROWS][COLS];
	setMatSequenc((int*) mat,ROWS,COLS);
	int zeroInRow = 0;
	int zeroInCol = 0;
	suffleMat((int*) mat,ROWS,COLS,&zeroInRow,&zeroInCol);
	playNumberGame((int*) mat,ROWS,COLS,&zeroInRow,&zeroInCol);
}

void playNumberGame(int* mat,int rows,int cols,int* zeroInRow,int* zeroInCol)
{
	char gameInProgres = 1;
	int sorted = 0;
	int choiseToMove,indexToMove;
	do
	{
		printMat(mat, rows, cols);
		sorted = isSorted(mat,rows*cols);
		if(sorted == 1)
		{
			printf("You Win The game is over!\n");
			gameInProgres = 0; 
			continue;
		}
		printf("Your step: ");
		scanf("%d",&choiseToMove); 		
		indexToMove = seekX(mat,rows*cols,choiseToMove);
		if(isValidMove( mat,rows, cols, zeroInRow, zeroInCol,indexToMove) == 0)
			printf("\nInvalid step!\n");
	}while(gameInProgres);
}

int isValidMove(int* mat,int rows,int cols,int* zeroInRow,int* zeroInCol,int indexToMove)
{
	if(indexToMove == -1)
		return 0;
		
	int colToMove = *zeroInCol - (indexToMove % cols);
	int rowToMove =	*zeroInRow - (indexToMove / cols);
	
	if(colToMove == 1 && rowToMove == 0)
		return moveLeft(mat, cols,zeroInRow, zeroInCol);
		
	if(colToMove == -1 && rowToMove == 0)
		return moveRight( mat, cols, zeroInRow, zeroInCol);
		
	if(rowToMove == 1 && colToMove == 0)
		return moveUp(mat, cols,zeroInRow, zeroInCol);
		
	if(rowToMove == -1 && colToMove == 0)
		return moveDown(mat, cols,rows, zeroInRow, zeroInCol);
		
	return 0;
}

void suffleMat(int* mat,int rows,int cols,int* zeroInRow,int* zeroInCol)
{
	int choise = 0;
	int suffledTimes = 0;
		
	while(suffledTimes < SUFFLE_COUNT)
	{
		choise = (rand() % 4) + 1;
		switch(choise)
	 	{
			case UP:
 				suffledTimes = suffledTimes + moveUp(mat, cols, zeroInRow,zeroInCol);
	 				break;
	 				
	 		case DOWN:
	 			suffledTimes = suffledTimes + moveDown(mat, cols, rows, zeroInRow, zeroInCol);
	 			break;
	 				
	 		case LEFT:
	 			suffledTimes = suffledTimes + moveLeft(mat, cols, zeroInRow, zeroInCol);
	 			break;
	 		case RIGHT:
	 			suffledTimes = suffledTimes + moveRight(mat, cols,zeroInRow, zeroInCol);
	 			break;
	 	}
	 }
}
int moveUp(int* mat,int cols,int* zeroInRow,int* zeroInCol)
{
	if(*zeroInRow == 0)
		return 0;
	*(mat + *zeroInRow*cols + *zeroInCol) = *(mat + *zeroInRow*cols + *zeroInCol - cols);
	*(mat + *zeroInRow*cols + *zeroInCol - cols) = 0;
	*zeroInRow = *zeroInRow - 1;
	return 1;
}
int moveDown(int* mat,int cols,int rows,int* zeroInRow,int* zeroInCol)
{
	if(*zeroInRow == (rows -1))
		return 0;
	*(mat + *zeroInRow*cols + *zeroInCol) = *(mat + *zeroInRow*cols + *zeroInCol + cols);
	*(mat + *zeroInRow*cols + *zeroInCol + cols) = 0;
	*zeroInRow = *zeroInRow + 1;
	return 1;
}

int moveLeft(int* mat,int cols,int* zeroInRow,int* zeroInCol)
{
	if(*zeroInCol == 0)
		return 0;
	*(mat + *zeroInRow*cols + *zeroInCol) = *(mat + *zeroInRow*cols + *zeroInCol - 1);
	*(mat + *zeroInRow*cols + *zeroInCol - 1) = 0;
	*zeroInCol = *zeroInCol -1;
	return 1;
}

int moveRight(int* mat,int cols,int* zeroInRow,int* zeroInCol)
{
	if(*zeroInCol == (cols -1))
		return 0;
	*(mat + *zeroInRow*cols + *zeroInCol) = *(mat + *zeroInRow*cols + *zeroInCol + 1);
	*(mat + *zeroInRow*cols + *zeroInCol + 1) = 0;
	*zeroInCol = *zeroInCol +1;
	return 1;
}


