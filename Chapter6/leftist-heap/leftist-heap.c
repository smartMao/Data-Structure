#include "leftist-heap.h"
#include <stdio.h>


void main(void)
{

	PriorityQueue H;
	H = Initialize();

	Insert1(10, H);
	Insert1(15, H);
	Insert1(7, H);
	Insert1(6, H);
	Insert1(5, H);
	Insert1(4, H);
	Insert1(3, H);
	Insert1(20, H);

}

/* 移除根 */
PriorityQueue DeleteMin1(PriorityQueue H)
{
	PriorityQueue leftHeap, rightHeap;

	leftHeap = H->Left;
	rightHeap = H->Right;
	free(H);

	Merge(leftHeap, rightHeap);
}

PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
	PriorityQueue SingleNode;

	SingleNode = malloc(sizeof(struct TreeNode));
	if (SingleNode == NULL) {
		exit(-1);
	}
	else {
		SingleNode->Element = X;
		SingleNode->Npl = 0;
		SingleNode->Left = NULL;
		SingleNode->Right = NULL;
		H = Merge(SingleNode, H);
	}

	return H;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
	if(H1 == NULL)
		return H2;

	if(H2 == NULL)
		return H1;

	if (H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge1(H2, H1);
}

PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
	if (H1->Left == NULL)
		H1->Left = H2;
	else {
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl) {
			SwapChildren(H1);
		}

		H1->Npl = H1->Right->Npl + 1;
	}

	return H1;
}

PriorityQueue SwapChildren(PriorityQueue H)
{
	PriorityQueue tmpH;
	if (H->Left != NULL && H->Right != NULL) {
		tmpH = H->Left;
		H->Left = H->Right;
		H->Right = tmpH;
	}
	else {
		exit(-1);
	}
}

/* 初始化 */
PriorityQueue Initialize(void)
{
	PriorityQueue H;
	H = malloc(sizeof(struct TreeNode));
	if (H == NULL) {
		exit(-1);
	}

	H->Element = 1;
	H->Left = NULL;
	H->Right = NULL;
	H->Npl = 0;

	return H;
}
