#include <string.h>
#include "khash.h"
#include "TableSystem.h"
#include "node.h"

typedef struct 
{
	char* dbname;
	khash_t(str)* hash;
	RefNode tables;
}Database, * RefBase;


RefBase initDataBase(char * dbname)
{
	RefBase database;
	database = malloc(sizeof(Database));
	if (database == NULL)
		return NULL;
	database->dbname = malloc(strlen(dbname));
	strcpy(database->dbname, dbname);
	database->hash = kh_init(str);
	database->tables = NULL;

}

Erros AddTable(RefBase database,refTable table)
{
	if (database->tables == NULL)
	{
		database->tables = initnode(table, sizeof(table));
		return (database->tables == NULL)? CANNOT_ALLOCTE: SUCCES;
	}

	return AddNode(&database->tables, table, sizeof(table) == SUCCES) ? SUCCES:CANNOT_ALLOCTE;
}


