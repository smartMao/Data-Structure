#include <stdio.h>

typedef int ElementType;

void Swap(ElementType *a, ElementType *b);
void QuickSort(ElementType A[], int length);


void main(void)
{

	ElementType A[] = {25, 48, 16,18, 36, 17,6,15,38,22,42 , 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48, 19,6,7,69};

	int length = sizeof(A) / sizeof(ElementType);
	QuickSort(A, length);

}

void QuickSort(ElementType A[], int length)
{
	int pivot = 0; // 将第一个元素设置为轴心
	int index = pivot + 1; //存储下标

	int hasElementLtPivot = 0;  // 在数组中有没有元素小于当前的 轴心

	for (int k = 0; k < length; k++) {
		hasElementLtPivot = 0;

		int index = pivot + 1;
		for (int i = pivot + 1; i < length; i++ ) {
			if (A[i] < A[pivot]) {
				if (index == i) {
					index++;
					continue;
				}
				Swap(&A[index], &A[i]);

				index++;
			}
		}

		Swap(&A[pivot], &A[--index]);

		for (int g = pivot + 1; g < length; g++) {
			if ( A[g] < A[pivot] ) {
				// 在数组中， 有其他 元素小于轴心元素
				hasElementLtPivot = 1;
				break;
			}
		}

		if (!hasElementLtPivot) {
			// 当数组中，没有其他元素小于轴心元素时， 将轴心下标++, 换另外一个轴心
			pivot++;
		}

	}
	
	for (int p = 0; p < length; p++) {
		printf("%d ", A[p]);
	}

}


void Swap(ElementType *a, ElementType *b)
{
	ElementType tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}







void InsertionSort(ElementType A[], int N)
{
	int j, P;

	ElementType Tmp;
	for (P = 1; P < N; P++) {
		Tmp = A[P];
		for (j = P; j > 0 && A[j - 1] > Tmp; j-- ) {
			A[j] = A[j-1];
		}
		A[j] = Tmp;
	}

}



