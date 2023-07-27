#include <stdlib.h>
#include "Enum.h"
#include <string.h>
#include <stdio.h>
typedef struct node
{
	void * value;
	struct node* next;
}Node,* RefNode;

Erros initnode(RefNode node, void* value, int sizeofvalue)
{
	Node* newnode;
	newnode = malloc(sizeof(Node));
	if (newnode == NULL)
		return CANNOT_ALLOCTE;
	newnode->value = malloc(sizeofvalue);
	if (newnode->value == NULL)
		return CANNOT_ALLOCTE;
	memcpy(newnode->value, value, sizeofvalue);
	node->next = NULL;
	return SUCCES;
}

Erros AddNode(RefNode nodelink,void * value,int sizeofvalue)
{
	Node node;
	if (initnode(&node, value, sizeof(sizeofvalue)) != SUCCES)
		return CANNOT_ALLOCTE;
	nodelink->next = nodelink;
	nodelink = &node;
}

int main()
{
	Node* hello;
	char name[] = "name1";
	char name1[] = "name12";
	if (initnode(hello, name, sizeof(name)) == SUCCES)
		if (AddNode(hello, name1, sizeof(name1)) == SUCCES)
			printf("%s\n", hello->value);
			printf("%s", hello->next->value);
}