#include <stdio.h>
#include "heap.h"

#define MaxElement 10;
#define MinData 0;

void main()
{

	PriorityQueue H;
	H = Initialize(10);

	Insert(10, H);
	Insert(20, H);
	Insert(30, H);
	Insert(40, H);
	Insert(50, H);
	Insert(60, H);
	printf("删除前");
	printList(H);
	printf("\n\n");

	DeleteMin(H);

	printList(H);
}


void Insert(ElementType X, PriorityQueue H)
{
	int i = 0;
	if (IsFull(H)) 
		exit(-1);

	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2) {
		H->Elements[i] = H->Elements[i / 2];
	}
	H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H)
{

	int i, Child;
	ElementType MinElement, LastElement;

	if (IsFull(H))
		exit(-1);

	MinElement = H->Elements[1]; // 找到要被移除的元素
	LastElement = H->Elements[H->Size--];

	for (i = 1; i * 2 <= H->Size; i++) {
		Child = 2 * i;
		if (H->Elements[Child] > H->Elements[Child+1]) {
			// 左子树 大于 右子树
			H->Elements[i] = H->Elements[Child+1];
		}
		else {
			// 右子树 大于 左子树
			H->Elements[i] = H->Elements[Child];
		}
	}

	H->Elements[Child] = LastElement;
	return MinElement;
}

void printList(PriorityQueue H)
{
	if (H == NULL) {
		exit(-1);
	}

	for (int i = 1; i <= H->Size; i++) {
		printf("%d \n", H->Elements[i]);
	}
}

/* 初始化 */
PriorityQueue Initialize( int maxElement )
{
	PriorityQueue H;
	H = malloc(sizeof( struct HeapStruct ) );
	if (H == NULL) {
		exit(-1);
	}

	H->Elements = malloc( sizeof( ElementType ) * (maxElement + 1) );
	if (H->Elements == NULL) {
		exit(-2);
	}

	H->Capacity = maxElement;
	H->Size = 0;
	H->Elements[0] = MinData;
	return H;
}


/*  */
int IsFull( PriorityQueue H)
{
	if (H == NULL)
		exit(-1);

	if (H->Size == H->Capacity) {
		return 1;
	}
	else {
		return 0;
	}
}
