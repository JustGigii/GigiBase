#include <string.h>
#include "khash.h"
#include "TableSystem.h"
#include "node.h"
#include "DataBase.h"



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
	RefBase db = initDataBase("gigi");
	if (db == NULL)
		return 1;
	refTable table = buildHupa();
	if (table == NULL)
		return 1;
	if (AddTable(db, table) == SUCCES)
		printf("succes\n");
	if (AddTable(db, buildHupa()) == SUCCES)
		printf("succes");
	refcolumn coll = CreateColumns("name", VARCHAR, 0);
	
	AddColumnsToTable(db->hash, table, coll);
	s = GetHash(db->hash, "name");
	
	
}
