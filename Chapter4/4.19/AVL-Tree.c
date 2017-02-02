#include <stdio.h>
#include <stdlib.h>
#include "AVL-Tree.h"

// 实现 - AVL树 非懒惰删除

struct treeNode {
	ElementType elem;
	AvlTree left;
	AvlTree right;
	int height;
};


AvlTree Delete(ElementType elem, AvlTree t)
{
	AvlTree tempCell;

	if (t == NULL) {
		exit(1);
	}
	else if (elem < t->elem) {
		t->left = Delete(elem, t->left);
		if (height(t->right) - height(t->left) == 2) {
			if (height(t->right->right) > height(t->right->left)) {
				t = singleRotateWithRight(t);
			}
			else {
				t = doubleRotateWithRight(t);
			}
		}
		t->height = Max(height(t->left), height(t->right)) + 1;
	}
	else if (elem > t->elem) {
		t->right = Delete(elem, t->right);
		if (height(t->left) - height(t->right) == 2) {
			if (height(t->left->left) > height(t->left->right)) {
				t = singleRotateWithLeft(t);
			}
			else {
				t = doubleRotateWithLeft(t);
			}
		}
		t->height = Max(height(t->left), height(t->right)) + 1;
	}
	else if (t->left && t->right) {
		// 已找到要 “要被删除的节点” , 并且该节点下有左右子树, 用右子树中最小的节点代替
		tempCell = findMin(t->right);
		t->elem = tempCell->elem;
		t->right = Delete(t->right->elem, t->right);
		t->height = Max(height(t->left), height(t->right)) + 1;
	}
	else {
		// 已找到要 “要被删除的节点”, 并且该节点下只有 1 个子节点 （左或右）
		tempCell = t;
		if (t->left != NULL) {
			t = t->left;
		}
		else if (t->right != NULL) {
			t = t->right;
		}
		free(tempCell);
	}

	return t;

}

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

AvlTree findMin(AvlTree t)
{
	if (t->left) {
		return findMin(t->left);
	}
	else {
		return t;
	}
}
