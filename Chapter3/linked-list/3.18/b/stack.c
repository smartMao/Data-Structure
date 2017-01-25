#include "stack.h"  
#include <stdio.h>  
#include <strinG.h>  
#include <malloc.h>  
#include <assert.h>

#define FALSE 0

// 实现： 栈的应用 - 平衡符号

typedef struct STACK_NODE
{
	STACK_TYPE value;
	struct STACK_NODE *next;
} StackNode;

static StackNode *stack; // 指向堆栈中第一个节点的指针


int main()
{
	int strLen = 0;
	char string[100];
	// 输入 ([{}]) 、/* asndni */ 之类的
	scanf("%[^\n]", string); // 匹配input中 “除\n以外的任何字符” (为了匹配空格)

	strLen = strlen(string);
	
	for (int i = 0; i < strLen; i++) {
		switch (string[i]) {
			case '{':
				push(string[i]);
				break;
			case '[':
				push(string[i]);
				break;
			case '(':
				push(string[i]);
				break;
			case '/':
				if (string[i+1] == '*') {
					push(string[i]);
					push(string[i+1]);
				}
				break;
		}

		switch (string[i]) {
			case '}':
				if ((top()) == '{') {
					pop();
				}
				break;
			case ']':
				if ((top()) == '[') {
					pop();
				}
				break;
			case ')':
				if ((top()) == '(') {
					pop();
				}
				break;
			case '*':
				if (string[i+1] == '/') {
					if ((top()) == '*') {
						pop();
						if ((top()) == '/') {
							pop();
						}
					}
				}
		}
	}
	
	if (stack == NULL) 
		printf("succ \n ");
	else
		printf("fail \n ");
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





