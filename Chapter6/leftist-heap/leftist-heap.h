#ifndef _LeftHeap_H

struct TreeNode;
typedef int ElementType;
typedef struct TreeNode *PriorityQueue;

PriorityQueue Initialize(void);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);
PriorityQueue SwapChildren(PriorityQueue H1);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);

PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

#endif


struct TreeNode {

	ElementType Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int Npl;
};
