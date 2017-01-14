#include <stdio.h>
#include "node.h"

/*
	实现：打印出一个单链表中所有元素
*/
int printfList(List L)
{
	Position P = L->Next;
	while (P != NULL && P->Element != NULL) {
		printf("%d \n", P->Element);
		P = P->Next;
	}
}
