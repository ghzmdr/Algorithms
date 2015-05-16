#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	FILE *file;
	file = fopen("enormous_file.txt", "w");

	srand((unsigned)time(NULL));

	int max_lns = rand()%1000000 +1, i;
	fprintf(file, "%d %d\n", max_lns, rand()%10000000 +1);

	for(i = 0; i < max_lns; i++)
		fprintf(file, "%d\n", rand()%1000000000 +1);0,
	fclose(file);
	return 0;
} 

