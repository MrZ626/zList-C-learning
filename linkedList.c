#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

static lNode _newNode(int data)
{
	lNode node = (lNode)malloc(sizeof(lNode));
	node->data = data;
	return node;
}
static void list_pushFirst(list L, int data)
{
	lNode node = _newNode(data);
	node->prevNode = NULL;
	node->nextNode = L->head;

	if (L->head != NULL)
		L->head->prevNode = node;
	L->head = node;

	L->len++;
}
static void list_pushLast(list L, int data)
{
	lNode node = _newNode(data);
	node->prevNode = L->tail;
	node->nextNode = NULL;

	if (L->tail != NULL)
		L->tail->nextNode = node;
	L->tail = node;

	L->len++;
}
static void list_pushPos(list L, int pos, int data)
{
	lNode nodeN = _newNode(data);
	lNode node;
	if (pos >= 0)
	{
		node = L->head;
		while (pos > 0)
		{
			node = node->nextNode;
			pos--;
		}
	}
	else
	{
		node = L->tail;
		while (pos < -1)
		{
			node = node->prevNode;
			pos++;
		}
	}
	nodeN->prevNode = node->prevNode;
	nodeN->nextNode = node;
	node->prevNode->nextNode = nodeN;
	node->prevNode = nodeN;
	L->len++;
}
static int list_popFirst(list L)
{
	int res = L->head->data;
	free(L->head);
	L->head = L->head->nextNode;
	if (L->len == 1)
		L->tail = NULL;
	L->len--;
	return res;
}
static int list_popLast(list L)
{
	int res = L->tail->data;
	free(L->tail);
	L->tail = L->tail->prevNode;
	if (L->len == 1)
		L->head = NULL;
	L->len--;
	return res;
}
static int list_popPos(list L, int pos)
{
	pos = (pos + L->len / 2) % L->len - L->len / 2;
	lNode node;
	if (pos >= 0)
	{
		node = L->head;
		while (pos > 0)
		{
			node = node->nextNode;
			pos--;
		}
	}
	else
	{
		node = L->tail;
		while (pos < -1)
		{
			node = node->prevNode;
			pos++;
		}
	}
	node->prevNode->nextNode = node->nextNode;
	node->nextNode->prevNode = node->prevNode;
	int res = node->data;
	free(node);

	L->len--;
	return 0; //return res;
}

list list_new()
{
	list L = malloc(sizeof(struct list));
	L->head = NULL;
	L->tail = NULL;
	L->len = 0;
	return L;
}
int list_get(list L, int pos)
{
	if (L->len > 0)
	{
		pos = (pos + L->len / 2) % L->len - L->len / 2;
		lNode node;
		if (pos >= 0)
		{
			node = L->head;
			while (pos > 0)
			{
				node = node->nextNode;
				pos--;
			}
		}
		else
		{
			node = L->tail;
			while (pos < -1)
			{
				node = node->prevNode;
				pos++;
			}
		}
		return node->data;
	}
	else
	{
		printf("\n<<ERROR : Nothing to get>>\n");
	}
}
void list_push(list L, int pos, int data) //Add node to list
{
	lNode node = _newNode(data);
	if (L->len == 0)
	{
		node->prevNode = NULL;
		node->nextNode = NULL;
		L->head = node;
		L->tail = node;
		L->len++;
	}
	else
	{
		pos = pos <= 0 ? 0 : pos < L->len ? pos : L->len;
		if (pos == 0)
			list_pushFirst(L, data);
		else if (pos == L->len)
			list_pushLast(L, data);
		else
			list_pushPos(L, pos, data);
	}
}
int list_pop(list L, int pos) //remove node from list
{
	if (L->len > 0)
	{
		pos = (pos + L->len / 2) % L->len - L->len / 2;
		if (pos == 0)
			return list_popFirst(L);
		else if (pos == -1)
			return list_popLast(L);
		else
			return list_popPos(L, pos);
	}
	else
	{
		printf("\n<<ERROR : Nothing to pop>>\n");
		return 0;
	}
}
void list_free(list L)
{
	lNode N = L->head->nextNode;
	while (N != NULL)
	{
		free(N->prevNode);
		N = N->nextNode;
	}
	if (L->tail != NULL)
		free(L->tail);
	free(L);
}