#include <stdio.h>
#include <stdlib.h>
void sort (int [], int, int);

int main (){

	int i, lns, items[1000000]
	
	scanf("%d", &lns);

	for (i = 0; i < lns; ++i)
		scanf("%d", items+i);

	sort(items, 0, lns-1);
	
	for (i = 0; i < lns; ++i){
		printf("%d\n", items[i]);
	}
	return 0;
}

void sort(int array[], int l, int h){
	
	(l==h) ? return;

	int i, pivot = (l+h)/2, lenght =  grp1 = 0, grp2 = 0, *tmp;
	tmp = malloc((l+h)*sizeof(int));
	sort(tmp, l, pivot);
	sort(tmp, pivot+1, h);

	for(i = 0; i < l; ++i)
		*(tmp+i) = *(array+i+1);
	
	grp1 = 0;
	grp2 = pivot -l+1;

	for (i = 0; i < l; i++)
		if (grp1 <= h-l)
			if (grp2 <= pivot-l)
				if (*(tmp+grp1) > *(tmp+grp2))
					*(array+i+l) = *(tmp+(grp2++));
				else *(array+i+l) = *(tmp+(grp1++));
			else *(array+i+l) = *(tmp+(grp2++));
		else *(array+i+l) = *(tmp+(grp1++));
}
	
