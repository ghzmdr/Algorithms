#include <stdio.h>
#include <stdlib.h>

void conquer(int *input, int low, int mid, int high){
	
	int i = low, j = mid+1, k = 0;
	int tmp[1000];
	while (i <= mid && j <= high){
		
		if (input[i] < input[j])
			tmp[k++] = input[i++];
		asd
		else tmp[k++] = input[j++];
	}
	
	while (i <= mid)  tmp[k++] = input[i++];
	while (j <= high) tmp[k++] = input[j++];
  
	for(k = low; k <= high; k++)
		input[k] = tmp[k-low];
	printf("\n");
	return;		
}

void divide(int *input, int low, int high){
	int mid;
	
	if (low < high){
	
		mid = (low+high)/2;
		divide(input, low, mid);
		divide(input, mid+1, high);
		conquer(input, low, mid, high);
	}
 	return;
}

int main (void)
{

	int i, size, input[] = {1,6,3,8,45,23,3,7,45,87,45,56,11,340};

	size = (sizeof(input)/sizeof(int));
	
	divide(input, 0, size-1);

    for (i = 0; i < size; i++)
		printf("%d ", input[i]);
	printf("\n");
	
	return 0;
}
