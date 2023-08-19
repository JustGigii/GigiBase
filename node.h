#pragma once
#ifndef Node_h
#define Node_h  
#include <stdlib.h>
#include "Enum.h"
#include <string.h>
#include <stdio.h>
typedef struct node
{
	void* value;
	struct node* next;
}Node, * RefNode;

RefNode initnode(void* value, int sizeofvalue);

Erros AddNode(RefNode* nodelink, void* value, int sizeofvalue);

Erros RemoveNode(RefNode* nodelink, void* value, short (*cmp)(void*, void*));
Erros Destroy(RefNode* nodelink);

#endif
