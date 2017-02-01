#include <stdio.h>
#include <stdlib.h>
#include "AVL-Tree.h"

struct treeNode {
	ElementType elem;
	AvlTree left;
	AvlTree right;
	int height;
};

AvlTree insert(ElementType elem, AvlTree t)
{
	if (t == NULL) {
		t = malloc(sizeof(struct treeNode));
		if (t == NULL) 
			exit(1);
		t->elem = elem;
		t->left = NULL;
		t->right = NULL;
		t->height = 0;
	}
	else {
		if (elem < t->elem) {
			// 插入到左子树
			t->left = insert(elem, t->left);
			if (height(t->left) - height(t->right) == 2) {
				// 当节点每次插入新的子节点后，检查左右子树的高度相差是否大于 2
				printf("asd");
				if (elem < t->left->elem) {
					t = singleRotateWithLeft(t);
				}
				else {
					t = doubleRotateWithLeft(t);
				}
			}

		}
		else if (elem > t->elem) {
			// 插入到右子树
			t->right = insert(elem, t->right);
			
			if (height(t->right) - height(t->left) == 2) {
				if (elem > t->right->elem) {
					t = singleRotateWithRight(t);
				}
				else {
					t = doubleRotateWithRight(t);
				}
			}

		}

	}

	t->height = Max(height(t->left), height(t->right)) + 1;
	return t;
}


static singleRotateWithLeft(AvlTree parentNode)
{
	// 在 parentNode 节点的 左右子树高度相差大于 2
	AvlTree newParentNode = parentNode->left;
	AvlTree y = newParentNode->right;
	parentNode->left = y;
	newParentNode->right = parentNode;

	parentNode->height = Max(height(parentNode->left), height(parentNode->right)) + 1;
	newParentNode->height = Max(height(newParentNode->left), height(newParentNode->right)) + 1;
	return newParentNode;
}

static doubleRotateWithLeft(AvlTree parentNode)
{
	parentNode->left = singleRotateWithRight(parentNode->left);
	return singleRotateWithLeft(parentNode);
}

static singleRotateWithRight(AvlTree parentNode)
{
	// 在 parentNode 节点的 左右子树高度相差大于 2
	AvlTree newParentNode = parentNode->right;
	AvlTree y = newParentNode->left;
	parentNode->right = y;
	newParentNode->left = parentNode;

	parentNode->height = Max(height(parentNode->left), height(parentNode->right)) + 1;
	newParentNode->height = Max(height(newParentNode->left), height(newParentNode->right)) + 1;
	return newParentNode;
}

static doubleRotateWithRight(AvlTree parentNode)
{
	parentNode->right = singleRotateWithLeft(parentNode->right);
	return singleRotateWithRight(parentNode);
}

ElementType Max(ElementType a, ElementType b)
{
	return a > b ? a : b;
}

int height(AvlTree t)
{
	if (t == NULL)
		return -1;
	else
		return t->height;
}
