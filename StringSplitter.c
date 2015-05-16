#include <stdio.h>


int main (int argc,char *argv[])
{
	FILE *fin, *fout;
	int ch;
	
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "wb+");
	
	while (ch = fgetc(fin) != EOF)
	{
		if (ch == '.')
		{
				do{
					fputc(ch, fout);
					ch = fgetc(fin);
					}while( ch < 'a' && ch > 'z' && ch < 'A' && ch > 'Z' && ch != EOF);	
				if (ch >= 'a')
					ch += 'A'-'a';
		}
		fputc(ch, fout);
	}
}