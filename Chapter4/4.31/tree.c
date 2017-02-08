a#include <stdio.h>
#include "tree.h"

// 实现： 编写一个函数， 生成一颗具有关键字 1 直到 2H-1 -1 且高为 H 的理想平衡二叉树。
struct treeNode
{
	int elem;
	Node left;
	Node right;
};

void main(void)
{
	int lastNodeElem = 0;
	Node t = makeNode(20, &lastNodeElem);
}

Node makeNode(int H, int *lastNodeElem)
{
	if (H >= 0) {
		Node t = malloc(sizeof(struct treeNode));
		t->left = makeNode(H - 1, lastNodeElem);
		t->elem = ++*lastNodeElem;
		t->right = makeNode(H - 1, lastNodeElem);

		return t;
	}
	return NULL;
}
