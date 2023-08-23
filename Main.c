#include <string.h>
#include "khash.h"
#include "TableSystem.h"
#include "node.h"
#include "DataBase.h"
#include "CmdUi.h"


refTable buildHupa()
{
	

	char name[] = "HupaTable";
	refTable table;
	refcolumn primery = CreateColumns("id", USHORT, 0);
	if (primery == NULL)
		return NULL;
	table = CreateTable(name, primery, NULL);
	return table;

}



void main()
{
	khiter_t k;
	size_t s;
	refTable table;
	refcolumn coll;
	int i;
	RefBase db = initDataBase("gigi");
	if (db == NULL)
		return 1;
	 table = buildHupa();
	if (table == NULL)
		return 1;
	if (AddTable(db, table) == CANNOT_ALLOCTE)
		printf("cannot allocit\n");
	if (AddTable(db, buildHupa()) == CANNOT_ALLOCTE)
		printf("cannot allocit\n");
	coll = CreateColumns("name", VARCHAR, 0);
	AddColumnsToTable(db->hash, table, coll);
	table = db->tables->next->value;
	printTable(table->name,table->namecolumns,table->numbercoll);

	
	
}
