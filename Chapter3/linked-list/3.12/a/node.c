#ifndef _list_h
#define _list_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType; 

void create(List head, int size);
void printfList(List head);
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(List L);
Position Findl(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious (ElementType X, List L);
void insert (ElementType X,  Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void find_by_pos(int pos, List L);
void printfLots(List L, List P );
void swapWithNext(List L, Position BeforeP);
List reverseLink(List list);


struct Node
{
	ElementType Element;
	struct Node * Next;
};

#endif
