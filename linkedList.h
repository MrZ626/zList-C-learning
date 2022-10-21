typedef struct _ListNode {
    size_t data;
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
size_t list_get(list L, int pos);

//Add node to list
void list_push(list L, int pos, size_t data);

//Remove node from list
size_t list_pop(list L, int pos);

//Free a list
void list_free(list L);
