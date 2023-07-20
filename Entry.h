#ifndef Entry.h
#define Entry.h

typedef struct
{
	void* key;
	void* value;
} Dictionary, * RefDictionary;

Erros initDict(void* key, int sizekey, void* value, int sizevalue, RefDictionary output);
Erros FreeDict(RefDictionary dict);

#endif