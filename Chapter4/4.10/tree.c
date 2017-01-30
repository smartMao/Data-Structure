#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// 实现 - 二叉树的基本操作


int main()
{
	SearchTree T;
	T = Insert(5, NULL);

	T = Insert(1, T);
	T = Insert(2, T);
	T = Insert(4, T);
	T = Insert(3, T);

	T = Insert(6, T);
	T = Insert(7, T);
	T = Insert(8, T);

	Delete(8, T);
	SearchTree FindRes;
	FindRes = Find(8, T);

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
