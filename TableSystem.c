#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
	CANNOT_ALLOCTE,
	SUCCES
	
}Erros;
typedef enum
{
	NUMBER,
	LONG,
	SHORT,
	UNUMBER,
	ULONG,
	USHORT,
	DOUBLE,
	FLOAT,
	VARCHAR,
	BOOL,
	TIME,
} DataType;

typedef struct 
{
	char* name;
	DataType type;
	void* row; //Data Structure to hold 

}column, *refcolumn;
typedef struct 
{
	char * name;
	refcolumn primary;
	refcolumn * refcolumns;

}Table, * refTable;

Erros CreateTable(char * name, refcolumn primary, refcolumn* refcolumns)
{
	refTable table;
	if (table =  malloc(sizeof(Table)) == NULL)
		return CANNOT_ALLOCTE;
	table->name = name;
	table->primary = primary;
	table->refcolumns;
	return SUCCES;
	
	
}

Erros buildHupa()
{
	char namearry[] = "HupaTable";
	char* name = malloc(strlen(namearry));
	
}


void main()
{
	
}
