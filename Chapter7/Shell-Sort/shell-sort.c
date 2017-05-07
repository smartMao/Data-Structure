#include <stdio.h>

typedef int ElementType;

void Shellsort(ElementType A[], int N);


void main(void)
{
	ElementType A[] = {89, 29, 85, 67, 99, 22};
	
	Shellsort(A, sizeof(A) / 4);

	for (int i = 0; i < 6; i++ ) {
		printf("%d \n", A[i]);
	}

}

void Shellsort(ElementType A[], int N)
{
	int i, j, Increment;
	ElementType Tmp;

	for (Increment = N / 2; Increment > 0; Increment /= 2) {
		for (i = Increment; i < N; i++) {
			
			Tmp = A[i];
			for (j = i; j >= Increment; j -= Increment) {
				if (Tmp < A[j-Increment]) {
					A[j] = A[j - Increment];
				}
				else {
					break;
				}
			}
			A[j] = Tmp;
		}
	}
}
