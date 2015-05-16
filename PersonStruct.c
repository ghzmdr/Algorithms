#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//Define a new structure named person
struct Person{
	char *name;
	int age;
	int height;
	int weight;
};

//A function to create a new person and give her initial values
struct Person *personCreate(char *name, int age, int height, int weight){
	struct Person *who= malloc(sizeof(struct Person));
	assert(who != NULL);
	
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	
	return who;
}

//A function for free the memory used
void personKill(struct Person *who){
	assert(who != NULL);
	
	free(who->name);
	free(who);
}

//A function that prints out infos
void personPrint(struct Person *who){
	printf("Name: %s\n", who->name);
	printf("Age: %d\n", who->age);
	printf("Height: %d\n", who->height);
	printf("Weight: %d\n", who->weight);
}

int main (int argc, char **argv){
	struct Person *joe = personCreate("Joe Someone", 20, 170, 70);
	struct Person *will = personCreate("Will ItBe", 30, 180, 100);
	
	printf("Joe is at memory location: %p\n", joe);
	printf("Will is at memory location: %p\n", will);
	
	joe->age += 20;
	joe->height += 20;
	joe-> weight += 20;
	personPrint(joe);
	
	will->age += 5;
	will->height += 30;
	personPrint(will);
	
	personKill(joe);
	personKill(will);	

	return 0;
}
