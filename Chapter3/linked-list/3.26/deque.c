#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// 实现： 双端队列

int main()
{
	ElementType data = 0;
	Deque Q;
	Q = CreateDeque(10);

	Push(Q, 7);
	data = Pop(Q);

	Inject(Q, 9);
	data = Eject(Q);
	
	return 0;

}

Deque CreateDeque(int MaxElemLength)
{
	Deque Q;
	Q = (Deque)malloc(sizeof(Deque));
	Q->array = (ElementType *)malloc(MaxElemLength * sizeof(ElementType));

	Q->front = 1;
	Q->rear = 0;
	Q->size = 0;
	Q->capacity = MaxElemLength;

	return Q;
}

/* 从队列前端插入 */
int Push(Deque Q, ElementType data)
{
	if (isFull(Q)) 
		return 0; // 队列已满

	Q->front = (Q->front - 1 + Q->capacity) % Q->capacity;
	Q->array[Q->front] = data;
	Q->size++;
	return 1;
}

/* 从队列前端移除，并返回该元素 */
ElementType Pop(Deque Q)
{
	if (isEmpty(Q))
		return 0;
	
	ElementType returnData = 0;
	returnData = Q->array[Q->front];
	Q->front = (Q->front + 1 + Q->capacity) % Q->capacity;
	Q->size--;
	return returnData;
}

int Inject(Deque Q, ElementType data)
{
	if (isFull(Q))
		return 0;
	Q->rear = (Q->rear + 1 + Q->capacity) % Q->capacity;
	Q->array[Q->rear] = data;
	Q->size++;

	return 1;
}

/* 从队列后端移除，并返回该元素 */
ElementType Eject(Deque Q)
{
	if (isEmpty(Q))
		return 0;
	
	ElementType returnData = 0;
	returnData = Q->array[Q->rear];
	Q->front = (Q->rear - 1 + Q->capacity) % Q->capacity;
	Q->size--;
	return returnData;
}


/* 队列是否满 */
int isFull(Deque Q)
{
	if (Q->size >= Q->capacity) 
		return 1;
	else 
		return 0;
}

/* 队列是否为空 */
int isEmpty(Deque Q)
{
	if (Q->size == 0) 
		return 1;
	else
		return 0;
}

