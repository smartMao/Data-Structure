#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// 实现 - 查找出二叉树内，大于 k1 小于 k2 的节点


int main()
{
	SearchTree T;
	T = Insert(5, NULL);

	for (int i = 0; i < 400; i++ ) {
		T = Insert(rand(), T);
	}
	printBetweenK1K2(T, 10, 300);
}


void printBetweenK1K2(SearchTree t, int k1, int k2)
{
	if (t) {
		if(t->Element >= k1){
			printBetweenK1K2(t->Left, k1, k2);
		}
		else if (t->Element >= k1 && t->Element <= k2) {
			printf("%d ", t->Element);
		}
		else if (t->Element <= k2) {
			printBetweenK1K2(t->Right, k1, k2);
		}
	}
}


/* 清空二叉树 T */
SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}


/* 递归查找 */
Position Find(ElementType Elem, SearchTree T)
{
	if (T != NULL) {
		if (Elem < T->Element) {
			return Find(Elem, T->Left);
		}
		else if (Elem > T->Element) {
			return Find(Elem, T->Right);
		}
		else {
			// Elem == T->Element
			return T;
		}
	}
	else {
		return NULL;
	}
}

/* 递归插入 */
SearchTree Insert(ElementType Elem, SearchTree T)
{
	if (T == NULL) {
		T = malloc(sizeof(TreeNode));
		if (T == NULL) {
			exit(1);
		}
		else {
			T->Element = Elem;
			T->Left = NULL;
			T->Right = NULL;
		}
	}
	else {
		if (Elem < T->Element) 
			T->Left = Insert(Elem, T->Left);
		else if(Elem > T->Element) 
			T->Right = Insert(Elem, T->Right);
	}

	return T;
}


SearchTree Delete(ElementType Elem, SearchTree T)
{
	Position TempCell;

	if (T == NULL) {
		exit(1);
	}
	else if (Elem < T->Element) {
		T->Left = Delete(Elem, T->Left);
	}
	else if (Elem > T->Element) {
		T->Right = Delete(Elem, T->Right);
	}
	else if (T->Left && T->Right) {
		TempCell = FindMin(T->Right);
		T->Element = TempCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else {
		TempCell = T;
		if (T->Left == NULL) {
			T = T->Right;
		}
		else if (T->Right == NULL) {
			T = T->Left;
		}
		free(TempCell);
	}
	return T;
}

Position FindMin(SearchTree T)
{
	if (T == NULL) {
		return T;
	}
	else if (T->Left == NULL) {
		return T;
	}
	else {
		return FindMin(T->Left);
	}
}
