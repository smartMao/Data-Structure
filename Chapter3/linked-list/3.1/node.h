#ifndef _list_h
#define _list_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType; 

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(List L);
Position Findl(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious (ElementType X, List L);
void Insert (ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);


struct Node
{
	ElementType Element;
	struct Node * Next;
};

#endif
