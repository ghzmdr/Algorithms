#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{	
	FILE *data;
	char dest[15], code[7], name[15];
	int dhours, dminutes, hours, minutes, i;
	
	if (argc != 2)
	{
		fprintf(stderr, "uso: voli nomefile");
		exit(0);
	}
	
	data = fopen(argv[1], "r");
	
	printf("Inserisci una destinazione: ");
	scanf("%s", &dest);
	printf("Inserisci una orario: ");
	scanf("%d:%02d", &dhours, &dminutes);
	
	printf("Dalle ore %02d:%d sono disponibili i seguenti voli per '%s': \n", dhours, dminutes, dest);

	while (fscanf(data, "%s %s %d:%02d", &code, &name, &hours, &minutes) == 4){
	if (!(strcmp(dest, name)) && (hours >= dhours) && (minutes >= dminutes))
		printf("%s %d:%02d\n", code, hours, minutes); 
	}
					
	return 0;
}
