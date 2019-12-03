#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int is_whitespace(char c)
{
	if (c == ' ' || 
		c == '\n' ||
		c == '\r' ||
		c == '\t' ||
		c == '(' 	
		)
	{
		return 1;
	}
	return 0;
}

int fget_word(FILE *fp, char *word)
{
	char c;
	int cnt;
	
	while( (c=fgetc(fp)) != EOF )
	{
		if(is_whitespace(c) == 0)
		{
			break;
		}
	}
	
	if( c == EOF )
	{
		return 0; // it means fail
	}
	
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	while( (word[cnt] = fgetc(fp)) != EOF )
	{
		if(is_whitespace(word[cnt]) == 1)
		{
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}	
	
	return cnt;
	
}

int main(void) {
	
	FILE *fp;
	char filepath[100];
	char word[100];
	
	//file open
	printf("Input the file path: ");
	scanf("%s", filepath); // filepath is pointer
	fp = fopen(filepath, "r"); // pointer
	
	if(fp == NULL)
	{
		printf("file path is wrong! %s\n", filepath);
		return -1;
	}
	

	//word reading & analysis
	while(fget_word(fp, word) != 0) // just for checking
	{
		count_word(word);
	}
	
	print_word();
	// output
	fclose(fp);

	return 0;
}
