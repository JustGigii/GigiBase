#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Enum.h"

typedef struct
{
	char* name;
	DataType type;
	void* row; //Data Structure to hold 

}column, * refcolumn;

typedef struct
{
	char* name;
	refcolumn primary;
	refcolumn* refcolumns;
	char* namecolumns[];
}Table, * refTable;


refcolumn CreateTable(char * name, refcolumn primary, refcolumn* refcolumns)
{
	refTable table;
	char* newname;
	if ((table = malloc(sizeof(Table))) == NULL || (newname = malloc(strlen(name)))==NULL)
		return NULL;
	strcpy(newname, name);
	table->name = newname;
	table->primary = primary;
	table->refcolumns;
	return table;
	
	
}

refcolumn CreateColumns(char* name, DataType type, void* row )
{
	refcolumn newcolumn =  malloc(sizeof(column));
	if (newcolumn == NULL) return NULL;
	newcolumn->name = name;
	newcolumn->row = row;
	newcolumn->type = type;
	return newcolumn;

}

Erros buildHupa()
{
	char name[] = "HupaTable";

	refcolumn primery;
	if (CreateColumns("id", USHORT, 0, &primery) == NULL)
		return CANNOT_ALLOCTE;

	
	
}



//void main()
//{
//	if (buildHupa() == SUCCES)
//		printf("the table build succes");
//}
