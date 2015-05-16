#include <stdio.h>

int isAlpha (char );

int main (int argc,char *argv[])
{
	FILE *fin, *fout;
	int ch;

	if (argc != 3) 
	{
		fprintf(stderr,"uso: toupper nomefile1 nomefile2\n");
		return 0;
	}
	
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	
	while ((ch = fgetc(fin)) != EOF)
	{
		if (ch == '.')
		{
			do {
			fputc(ch, fout);
			ch = fgetc(fin);
			} while( !isAlpha(ch) && ch != EOF);
			
			if ( ch >= 'a' && ch <= 'z')
			ch += 'A'-'a';
		}
		if (ch != EOF)
		fputc(ch, fout);
	}
	fclose(fin);
	fclose(fout);
}

int isAlpha (char c){
return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}