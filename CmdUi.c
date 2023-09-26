#include <stdio.h>
#include <string.h>
#include "Enum.h"


Erros printTable(char* tablename,char* perimery ,char** columns, int size)
{
	int i,j,amount;

	for ( i = 0; i < size; i++)
	{
		printf("|");
		amount = (10 - strlen(columns[i] - 1)) / 2;
		for (j = 0; j < amount; j++) printf(" ");
		printf("%s", columns[i]);
		for ( j = 0; j < amount; j++) printf(" ");
		
	}
	printf("\n");
	for ( i = 0; i < 10*(size+1); i++)printf("_");


}