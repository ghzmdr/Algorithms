#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int age, height, weight;	
	char *name;
} person;

person personCreate(char *name, int age, int height, int weight){
	person who;
	who.name = strdup(name);
	who.age = age;
	who.height = height;
	who.weight = weight;
	
	return who;
}

void personPrint(person who){
	printf("Name: %s\n", who.name);
	printf("Age: %d\nHeight: %d\nWeight: %d\n", who.age, who.height, who.weight);	
}

int main(int argc, char **argv){
	person joe = personCreate("Joe Someone", 20, 170, 80);
	person will = personCreate("Will ItBe", 30, 180, 90);
	
	personPrint(joe);
	personPrint(will);
	free(joe.name);
	free(will.name);
	
	return 0;
}
