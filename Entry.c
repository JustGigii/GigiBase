#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Enum.h"
#include "Entry.h"
typedef struct
{
	void* key;
	void* value;
} Dictionary, * RefDictionary;

Erros initDict(void* key, int sizekey, void* value, int sizevalue, RefDictionary output)
{
	Dictionary dict;
	dict.key = malloc(sizekey);;
	dict.value = malloc(sizevalue);
	if (dict.key == NULL || dict.value == NULL)
		return CANNOT_ALLOCTE;
	memcpy(dict.key, key, sizekey);
	memcpy(dict.value, value, sizevalue);
	*output = dict;
	return SUCCES;
}

Erros FreeDict(RefDictionary dict)
{
	free(dict->key);
	free(dict->value);
	free(dict);
	return SUCCES;
}

void main()
{
	Dictionary dict;
	char name[] = "omri";
	int age = 22;
	if (init(name, sizeof(name), &age, sizeof(int), &dict) == SUCCES)
		printf("%s", dict.key);
	FreeDict(&dict);
}
