#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"

int main()
{
	// 实现：交换双链表中相邻的两个节点
	DOUBLE_LIKE_NODE *pDLinkNode;
	pDLinkNode = (DOUBLE_LIKE_NODE *)malloc(sizeof(DOUBLE_LIKE_NODE));
	pDLinkNode = create_double_link_node(1);
	DOUBLE_LIKE_NODE **node;
	node = &pDLinkNode;

	insert_data_into_double_link(node, 2);
	insert_data_into_double_link(node, 3);
	insert_data_into_double_link(node, 4);
	insert_data_into_double_link(node, 5);

	switch_double_link_node(*node, 1);
	switch_double_link_node(*node, 3);

	print_double_link_node(*node);

}

/*
交换位置相邻的两个节点
pos = 要交换节点的下标（往后对节点交换）
*/
STATUS switch_double_link_node(DOUBLE_LIKE_NODE *pDLinkNode, int pos)
{
	if (pDLinkNode == NULL) {
		return 0;
	}

	DOUBLE_LIKE_NODE *pBefore;
	DOUBLE_LIKE_NODE *pIndex;
	DOUBLE_LIKE_NODE *pAfter;

	pIndex = pDLinkNode;
	int index = 0;
	while (pIndex != NULL) {
		if (index == pos) {
			if (pIndex->next != NULL) {
				// 可以跟下一个节点进行交换
				pBefore = pIndex->prev;
				pAfter = pIndex->next;

				pBefore->next = pAfter;
				pAfter->prev = pBefore;

				pIndex->prev = pAfter;
				pIndex->next = pAfter->next;

				if (pIndex->next == NULL) {
					return 0;
				}
				
				pIndex->next->prev = pIndex;
				pAfter->next = pIndex;

				return 1;
			}
			else {
				// 没有可供交换的节点
				return 0;
			}
		}
		else {
			pIndex = pIndex->next;
			index++;
		}
	}

	return 0;
}

/*创建双链表节点*/
DOUBLE_LIKE_NODE* create_double_link_node(int value)
{
	DOUBLE_LIKE_NODE * pDLinkNode = NULL;
	pDLinkNode = (DOUBLE_LIKE_NODE *)malloc(sizeof(DOUBLE_LIKE_NODE));
	assert(NULL != pDLinkNode); // 错误检测

	memset(pDLinkNode, 0, sizeof(DOUBLE_LIKE_NODE)); // 初始化 pDLinkNode
	pDLinkNode->data = value;
	return pDLinkNode;
}

/*插入数据*/
STATUS insert_data_into_double_link(DOUBLE_LIKE_NODE **ppDLinkNode, int data)
{
	DOUBLE_LIKE_NODE *pNode;
	DOUBLE_LIKE_NODE *pIndex;

	if (NULL == *ppDLinkNode) {
		// 不存在传入的链表，则创建一个
		pNode = create_double_link_node(data);
		assert(pNode != NULL);
		*ppDLinkNode = pNode;
		(*ppDLinkNode)->prev = NULL;
		(*ppDLinkNode)->next = NULL;
		return 1;
	}

	// 创建节点
	pNode = create_double_link_node(data);

	pIndex = *ppDLinkNode;
	while (pIndex->next != NULL) {
		pIndex = pIndex->next;
	}

	pNode->prev = pIndex;
	pNode->next = pIndex->next; // 此时的 pIndex->next == NULL
	pIndex->next = pNode;

	return 1;
}

/*打印链表中的元素*/
void print_double_link_node(const DOUBLE_LIKE_NODE *pDLinkNode)
{
	DOUBLE_LIKE_NODE *pIndex;
	pIndex = (DOUBLE_LIKE_NODE *)pDLinkNode;
	int i = 0;
	while (pIndex != NULL) {
		i++;
		printf("index = %d , data = %d \n", i, pIndex->data);
		pIndex = pIndex->next;
	}
}
