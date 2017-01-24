#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"

int main()
{
	// 实现: 有 已排序的双链表 node1 与 node2 ， 取交集存放到 nodeUnion 中;

	// node 1
	DOUBLE_LIKE_NODE *pDLinkNode1;
	pDLinkNode1 = (DOUBLE_LIKE_NODE *)malloc(sizeof(DOUBLE_LIKE_NODE));
	pDLinkNode1 = create_double_link_node(1);
	DOUBLE_LIKE_NODE **node1;
	node1 = &pDLinkNode1;

	// node2
	DOUBLE_LIKE_NODE *pDLinkNode2;
	pDLinkNode2 = (DOUBLE_LIKE_NODE *)malloc(sizeof(DOUBLE_LIKE_NODE));
	pDLinkNode2 = create_double_link_node(1);
	DOUBLE_LIKE_NODE **node2;
	node2 = &pDLinkNode2;

	insert_data_into_double_link(node1, 2);
	insert_data_into_double_link(node1, 3);
	insert_data_into_double_link(node1, 4);
	insert_data_into_double_link(node1, 8);

	insert_data_into_double_link(node2, 4);
	insert_data_into_double_link(node2, 9); 
	insert_data_into_double_link(node2, 2); 
	insert_data_into_double_link(node2, 100); 

	DOUBLE_LIKE_NODE *nodeUnion;
	nodeUnion = (DOUBLE_LIKE_NODE *)malloc(sizeof(DOUBLE_LIKE_NODE));
	*nodeUnion = double_link_node_union(*node1, *node2); // 找出并集

	// 删除头结点
	nodeUnion = nodeUnion->next;
	nodeUnion->prev->next = NULL;
	nodeUnion->prev = NULL;

	print_double_link_node(nodeUnion);

}

/* 已排序的双链表 node1 与 node2 ， 取交集存放到 nodeUnion 中;*/
DOUBLE_LIKE_NODE double_link_node_union(DOUBLE_LIKE_NODE *node1, DOUBLE_LIKE_NODE *node2)
{
	DOUBLE_LIKE_NODE **node;
	DOUBLE_LIKE_NODE *nodeUnion;
	node = &nodeUnion;
	nodeUnion = create_double_link_node(0);

	while (node1) {
		if (!find_data_in_double_link(nodeUnion, node1->data)) {
			insert_data_into_double_link(node, node1->data);
		}
		node1 = node1->next;
	}

	while (node2) {
		if (find_data_in_double_link(nodeUnion, node2->data)) {
			insert_data_into_double_link(node, node2->data);
		}
		node2 = node2->next;
	}
	return *nodeUnion;
}

/*
	取 node1 与 node2 的交集，存放到 nodeIntersect 当中
*/
DOUBLE_LIKE_NODE double_link_node_intersect(DOUBLE_LIKE_NODE *node1, DOUBLE_LIKE_NODE *node2)
{ 
	// 使用简单的暴力枚举法

	DOUBLE_LIKE_NODE *temp_node1;
	DOUBLE_LIKE_NODE *temp_node2;
	temp_node1 = node1;
	temp_node2 = node2;

	DOUBLE_LIKE_NODE temp;
	DOUBLE_LIKE_NODE *nodeIntersect;
	nodeIntersect = (DOUBLE_LIKE_NODE *)malloc(sizeof(DOUBLE_LIKE_NODE));
	nodeIntersect = create_double_link_node(0);

	while (temp_node1) {
		
		if (find_data_in_double_link(temp_node2, temp_node1->data)) {

			nodeIntersect->next = temp_node1;
			temp_node1->prev = nodeIntersect;
			nodeIntersect = nodeIntersect->next;
		}
		temp_node1 = temp_node1->next;
	}
	nodeIntersect->next = NULL;
	return *nodeIntersect;
}

STATUS find_data_in_double_link(DOUBLE_LIKE_NODE *head, int data)
{
	DOUBLE_LIKE_NODE *pIndex = head;
	while (pIndex) {
		if (pIndex->data == data) {
			return 1;
		}
		pIndex = pIndex->next;
	}

	return 0;
}

/*
	返回 节点 temp_node 在 节点node 中的下一个节点 
*/
DOUBLE_LIKE_NODE get_next_double_link_node(DOUBLE_LIKE_NODE *temp_node, DOUBLE_LIKE_NODE *node)
{
	return *temp_node->next;
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

	// 移动到头结点
	while (pIndex->prev) {
		pIndex = pIndex->prev;
	}

	int i = 0;
	while (pIndex != NULL) {
		i++;
		//printf("index = %d , data = %d \n", i, pIndex->data);
		printf("data = %d \n", pIndex->data);
		pIndex = pIndex->next;
	}
}

/*打印链表中的元素(从尾到头)*/
void print_to_head_double_link_node(const DOUBLE_LIKE_NODE *pDLinkNode)
{
	DOUBLE_LIKE_NODE *pIndex;
	pIndex = (DOUBLE_LIKE_NODE *)pDLinkNode;

	while (pIndex != NULL) {

		printf("data = %d \n", pIndex->data);
		pIndex = pIndex->prev;
	}
}

/*删除掉头节点*/
STATUS delete_head_double_link_node(DOUBLE_LIKE_NODE *node)
{
	while(node->prev != NULL){
		node = node->prev;
	}

	node = node->next;
	node->prev->next = NULL;
	node->prev = NULL;

	return 1;
}
