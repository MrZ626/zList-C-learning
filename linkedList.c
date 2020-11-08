#include <stdio.h>
#include <stdlib.h>

//Private
typedef struct listNode
{
	int data;
	struct listNode *prevNode;
	struct listNode *nextNode;
} * lNode;
typedef struct list
{
	int len;
	lNode head;
	lNode tail;
} * list;
lNode _newNode(int data)
{
	lNode node = (lNode)malloc(sizeof(lNode));
	node->data = data;
	return node;
}
void _list_pushFirst(list L, int data)
{
	lNode node = _newNode(data);
	node->prevNode = NULL;
	node->nextNode = L->head;

	if (L->head != NULL)
		L->head->prevNode = node;
	L->head = node;

	L->len++;
}
void _list_pushLast(list L, int data)
{
	lNode node = _newNode(data);
	node->prevNode = L->tail;
	node->nextNode = NULL;

	if (L->tail != NULL)
		L->tail->nextNode = node;
	L->tail = node;

	L->len++;
}
void _list_pushPos(list L, int pos, int data)
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
	node->prevNode->nextNode=nodeN;
	node->prevNode=nodeN;
	L->len++;
}
int _list_popFirst(list L)
{
	int res = L->head->data;
	free(L->head);
	L->head = L->head->nextNode;
	if (L->len == 1)
		L->tail = NULL;
	L->len--;
	return res;
}
int _list_popLast(list L)
{
	int res = L->tail->data;
	free(L->tail);
	L->tail = L->tail->prevNode;
	if (L->len == 1)
		L->head = NULL;
	L->len--;
	return res;
}
int _list_popPos(list L, int pos)
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
	node->prevNode->nextNode=node->nextNode;
	node->nextNode->prevNode=node->prevNode;
	int res=node->data;
	free(node);

	L->len--;
	return 0; //return res;
}

//Public
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
		pos=pos<=0?0:pos<L->len?pos:L->len;
		if (pos == 0)
			_list_pushFirst(L, data);
		else if (pos == L->len)
			_list_pushLast(L, data);
		else
			_list_pushPos(L, pos, data);
	}
}
int list_pop(list L, int pos) //remove node from list
{
	if (L->len > 0)
	{
		pos = (pos + L->len / 2) % L->len - L->len / 2;
		if (pos == 0)
			return _list_popFirst(L);
		else if (pos == -1)
			return _list_popLast(L);
		else
			return _list_popPos(L, pos);
	}
	else
	{
		printf("\n<<ERROR : Nothing to pop>>\n");
		return 0;
	}
}