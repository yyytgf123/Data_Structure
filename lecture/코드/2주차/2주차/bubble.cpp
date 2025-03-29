#include <stdio.h>
#include <stdlib.h>

void bubble(int arr[], int n) {
	int i, j;
	int tmp;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1; j++) {
			if (arr[j - 1] > arr[j]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
 			}
		}	
	}
}

int main() {
	int arr[5] = { 8, 2, 19, 12, 7 };

	bubble(arr, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
}