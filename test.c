#include <stdio.h>
#include "linkedList.c"
int main()
{
	list L = list_new();
	list_push(L, 3, 1);
	list_push(L, 3, 2);
	list_push(L, 3, 3);
	list_push(L, 3, 4);
	list_push(L, 3, 5);
	for(int i=0;i<L->len;i++)
		printf("%d\n", list_get(L,i));
	return 0;
}