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


//Shellsort:
//Take the n° of elements and set a constant 'c' basing on that number
//Set a variable 'x' equal to that number/'c'

//While 'x' is > 0
	//'y' = 'x'
	//While 'y' is < lenght
		//Take the element at position 'y'
		//y = y*2
	//Compare the elements taken and swap them if needed
	//x = x/c
	
void shellSort(int *numbers, int lenght, compare cmp){

	int i, j, tmp, inc;
	for(inc = lenght/2; inc>0; inc/=2)
	   for(i=inc; i<lenght; i++)
		 for(j=i-inc; j>=0; j-=inc)
		    if(cmp(numbers[j], numbers[j+inc]) >0){
		        tmp=numbers[j];
		        numbers[j]=numbers[j+inc];
		        numbers[j+inc]=tmp;
		    } else break;
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
	
	shellSort(numbers, count, cmp);

	for (; i < count; i++)
		printf("%d  ", numbers[i]);
	printf("\n");
}

void printRawData(compare cpm){
	int i;
	unsigned char* data = (unsigned char*)cmp;
	for (i = 0; i < 25; i++)
		printf("%02x  ", data[i]);
	printf("\n");
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
