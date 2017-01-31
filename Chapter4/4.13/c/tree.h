typedef int ElementType;
#define SpaceSize 100  
#ifndef _Tree_H
#define _Tree_H

typedef int PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode SearchTree;

void initializeCursorSpace(void);
void makeEmpty(SearchTree t);
void Dir(SearchTree t);

Position find(ElementType X, SearchTree t);
Position findMin(SearchTree t);
Position findMax(SearchTree t);
SearchTree insert(ElementType X, SearchTree t);
SearchTree Delete(ElementType X, SearchTree t);
ElementType Retrieve(Position p);

#endif
