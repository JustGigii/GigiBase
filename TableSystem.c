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


Erros CreateTable(char * name, refcolumn primary, refcolumn* refcolumns)
{
	refTable table;
	char* newname;
	if ((table = malloc(sizeof(Table))) == NULL || (newname = malloc(strlen(name)))==NULL)
		return CANNOT_ALLOCTE;
	strcpy(newname, name);
	table->name = newname;
	table->primary = primary;
	table->refcolumns;
	return SUCCES;
	
	
}

Erros CreateColumns(char* name, DataType type, void* row,refcolumn * newcolumnref  )
{
	refcolumn newcolumn =  malloc(sizeof(column));
	if (newcolumn == NULL) return CANNOT_ALLOCTE;
	newcolumn->name = name;
	newcolumn->row = row;
	newcolumn->type = type;
	*newcolumnref = newcolumn;
	return SUCCES;
}

Erros buildHupa()
{
	char name[] = "HupaTable";

	refcolumn primery;
	if (CreateColumns("id", USHORT, 0, &primery) == CANNOT_ALLOCTE)
		return CANNOT_ALLOCTE;

	
	
}



//void main()
//{
//	if (buildHupa() == SUCCES)
//		printf("the table build succes");
//}
