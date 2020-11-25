
#ifndef __NUMGAME__
#define __NUMGAME__

#define ROWS 3
#define COLS 4
#define SUFFLE_COUNT 10

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

	
void NumberGame();
void suffleMat(int* mat,int rows,int cols,int* zeroInRow,int* zeroInCol);
int moveUp(int* mat,int cols,int* zeroInRow,int* zeroInCol);
int moveDown(int* mat,int cols,int rows,int* zeroInRow,int* zeroInCol);
int moveLeft(int* mat,int cols,int* zeroInRow,int* zeroInCol);
int moveRight(int* mat,int cols,int* zeroInRow,int* zeroInCol);
void playNumberGame(int* mat,int rows,int cols,int* zeroInRow,int* zeroInCol);
int isValidMove(int* mat,int rows,int cols,int* zeroInRow,int* zeroInCol,int indexToMove);
#endif

