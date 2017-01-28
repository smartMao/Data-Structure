
typedef int ElementType;

struct DequeRecord {
	int capacity;
	int front;
	int rear;
	int size;
	ElementType *array;
};

typedef struct DequeRecord *Deque;

Deque CreateDeque(ElementType data);

int Push(Deque Q, ElementType data);
ElementType Pop(Deque Q);

int Inject(Deque Q, ElementType data);
ElementType Eject(Deque Q);

int isFull(Deque Q);
int isEmpty(Deque Q);

