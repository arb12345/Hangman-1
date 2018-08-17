#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int main()
{
	void hangman(int);
	int i,chance=7,check=0,n=60;
	char word[20]="university",guess[20],w,displayguess[20];
	printf("\n\n\n\t\t|  |  /\\  |\\  | ---  |\\    /|  /\\  |\\  |\n");
	printf("\t\t|--| /__\\ | \\ ||  _  | \\  / | /__\\ | \\ |\n");
	printf("\t\t|  |/    \\|  \\||___| |  \\/  |/    \\|  \\| \n");
	Sleep(1000);
	
	printf("\n\n\n\n\n\n\n\t\t\t\tLoading...\n\n\t");
	while(n>=0)
	{
	printf("|");
	Sleep(20);
	n--;
    }
    printf(" 100%%\n\n\t");
    Sleep(1000);
    printf("\n");
    system("cls");
	for(i=0;i<=strlen(word);i++)
	{
		if(i%2==0)
		{
			guess[i]=word[i];
			displayguess[i]=word[i];
		}
		else
		{
			guess[i]='_';
			displayguess[i]='_';
		}
	}
	while(n)
	{
		printf("\n\n\n\t\t\tGuess the word: %s\n",displayguess);
		printf("Chances:%d\n",chance);
		printf("\n");
		hangman(chance);
		printf("\n%s\n\n\t\t\t",guess);
		check=0;
		printf("\nEnter a letter:");
		scanf(" %c",&w);
		for(i=0;i<=strlen(word)-1;i++)
		{
			if(word[i]==w)
			{
				guess[i]=w;
			    check=1;
			if (strcmp(word,guess) == 0)
			{
				printf("\nyou won\n");
				n=1;
				break;			
			}
			}
		}
		if(check==0)
		{
			chance=chance-1;
			printf("\nWRONG\n");
			if(chance==0)				{
				printf("\nLast chance! Game over!!\n\n\n");
				n=1;
				break;
			}
		}
	n--;
	Sleep(900);
	system("cls");
    }
	return 0;
	
}

void hangman(int c)
{
	switch(c)
	{
	 case 6:
	 {	
		printf("\t\t\t\t|---O   \n");
		printf("\t\t\t\t|      \n");
		printf("\t\t\t\t|       \n");
		printf("\t\t\t\t|       \n");
		printf("\t\t\t\t|       \n");
		break;
	 }
	 case 5:
	 {
		printf("\t\t\t\t|---O  \n");
		printf("\t\t\t\t|  /    \n");
		printf("\t\t\t\t|       \n");
		printf("\t\t\t\t|      \n");
		printf("\t\t\t\t|       \n");
		break;
	 }
	 case 4:
	 {
		printf("\t\t\t\t|---O   \n");
		printf("\t\t\t\t|  /|    \n");
		printf("\t\t\t\t|        \n");
		printf("\t\t\t\t|     \n");
		printf("\t\t\t\t|       \n");
		break;
		
	 }
	 case 3:
	 {
		printf("\t\t\t\t|---O   \n");
		printf("\t\t\t\t|  /|\\    \n");
		printf("\t\t\t\t|        \n");
		printf("\t\t\t\t|      \n");
		printf("\t\t\t\t|       \n");
		break;
	}
	case 2:
	{
		printf("\t\t\t\t|---O   \n");
		printf("\t\t\t\t|  /|\\    \n");
		printf("\t\t\t\t|   |    \n");
		printf("\t\t\t\t|      \n");
		printf("\t\t\t\t|       \n");
		break;
	}
	case 1:
	{
		printf("\t\t\t\t|---O   \n");
		printf("\t\t\t\t|  /|\\    \n");
		printf("\t\t\t\t|   |    \n");
		printf("\t\t\t\t|  /    \n");
		printf("\t\t\t\t|       \n");
		break;
	}
	case 0:
	{
		printf("\t\t\t\t|---O   \n");
		printf("\t\t\t\t|  /|\\    \n");
		printf("\t\t\t\t|   |    \n");
		printf("\t\t\t\t|  / \\   \n");
		printf("\t\t\t\t|       \n");
		break;
	}
    
		
}
}
