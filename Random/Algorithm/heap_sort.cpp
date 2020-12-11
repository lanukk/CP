#include<stdio.h>
int a[1000];


void swap(int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void heapify( int n, int i) {
	if (i >= n ) {
		return ;
	}
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (a[largest] < a[left] && left < n)largest = left;
	if (a[largest] < a[right] && right < n) largest = right;
	if (largest != i) {
		swap(largest, i);
		heapify( n, largest);
	}
}

int main() {
	int n;
	printf("Enter size of array : ");
	scanf("%d ", &n);
	printf("Enter array :");
	for (int i = 0 ; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i =  n / 2 - 1 ; i >= 0; i--) {
		heapify( n, i);
	}
	for (int  i = n - 1; i >= 0; i--) {
		swap(i, 0);
		heapify( i, 0);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i] );
	}

}