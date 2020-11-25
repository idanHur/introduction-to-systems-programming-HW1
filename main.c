#include <stdio.h>
#include "PictureManipulation.h"
#include <ctype.h>
#include "NumberGame.h"

int  main()
{
	char flag = 1;
	char choice = ' ';
 	do
 	{
 		printf("\nPlease choose one of the following options \n");
 		printf("P/p - Picture Manipulation \n");
 		printf("N/n - Number Game \n");
 		printf("E/e - Quit \n");
 		do
 		{
 			scanf("%c", &choice);
 		}while(isspace(choice));
 		choice = tolower(choice);
 		switch(choice)
 		{
 			case 'p':
 				PictureManipulation();
 				break;
 			case 'n':
 				NumberGame();
 				break;
 			case 'e':
 				printf("Bye Bye\n");
 				flag = 0;
 				break;
 		}
 	}while(flag);
}
