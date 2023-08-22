#pragma once
#ifndef database_h
#define database_h  
#include <string.h>
#include "khash.h"
#include "TableSystem.h"
#include "node.h"

//KHASH_MAP_INIT_STR(str, size_t);
typedef struct
{
	char* dbname;
	khash_t(str)* hash;
	RefNode tables;
}Database, * RefBase;


RefBase initDataBase(char* dbname);

Erros AddTable(RefBase database, refTable table);

#endif