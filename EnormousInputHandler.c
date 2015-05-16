#include <stdio.h>

int main (){

int lines_n, divider, current, i, counter=0;
	
	scanf("%d%d", &lines_n, &divider);
	for(i = 0; i < lines_n; ++i)
	{
		scanf("%d", &current);
		if (!(current%divider))
			++counter;
	}
	printf("%d\n", counter);
	return 0;
}




