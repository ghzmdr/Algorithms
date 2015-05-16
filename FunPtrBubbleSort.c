#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//Using this kind of polimorphysm we don't have to write 3 different bubbleSort functions.
//Instead we write it only once and change the sorting rule by passing a different function each time.
//This lets the caller pass in anything they want as long as it matches the signature of the defined "compare" type.

void die(const char* message){
	if (errno)	perror(message);
	else printf("ERROR: %s\n", message);
	exit(1);
}

typedef int(*compare)(int a, int b);

int *bubbleSort(int *numbers, int count, compare cmp){
	int tmp = 0, i = 0, j = 0;
	int *target = malloc(count*sizeof(int));
	
	if (!target) die("Memory Fault");
	
	memcpy(target, numbers, count * sizeof(int));
	
	for (i = 0; i < count; i++)
		for (j = 0; j < count -1; ++j)
			if (cmp(target[j], target[j+1]) > 0){
				tmp = target[j+1];
				target[j+1] = target[j];
				target[j] = tmp;
			}
	return target;
}

int sortedOrder(int a, int b){
	return a-b;
}

int reverseOrder(int a, int b){
	return b-a;
}

int strangeOrder(int a, int b){
	if (a == 0 || b == 0)	return 0;
	else return a%b;
}

void testSort(int *numbers, int count, compare cmp){
	int i = 0;
	int *sorted = bubbleSort(numbers, count, cmp);
	if (!sorted)	die("Unexpected error while sorting");

	for (; i < count; i++)
		printf("%d  ", sorted[i]);
	free(sorted);
	printf("\n");
	
	//Uncomment this to see the value of the cmp function as raw hex chars
	/*
	unsigned char* data = (unsigned char*)cmp;
	for (i = 0; i < 25; i++)
		printf("%02x  ", data[i]);
	printf("\n");
	*/
}

int main (int argc, char **argv){
	if (argc < 2)	die("USAGE: ./program n1, n2, n3, n4, n5, ..., n");
	
	int count = argc-1, i = 0;
	
	int *numbers = malloc(count*sizeof(int));
	if (!numbers)	die("Memory Fault");
	
	for(; i < count; ++i)
		numbers[i] = atoi(argv[i+1]);
	
	testSort(numbers, count, sortedOrder);
	testSort(numbers, count, reverseOrder);
	testSort(numbers, count, strangeOrder);
	
	free(numbers);
	return 0;
}
