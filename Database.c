#include "khash.h"
#include "TableSystem.h"
KHASH_MAP_INIT_STR(str, int);
typedef struct 
{
	char* dbname;
	khash_t(str)* hash;
	

};