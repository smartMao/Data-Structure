
// 只使用指向二叉树根节点的指针 T， 并计算 T 中的节点数量 、T 中的树叶的片数、T 中满节点的个数。

void nodeTreeInfo(SearchTree T)
{
	if (T) {
		nodeTotalCount++;
		if (T->Left && T->Right) {
			nodeFullCount++;
		}
		if (T->Left == NULL && T->Right == NULL) {
			nodeLeafCount++;
		}

		nodeTreeInfo(T->Left);
		nodeTreeInfo(T->Right);
	}
}
