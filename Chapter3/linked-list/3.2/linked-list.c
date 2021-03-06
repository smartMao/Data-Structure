#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "windows.h"

struct book {
	char title[20];
	char author[2];
};

// 实现： 有链表 L 和 P, 打印出L中，以P所指定位置上的元素

int main()
{
	FILETIME beg,end;
	GetSystemTimeAsFileTime(&beg);

	List L; 
	L = malloc(sizeof(struct Node)); // 初始化指针，指向一个分配好的内存地址
	L->Element = 0;
	L->Next = malloc(sizeof(struct Node));
	
	create(L, 10); // 创建链表
	insert(8, L); // 插入节点
	insert(1, L); // 插入节点
	insert(9, L); // 插入节点
	insert(6, L); // 插入节点
	insert(2, L); // 插入节点
	insert(7, L); // 插入节点
	printfList(L);

	List P;
	P = malloc(sizeof(struct Node));
	P->Element = 1;
	P->Next = malloc(sizeof(struct Node));
	create(P, 0); // 创建链表
	insert(5, P);
	insert(3, P);
	printfLots(L, P);
	//printfList(P);

	GetSystemTimeAsFileTime(&end);
	long dur = 100*(end.dwLowDateTime-beg.dwLowDateTime);
	printf("程序运行微秒数： %d \n", dur);

}

void printfLots(List L, List P )
{
	List temp = malloc(sizeof(List));
	temp = P;
	do
	{
		find_by_pos(temp->Element, L);
		temp = temp->Next;
	} while (temp != NULL);

}

void create(List head, int size)
{
	List p = (List)malloc(sizeof(List));
	List pNode;

	p->Element = 0;
	p->Next = NULL;
	head->Next = p;
	for (int i = 0; i < size; i++) {
		pNode = (List)malloc(sizeof(List));
		if (pNode == NULL) {
			return -1;
		}

		// 建立新的节点，Element被初始化为0，Next为NULL(因为他就是最新的节点 )
		pNode->Element = 0;
		pNode->Next = NULL;
/*3*/	p->Next = pNode;
/*4*/	p = pNode; // 每次循环都更新 p 的值，让p每次都是最新的节点
	}


}

void printfList(List head)
{
	List p = malloc(sizeof(List));
	p = head;

	do {
		printf("Element = %d , Next = %p \n", p->Element, p->Next);
		p = p->Next;
	} while (p != NULL);

}

/*
	通过下标find节点元素
*/
void find_by_pos(int pos, List L)
{
	List p = malloc(sizeof(List));
	p = L;
	int i = 0;

	do {
		if (i == pos) {
			printf("L中下标为%d的元素: Element = %d , Next = %p \n", pos , p->Element, p->Next);
			break;
		}
		i++;
		p = p->Next;
	} while (p != NULL);
}


void insert(ElementType X, Position P)
{
	Position temp = malloc(sizeof(Position));
	if (temp != NULL){
		temp->Element = X;
		temp->Next = P->Next;
		P->Next = temp;
	}
}
