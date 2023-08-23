#include <stdio.h>
#include <string.h>
#include "Enum.h"


Erros printTable(char* tablename, char** columns, int size)
{
	int i,j;
	for ( i = 0; i < size; i++)
	{
		printf("|%s", columns[i]);
		for ( j = 0; j < 15-strlen(columns[i]-1); j++) printf(" ");
	}
	printf("\n");
	for ( i = 0; i < 15*size; i++)printf("_");


}