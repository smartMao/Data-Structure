#include <stdio.h>
#include <stdlib.h>
#include "AVL-Tree.h"

struct treeNode {
	ElementType elem;
	AvlTree left;
	AvlTree right;
	int height;
};

int RandInt(int i , int j)
{
	int temp;
	temp = (int)(i + (1.0 * rand() / RAND_MAX) * (j - i) );
	return temp;
}


AvlTree makeRandomAvlTree(int H)
{
	if (H >= 0) {
		AvlTree t = malloc(sizeof(struct treeNode));
		if (t == NULL)
			exit(1);

		// 为了在H高度下， 生成最少的节点数， 左右子树的高度相差 1
		t->left = makeRandomAvlTree(H - 1);
		t->right = makeRandomAvlTree(H - 2);

		if (t->left == NULL && t->right == NULL) {
			t->elem = rand();
		}
		else if (t->left == NULL) {
			t->elem = RandInt(0, t->right->elem);
		}
		else if (t->right == NULL) {
			t->elem = RandInt(t->left->elem, RAND_MAX);
		}
		else {
			t->elem = RandInt(t->left->elem, t->right->elem);
		}
	
		return t;
	}
	return NULL;
}
