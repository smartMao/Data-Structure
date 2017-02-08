#pragma once

struct treeNode;
typedef struct treeNode *AvlTree;
typedef struct treeNode *Position;
typedef int ElementType;


AvlTree insert(ElementType elem, AvlTree t);

int height(AvlTree t);
ElementType Max(ElementType a, ElementType b);
AvlTree makeRandomAvlTree(int H);
int RandInt(int i, int j);
