#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Enum.h"
#include "node.h"
#include "khash.h"
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
	char numbercoll;
	char** namecolumns;
}Table, * refTable;


refTable CreateTable(char * name, refcolumn primary, refcolumn* refcolumns)
{
	refTable table;
	char* newname;
	if ((table = malloc(sizeof(Table))) == NULL || (newname = malloc(strlen(name)))==NULL)
		return NULL;
	strcpy(newname, name);
	table->name = newname;
	table->primary = primary;
	table->numbercoll = 0;
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
KHASH_MAP_INIT_STR(str,refcolumn)

char* insertname(char** namecolumns,char size, char* addname)
{
	char** namecolumnsarry;
	if (size == 0)
		namecolumnsarry = (char*)malloc(sizeof(char*));
	else
		namecolumnsarry = (char*)realloc(namecolumns, sizeof(char*)*(size + 1));
	if (namecolumnsarry == NULL)
		return CANNOT_ALLOCTE;
	char* name = malloc(strlen(addname));
	if (name == NULL)
		return CANNOT_ALLOCTE;
	strcpy(name, addname);
	namecolumnsarry[size] = name;
	return namecolumnsarry;
}


Erros AddColumnsToTable(khash_t(str) * hash, refTable table, refcolumn column)
{
	khint_t k;
	int ret;
	char* key = column->name;
	HashAdd(hash, key, column);
	table->namecolumns = insertname(table->namecolumns, table->numbercoll, column->name);
	table->numbercoll++;

}

Erros HashAdd(khash_t(str)* h1, char* paramName, refcolumn h)
{
	int ret;
	khiter_t k;

	k = kh_put(str, h1, paramName, &ret);
	kh_value(h1, k) = h;
}

refcolumn GetHash(khash_t(str)* h, char* paramName)
{
	khiter_t k;
	refcolumn handler;

	k = kh_get(str, h, paramName);
	handler = kh_value(h, k);
	return handler;
}