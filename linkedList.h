typedef struct _ListNode {
    int data;
    struct _ListNode* prevNode;
    struct _ListNode* nextNode;
} *lNode;

typedef struct _List {
    int len;
    lNode head;
    lNode tail;
} *list;

//Create a new list
list list_new();

//Get data from list
int list_get(list L, int pos);

//Add node to list
void list_push(list L, int pos, int data);

//Remove node from list
int list_pop(list L, int pos);

//Free a list
void list_free(list L);
