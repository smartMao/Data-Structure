#include <stdio.h>
#include <stdlib.h>
#include"tree.h"

struct TreeNode {
	ElementType element;
	SearchTree left;
	SearchTree right;
};

struct TreeNode cursorSpace[SpaceSize];


// 实现 - 二叉树的查找游标实现

int main()
{

    initializeCursorSpace();  
    SearchTree t = 0;  
  
    t = insert(3, t);  
    t = insert(1, t);  
    t = insert(4, t);  
    t = insert(6, t);  
    t = insert(9, t);  
    t = insert(2, t);  
    t = insert(5, t);  
    t = insert(7, t);  
  
    Dir(t);  
    printf("\n");  
    Delete(3, t);  
  
    Dir(t);  

}

static PtrToNode cursorNew() {
	PtrToNode p;
	p = cursorSpace[0].left;
	cursorSpace[0].left = cursorSpace[p].left;
	return p;
}

static void cursorDispose(PtrToNode p) {
	cursorSpace[p].left = cursorSpace[0].left;
	cursorSpace[0].left = p;
}

void initializeCursorSpace(void) {
	for (int i = 0; i < SpaceSize-1; i++) {
		cursorSpace[i].left = i + 1;
	}
	cursorSpace[SpaceSize - 1].left = 0;
}

void makeEmpty(SearchTree t) {
	if (t) {
		makeEmpty(cursorSpace[t].left);
		makeEmpty(cursorSpace[t].right);
		cursorDispose(t);
	}
}

Position find(ElementType X, SearchTree t) {
	if (t == 0)
		return 0;//NOT FOUND
	else {
		if (X < cursorSpace[t].element)
			return find(X, cursorSpace[t].left);
		else if (X>cursorSpace[t].element)
			return find(X, cursorSpace[t].right);
		else
			return t;
	}
}

Position findMin(SearchTree t) {
	while (cursorSpace[t].left)
		t = cursorSpace[t].left;
	return t;
}

Position findMax(SearchTree t) {
	while (cursorSpace[t].right)
		t = cursorSpace[t].right;
	return t;
}

SearchTree insert(ElementType X, SearchTree t) {
	if (t == 0) {//包含树没有初始化
		t = cursorNew();
		if (t == 0) {
			//Error("out of cursorSpace");
			exit(1);
		}
		cursorSpace[t].element = X;
		cursorSpace[t].left = 0;
		cursorSpace[t].right = 0;
	}
	else {
		if (X < cursorSpace[t].element)
			cursorSpace[t].left = insert(X, cursorSpace[t].left);
		else if (X>cursorSpace[t].element)
			cursorSpace[t].right = insert(X, cursorSpace[t].right);
	}
	return t;//两种情况
}

SearchTree Delete(ElementType X, SearchTree t) {
	Position tempCell;
	if (t == 0) {
		//Error("Element not found");
	}
	else if (X < cursorSpace[t].element)
		cursorSpace[t].left = Delete(X, cursorSpace[t].left);
	else if (X > cursorSpace[t].element)
		cursorSpace[t].right = Delete(X, cursorSpace[t].right);
	else if (cursorSpace[t].left && cursorSpace[t].right) {
		tempCell = findMin(cursorSpace[t].right);
		cursorSpace[t].element = cursorSpace[tempCell].element;
		cursorSpace[t].right = Delete(cursorSpace[t].element, cursorSpace[t].right);
	}
	else {
		tempCell = t;
		if (cursorSpace[t].left == 0)
			t = cursorSpace[t].right;
		else if (cursorSpace[t].right == 0)
			t = cursorSpace[t].left;
		cursorDispose(tempCell);
	}
	return t;
}

ElementType Retrieve(Position p) {
	return cursorSpace[p].element;
}

void Dir(SearchTree t) {
	if (t) {
		printf("%d ", cursorSpace[t].element);
		Dir(cursorSpace[t].left);
		Dir(cursorSpace[t].right);
	}
}
