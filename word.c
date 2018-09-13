#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

#ifdef _WIN32
#include<windows.h>
#elif __linux__
#include<unistd.h>
#endif

void hangman(int);
void play();
char* random_word();
void clears();
void sleeps(int);
void checkscore(int);

int main()
{
	int n=60,choice=0;
	srand(time(0));
	clears();
	printf("\n\n\n\t\t|  |  /\\  |\\  | ---  |\\    /|  /\\  |\\  |\n");
	printf("\t\t|--| /__\\ | \\ ||  _  | \\  / | /__\\ | \\ |\n");
	printf("\t\t|  |/    \\|  \\||___| |  \\/  |/    \\|  \\| \n");
	sleeps(1000);	
	printf("\n\n\n\n\n\n\n\t\t\t\tLoading...\n\n\t");
	while(n>=0)
	{
	printf("|");
	sleeps(20);
	n--;
    }
    printf(" 100%%\n\n\t");
    sleeps(1000);
    printf("\n");
    clears();
    do
	{ 
		printf("\n\n\n\t\t|  |  /\\  |\\  | ---  |\\    /|  /\\  |\\  |\n");
		printf("\t\t|--| /__\\ | \\ ||  _  | \\  / | /__\\ | \\ |\n");
		printf("\t\t|  |/    \\|  \\||___| |  \\/  |/    \\|  \\| \n"); 
		printf("\n\n\n\n\n\n\t\t\t\t1. PLAY\n\n\t\t\t\t2. HIGH SCORE\n\n\t\t\t\t3. EXIT\n\n\t\t\t\t"); 
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					play();
				}break;
			case 2:
				{
					printf("HIGH SCORE");
				}break;
			case 3:
				{
					clears();
					exit(1);
				}break;
		} 
	}
	while(choice!=3);
	return 0;	
}

void play()
{
	int i,chance=7,check=0,n=60,score=0,level=1;
	char word[80],guess[80],w,displayguess[80];
	clears();
	strcpy(word,random_word());
    //strupr(word);
	for(i=0;i<=strlen(word)-1;i++)
	{
		if(i%3==0)
		{
			guess[i]=word[i];
			displayguess[i]=word[i];
		}
		else
		if(i<strlen(word)-2)
		{
			guess[i]='_';
			displayguess[i]='_';
		}
		else
		{
			guess[i]=word[i];
			displayguess[i]=word[i];
		}
		
	}
	guess[i]='\0';
	displayguess[i]='\0';
	while(n)
	{
		printf("\n\n\n\t\t\tGuess the word: %s\n\n",displayguess);
		printf("\t\t\t\tLevel %d\n\n",level);
		printf("Chances:%d\t\t\t\t\t\t\tScore:%d\n",chance,score);
		printf("\n");
		hangman(chance);
		printf("\n\n\t\t\t\t%s\n",guess);
		check=0;
		printf("\nEnter a letter:");
		scanf(" %c",&w);
		w=toupper(w);
		for(i=0;i<=strlen(word)-1;i++)
		{
			if(word[i]==w)
			{
				guess[i]=w;
			    check=1;
			if (strcmp(word,guess) == 0)
			{
				printf("\nNext Level\n");
				score=score+5;
				level++;
				//n=1;
				//break;
				if(chance!=0)
				{
					strcpy(word,random_word());					
			/////////////////////////////////////
					for(i=0;i<=strlen(word)-1;i++)
					{
						if(i%3==0)
						{
							guess[i]=word[i];
							displayguess[i]=word[i];
						}
						else
						if(i<strlen(word)-2)
						{
							guess[i]='_';
							displayguess[i]='_';
						}
						else
						{
							guess[i]=word[i];
							displayguess[i]=word[i];
						}
					}
				guess[i]='\0';
				displayguess[i]='\0';
	       ///////////////////////////////				
				}		
			}
			}
		}
		if(check==0)
		{
			chance=chance-1;
			printf("\nWRONG\n");
			score--;
			if(chance==0)				
			{
				clears();
				printf("\n\n\n\n\n\t\t\tLast chance! Game over!!\n");
				printf("\n\t\t\t\tYour Score:%d\n\n\n\n\n",score);
				checkscore(score);
				sleeps(2000);
				clears();
				n=1;
				break;
			}
		}
	n--;
	sleeps(900);
	clears();
    }
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

char* random_word()
{
	int j=0,random_num=0;
	char buffer[50],buffer1[50];
	random_num = (rand() %11+0);
	FILE *fptr;
	if ((fptr = fopen("hangmanword.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }  
    while (fgets(buffer, sizeof(buffer), fptr)) 
    {
		if(j==random_num)
		{
			strcpy(buffer1, buffer);
			
		}
		j++;
			
    }
char *word=buffer1;
    fclose(fptr);
    return word;
	
}
void checkscore(int score)
{
	char name[100];
	FILE *fptr;
	fptr = fopen("score.txt", "a+");
	if(fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	printf("Enter your name:\n");
	scanf("%s",name);
	fprintf(fptr,"%s %d\n", name,score);
	fclose(fptr);
}

void clears()
{
	#ifdef _WIN32
	system("cls");
	#elif __linux__
	system("clear");
	#endif
}

void sleeps(int x)
{
	#ifdef _WIN32
	Sleep(x);
	#elif __linux__
	sleep(x*0.001);
	#endif
}

