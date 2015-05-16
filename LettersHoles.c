#include <stdio.h>
#include <stdlib.h>
//COUNTS THE NUMBER OF HOLES IN THE LETTERS OF THE INPUT EG: 'B' HAS 2 HOLES, 'A' ONLY ONE
 
int main(){
	int lns, count, i;
	char ch;
	scanf("%d", &lns);
	getchar();
	while (lns--){
	
		count = 0;
			while((ch = getchar()) != '\n'){
				if( ch == 'A' || ch == 'D' || ch == 'O' || ch == 'Q' || ch == 'R' || ch == 'P')
					count++;
				else if (ch == 'B')
					count+=2;
			}
		printf("%d\n",count);
	}
	return 0;
} 
