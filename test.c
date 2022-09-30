#include <stdio.h>
#include "linkedList.h"
#define divLine printf("----------\n")

int main()
{
    divLine;

    printf("�½��б���ĩβ��������\n");
    list L = list_new();
    list_push(L, -1, 1);
    list_push(L, -1, 2);
    list_push(L, -1, 3);
    list_push(L, -1, 4);
    list_push(L, -1, 5);
    for (int i = 0; i < L->len; i++)
        printf("%d\n", list_get(L, i));

    divLine;

    printf("�Ƴ����ĸ��͵ڶ���\n");
    list_pop(L, 3);
    list_pop(L, 1);
    for (int i = 0; i < L->len; i++)
        printf("%d\n", list_get(L, i));

    divLine;

    printf("�����ڶ��͵��ĵ�λ�ò���������\n");
    list_push(L, -2, 400);
    list_push(L, -4, 200);
    for (int i = 0; i < L->len; i++)
        printf("%d\n", list_get(L, i));

    divLine;

    printf("�ͷ�����\n");
    list_free(L);
    printf("���\n");

    divLine;

    return 0;
}