#include <stdio.h>

int array[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 4, 6, 8, 1, 3, 5};
int LastPosition = 16;

// 删除数组中 相同的元素， 并且不能破坏数组的位置

void delete(int j);

int main()
{
	for (int i = 0; i < LastPosition; i++) {
		int j = i + 1;
		while (j < LastPosition) {
			if (array[i] == array[j])
				delete(j);
			else
				j++;
		}
	}

	for (int k = 0; k < LastPosition; k++) {
		printf("%d \n", array[k]);
	}
}

void delete(int j)
{
	for (int i = j; i < LastPosition; i++) {
		array[i] = array[i + 1];
	}
	LastPosition--;
}
