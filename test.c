#include <stdio.h>
#include "linkedList.h"
#define divLine printf("----------\n")

int main()
{
    divLine;

    printf("新建列表并在末尾添加五个数\n");
    list L = list_new();
    list_push(L, -1, 1);
    list_push(L, -1, 2);
    list_push(L, -1, 3);
    list_push(L, -1, 4);
    list_push(L, -1, 5);
    for (int i = 0; i < L->len; i++)
        printf("%d\n", list_get(L, i));

    divLine;

    printf("移除第四个和第二个\n");
    list_pop(L, 3);
    list_pop(L, 1);
    for (int i = 0; i < L->len; i++)
        printf("%d\n", list_get(L, i));

    divLine;

    printf("向倒数第二和第四的位置插入两个数\n");
    list_push(L, -2, 400);
    list_push(L, -4, 200);
    for (int i = 0; i < L->len; i++)
        printf("%d\n", list_get(L, i));

    divLine;

    printf("释放链表\n");
    list_free(L);
    printf("完成\n");

    divLine;

    return 0;
}