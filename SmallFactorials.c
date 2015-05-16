#include <stdio.h>
#include <stdlib.h>

void calc (int);

int i;

int main (){

	int lns;
	scanf("%d", &lns);
	int *values = malloc(lns*sizeof(int)), *start = values;
	for (i = 0; i < lns; i++, values++)
		scanf("%d", values);
	values = start;
	while(lns--) calc(*values++);
	free(start);
	return 0;
}

void calc (int n){
	
	int number_dig[200] = {1}, max = 1, tmp = 0,  current_mul, x;

	for(current_mul = 1; current_mul <= n; ++current_mul){
	
		for (i = 0; i < max; i++){
			x = number_dig[i]*current_mul+tmp;
			number_dig[i] = x%10;
			tmp = x/10;
		}
		while (tmp > 0){
			number_dig[i++] = tmp%10;
			tmp/=10;
		}
		max = i;
	}
	
	for (i = max-1; i >= 0; i--)
		printf("%d", number_dig[i]);
	printf("\n");
}
