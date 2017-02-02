#include"AVL-Tree.h"
#include<stdio.h>
#include<stdlib.h>

// 实现 - 写出执行双旋转的函数，执行效率要超过执行两个单旋转 （4.18题就是用两个单旋转函数组合成一个双旋转函数）

int main() {
	AvlTree t = NULL;

	//int array[100] = { 50, 40, 30, 20, 10, 5 }; // 单旋转
	//int array[100] = { 10 , 6, 4}; // 单旋转
	//int array[100] = { 40, 30 , 50, 31, 32}; // 单旋转
	//int array[100] = { 50, 60 , 40, 30, 20}; // 单旋转
	//int array[100] = { 10 , 4 ,6}; // 双旋转
	int array[100] = { 5, 15, 10}; // 双旋转
	//int array[100] = { 10 , 16 ,15}; // 双旋转
	//int array[100] = { 50, 20, 70, 10, 30, 60, 80, 4, 6}; // 双旋转
	//int array[100] = {52,61,81,49,75,63,85,26,89,68,78,56,15};

	for (int i = 0; i < 3; i++) {
		//t= insert(rand() % 100, t);
		t = insert(array[i], t);
	}
}
