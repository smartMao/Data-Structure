#pragma once
#ifndef _Tree_H

struct TreeNode;

typedef struct TreeNode *SearchTree;
typedef struct TreeNode *Position;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType Elem, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType Elem, SearchTree T);
SearchTree Delete(ElementType Elem, SearchTree T);
void printBetweenK1K2(SearchTree t, int k1, int k2);

#endif 

struct TreeNode {
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
} TreeNode;
