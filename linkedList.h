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

//Create a new list
list list_new();

//Get data from list
int list_get(list L, int pos);

//Add node to list
void list_push(list L, int pos, int data);

//Remove node from list
int list_pop(list L, int pos);