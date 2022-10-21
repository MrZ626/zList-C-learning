#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linkedList.h"

static int clamp(int min, int max, int val) {
    if (val <= min)
        return min;
    else if (val >= max)
        return max;
    else
        return val;
}

static lNode _newNode(size_t data) {
    lNode node = (lNode)malloc(sizeof(struct _ListNode));
    node->data = data;
    return node;
}
static void list_pushFirst(list L, size_t data) {
    lNode node = _newNode(data);
    node->prevNode = NULL;
    node->nextNode = L->head;

    if (L->head != NULL)
        L->head->prevNode = node;
    L->head = node;

    L->len++;
}
static void list_pushLast(list L, size_t data) {
    lNode node = _newNode(data);
    node->prevNode = L->tail;
    node->nextNode = NULL;

    if (L->tail != NULL)
        L->tail->nextNode = node;
    L->tail = node;

    L->len++;
}
static void list_pushPos(list L, int pos, size_t data) {
    lNode nodeN = _newNode(data);
    lNode node;
    if (pos >= 0) {
        node = L->head;
        while (pos > 0) {
            node = node->nextNode;
            pos--;
        }
    }
    else {
        node = L->tail;
        while (pos < -1) {
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
static size_t list_popFirst(list L) {
    lNode n = L->head;
    size_t res = n->data;
    L->head = n->nextNode;
    free(n);
    if (L->head != NULL)
        L->head->prevNode = NULL;
    L->len--;
    if (L->len == 0)
        L->tail = NULL;
    return res;
}
static size_t list_popLast(list L) {
    lNode n = L->tail;
    size_t res = n->data;
    L->tail = n->prevNode;
    free(n);
    if (L->tail != NULL)
        L->tail->nextNode = NULL;
    L->len--;
    if (L->len == 0)
        L->head = NULL;
    return res;
}
static size_t list_popPos(list L, int pos) {
    pos = (pos + L->len / 2) % L->len - L->len / 2;
    lNode node;
    if (pos >= 0) {
        node = L->head;
        while (pos > 0) {
            node = node->nextNode;
            pos--;
        }
    }
    else {
        node = L->tail;
        while (pos < -1) {
            node = node->prevNode;
            pos++;
        }
    }
    node->prevNode->nextNode = node->nextNode;
    node->nextNode->prevNode = node->prevNode;
    size_t res = node->data;
    free(node);

    L->len--;
    return res;
}

list list_new() {
    list L = malloc(sizeof(list));
    L->head = NULL;
    L->tail = NULL;
    L->len = 0;
    return L;
}
size_t list_get(list L, int pos) {
    if (L->len > 0) {
        pos = (pos + L->len / 2) % L->len - L->len / 2;
        lNode node;
        if (pos >= 0) {
            node = L->head;
            while (pos > 0) {
                node = node->nextNode;
                pos--;
            }
        }
        else {
            node = L->tail;
            while (pos < -1) {
                node = node->prevNode;
                pos++;
            }
        }
        return node->data;
    }
    else {
        printf("\n<<ERROR : Nothing to get>>\n");
    }
}
void list_push(list L, int pos, size_t data) // Add node to list
{
    lNode node = _newNode(data);
    if (L->len == 0) {
        node->prevNode = NULL;
        node->nextNode = NULL;
        L->head = node;
        L->tail = node;
        L->len++;
    }
    else {
        if (pos < 0)
            pos = L->len + 1 + pos;
        pos = clamp(0, L->len, pos);
        if (pos == 0)
            list_pushFirst(L, data);
        else if (pos == L->len)
            list_pushLast(L, data);
        else
            list_pushPos(L, pos, data);
    }
}
size_t list_pop(list L, int pos) // remove node from list
{
    if (L->len > 0) {
        pos = (pos + L->len / 2) % L->len - L->len / 2;
        if (pos == 0)
            return list_popFirst(L);
        else if (pos == -1)
            return list_popLast(L);
        else
            return list_popPos(L, pos);
    }
    else {
        printf("\n<<ERROR : Nothing to pop>>\n");
        return 0;
    }
}
void list_free(list L) {
    if (L->len > 0) {
        lNode N = L->head->nextNode;
        while (N != NULL) {
            free(N->prevNode);
            N = N->nextNode;
        }
        if (L->tail != NULL)
            free(L->tail);
    }
    free(L);
}
