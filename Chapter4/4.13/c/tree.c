#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define CursorSpaceNum 100

// 实现： 编写一个程序，删除某节点，规则是：随机交替使用 左子树中 最大的节点 和 右子树中 最小的节点 来代替 “被删除的节点”

struct TreeNode {
	ElementType element;
	Position left;
	Position right;
};

struct TreeNode cursorSpace[CursorSpaceNum];

static PtrToNode cursorNew()
{
	PtrToNode p;
	p = cursorSpace[0].left;
	cursorSpace[0].left = cursorSpace[p].left;
	return p;
}

static void cursorDispose(PtrToNode p) 
{
	cursorSpace[p].left = cursorSpace[0].left;
	cursorSpace[0].left = p;
}


int main()
{
	initializeCursorSpace();
	SearchTree t = 0;

	t = insert(5, t);
	t = insert(9, t);
	t = insert(1, t);
	t = insert(3, t);
	t = insert(2, t);
	t = insert(4, t);
	t = insert(8, t);
	t = insert(12, t);

	Delete(5, t);
	Delete(4, t);
}

SearchTree Delete(ElementType elem, SearchTree t)
{
	int num = 0;
	if (t == 0) {
		return 0;
	}
	else {
		if (elem < cursorSpace[t].element) {
			Delete(elem, cursorSpace[t].left);
		}
		else if (elem > cursorSpace[t].element) {
			Delete(elem, cursorSpace[t].right);
		}
		else {
			// 已找到要删除的节点， 还需要知道“要删除节点” 的子节点
			SearchTree tempCell;

			if (cursorSpace[t].left && cursorSpace[t].right) {

				// 随机
				srand(time(0));
				if (rand() % 2) {
					tempCell = findMax(cursorSpace[t].left);
					cursorSpace[t].element = cursorSpace[tempCell].element;
					cursorSpace[t].left = Delete(cursorSpace[t].element, cursorSpace[t].left);
				}else{
					tempCell = findMin(cursorSpace[t].right);
					cursorSpace[t].element = cursorSpace[tempCell].element;
					cursorSpace[t].right = Delete(cursorSpace[t].element, cursorSpace[t].right);
				}

			}
			else {
				tempCell = t;
				if (cursorSpace[t].left == 0) {
					t = cursorSpace[t].right;
				}
				else if (cursorSpace[t].right == 0) {
					t = cursorSpace[t].right;
				}
				cursorDispose(tempCell);
			}
		}
	}
	return t;

}


SearchTree insert(ElementType elem, SearchTree t)
{
	if (t == 0) {
		t = cursorNew();
		
		cursorSpace[t].element = elem;
		cursorSpace[t].right = 0;
		cursorSpace[t].left = 0;
	}
	else {
		if (elem < cursorSpace[t].element) {
			cursorSpace[t].left = insert(elem, cursorSpace[t].left);
		}
		else if (elem > cursorSpace[t].element) {
			cursorSpace[t].right = insert(elem, cursorSpace[t].right);
		}
	}
	return t;
}

Position find(ElementType elem, SearchTree t)
{
	if (t == 0) {
		return 0;
	}
	else {
	
		if (elem < cursorSpace[t].element) {
			return find(elem, cursorSpace[t].left);
		}
		else if (elem > cursorSpace[t].element) {
			return find(elem, cursorSpace[t].right);
		}
		else {
			return t;
		}
	}


}

void initializeCursorSpace(void)
{
	for (int i = 0; i < CursorSpaceNum; i++) {
		cursorSpace[i].left = i + 1;
	}
	cursorSpace[CursorSpaceNum - 1].left = 0;
}

Position findMin(SearchTree t)
{
	if (cursorSpace[t].left == 0) {
		return t;
	}
	else {
		findMin(cursorSpace[t].left);
	}
}

Position findMax(SearchTree t)
{
	if (cursorSpace[t].right == 0) {
		return t;
	}
	else {
		findMax(cursorSpace[t].right);
	}
}
