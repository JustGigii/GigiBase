#include <stdlib.h>
#include "Enum.h"
#include <string.h>
#include <stdio.h>
typedef struct node
{
	void* value;
	struct node* next;
}Node, * RefNode;

RefNode initnode(void* value, int sizeofvalue)
{
	Node* newnode;
	newnode = malloc(sizeof(Node));
	if (newnode == NULL)
		return NULL;
	newnode->value = malloc(sizeofvalue);
	if (newnode->value == NULL)
		return NULL;
	memcpy(newnode->value, value, sizeofvalue);
	newnode->next = NULL;
	return newnode;
}

Erros AddNode(RefNode* nodelink, void* value, int sizeofvalue)
{
	RefNode node = initnode(value, sizeofvalue);
	if (node == NULL)
		return CANNOT_ALLOCTE;
	node->next = *nodelink;
	*nodelink = node;
	return SUCCES;
}

Erros RemoveNode(RefNode* nodelink, void* value, short (*cmp)(void*, void*))
{
 	RefNode prev = *nodelink;
	RefNode next;
	if (cmp(value, prev->value) == 0)
	{
		*nodelink = prev->next;
		free(prev->value);
		free(prev);
		return SUCCES;
	}
	next = prev->next;
	while (prev)
	{
		
		if (cmp(value, prev->value) == 0)
		{
			prev->next = next->next;
			free(next->value);
			free(next);
			return SUCCES;
		}
		prev = prev->next;
	}
	return NOT_FOUND;

}

Erros Destroy(RefNode* nodelink)
{
	RefNode prev;
	while (*nodelink)
	{
		prev = *nodelink;
		*nodelink = prev->next;
		free(prev->value);
		free(prev);
	}
}
