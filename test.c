#include<stdio.h>
#include<string.h>
int main()
{
	char* test(char[]);
	char s[8]="abcdejk\0",s1[10],s2[10];
	strcpy(s1,test(s));
	//strcpy(s2,s1);
	printf("%s %d\n",s1,strlen(s1));
	//printf("%s\n%s\n\n",s1,s2);
	return 0;
}
char* test(char word[])
{		
	int i;
	char guess[20];
	printf("%s %d\n",word,strlen(word));
				for(i=0;i<=strlen(word)-1;i++)
					{
						if(i%3==0)
						{
							guess[i]=word[i];
						}
						else
						if(i<strlen(word)-2)
						{
							guess[i]='_';
						}
						else
						{
							guess[i]=word[i];
						}
					}
				guess[i]='\0';
				printf("%s %d\n",guess,strlen(guess));
				char *word1=guess;
				return word1;
}
