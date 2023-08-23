#pragma once
#ifndef TableSystem_h
#define TableSystem_h
KHASH_MAP_INIT_STR(str, size_t);
#include "Enum.h"
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


refTable CreateTable(char* name, refcolumn primary, refcolumn* refcolumns);

refcolumn CreateColumns(char* name, DataType type, void* row);

Erros AddColumnsToTable(khash_t(str)* hash, refTable Table, refcolumn column);

Erros HashAdd(khash_t(str)* h1, char* paramName, refcolumn h);

refcolumn GetHash(khash_t(str)* h, char* paramName);

#endif // !TableSystem_h

