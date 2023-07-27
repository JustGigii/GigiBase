#pragma once
#ifndef TableSystem_h
#include "Enum.h"

#define TableSystem_h
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

#endif // !TableSystem_h

