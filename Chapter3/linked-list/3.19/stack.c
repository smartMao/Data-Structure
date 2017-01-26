#include "stack.h"  
#include <stdio.h>  
#include <strinG.h>  
#include <malloc.h>  
#include <assert.h>

#define FALSE 0

// 实现： 计算后缀表达式

typedef struct STACK_NODE
{
	STACK_TYPE value;
	struct STACK_NODE *next;
} StackNode;

static StackNode *stack; // 指向堆栈中第一个节点的指针


int main()
{
	char string[100];
	// 输入 12+3+3-   /  45+1-5+
	scanf("%[^\n]", string); // 匹配input中 “除\n以外的任何字符” (为了匹配空格)
	suffixCalc(string);
}

void suffixCalc(char string[])
{
	char symbol[100];
	int strLen = 0;
	int symIndex = 0;

	strLen = strlen(string);

	for (int i = strLen-1; i >= 0; i--) {
		if ((string[i] - '0') >= 0) {
			push(string[i] - '0');
		}
		else {
			switch (string[i]) {
				case '+':
				case '-':
				case '*':
				case '/':
					symbol[symIndex++] = string[i];
					break;
				default:
					// 不合法的符号
					exit(1);
			}
		}
	}

	symbol[symIndex] = '\0';

	int a;
	int b;
	int result;
	int symLen;

	symLen = strlen(symbol);

	for (int i = symLen-1; i >= 0; i--) {
		a = top(); pop();
		b = top(); pop();

		switch (symbol[i]) {
			case '+':
				result = a + b;
				push(result);
				break;
			case '-':
				result = a - b;
				push(result);
				break;
			case '*':
				result = a * b;
				push(result);
				break;
			case '/':
				result = a / b;
				push(result);
				break;
		}

	}

	printf("result = %d \n", top());
}

void push(STACK_TYPE value)
{
	StackNode *newNode;
	newNode = (StackNode *)malloc(sizeof(StackNode));
	if (newNode == NULL) 
		exit(1);

	newNode->value = value;
	newNode->next = stack;

	stack = newNode;
}

void pop()
{
	StackNode *firstNode;
	firstNode = stack;
	stack = stack->next;
	free(firstNode);
}

char top()
{
	return stack->value;
}

void printStack()
{
	int i = 0;
	StackNode *pIndex;
	pIndex = stack;
	while(pIndex){
		printf("index = %d , value = %d \n", i++, pIndex->value);
		pIndex = pIndex->next;
	}
}

int isEmpty()
{
	if (stack == NULL)
		return 1;
	else
		return 0;
}



