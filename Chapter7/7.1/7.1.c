#include <stdio.h>

// 7.1 实现：使用插入排序将序列 {3， 1， 4， 1， 5， 9， 2， 6， 5} 排序


typedef int ElementType;

void InsertionSort(ElementType A[], int N);

void main(void)
{

	ElementType A[] = {3, 1, 4, 1, 5, 9, 6, 5};

	int N = sizeof(A) / sizeof(ElementType);
	InsertionSort(A, N);

	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}

}


void InsertionSort(ElementType A[], int N)
{
	int j, P;
	ElementType Tmp;

	for (P = 1; P < N; P++) {
		Tmp = A[P];
		for (j = P; j > 0 && A[j - 1] > Tmp; j--) {
			A[j] = A[j - 1];
		}
		A[j] = Tmp;
	}
}

