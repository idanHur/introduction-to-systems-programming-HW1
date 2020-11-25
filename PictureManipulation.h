#ifndef __PICTURE__
#define __PICTURE__

#define SIZE 5
#define LOWER 1
#define UPPER 99

#define CLOCKWISE 1
#define COUNTER_CLOCKWISE 2
#define HORIZONTAL 3
#define VERTICAL 4


void clockwiseFlipMat(int* mat,int size);
void counterClockwiseFlipMat(int* mat,int size);
void PictureManipulation();
void verticalFlip(int* mat,int size);
void horizontalFlip(int* mat,int size);
void printMenu();
void playGame(int* mat,int size);
void makeChoise(int* mat,int size,int* choice);
#endif
