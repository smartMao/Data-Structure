#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct book {
	char title[20];
	char author[2];
};

int main()
{
	int size = 10;
	List head; // head 是个结构指针，但没有指向任何地址，所有没有被初始化。
	head = malloc(sizeof(struct Node)); // 初始化指针，指向一个分配好的内存地址
	head->Element = 0;
	head->Next = malloc(sizeof(struct Node));
	
	create(head, size); // 创建链表
	insert(18, head); // 插入节点
	printfList(head); // 打印链表
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

void insert(ElementType X, Position P)
{
	Position temp = malloc(sizeof(Position));
	if (temp != NULL){
		temp->Element = X;
		temp->Next = P->Next;
		P->Next = temp;
	}
}

