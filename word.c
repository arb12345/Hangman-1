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
char* hint();
void clears();
void sleeps(int);
void checkscore(int,float);
void displayscore();
void difficulty();
void displaynewhigh();

struct g_score
{
	int hscore;
	char name[20];
	float t;
};
typedef struct g_score highscore;

int hint_line=0;

int main()
{
	int n=70,choice=0,q;
	srand(time(0));
	clears();
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t|  |  /\\  |\\  | ---  |\\    /|  /\\  |\\  |\n");
	printf("\t\t\t\t\t\t\t|--| /__\\ | \\ ||  _  | \\  / | /__\\ | \\ |\n");
	printf("\t\t\t\t\t\t\t|  |/    \\|  \\||___| |  \\/  |/    \\|  \\|\n");
	sleeps(1000);	
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tLoading...\n\n\n\n\n\t\t\t\t\t");
	while(n>=0)
	{
	printf("|");
	sleeps(18);
	n--;
    }
    printf(" 100%%\n\n\t");
    sleeps(1000);
    printf("\n");
    clears();
    do
	{ 
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t|  |  /\\  |\\  | ---  |\\    /|  /\\  |\\  |\n");
		printf("\t\t\t\t\t\t\t|--| /__\\ | \\ ||  _  | \\  / | /__\\ | \\ |\n");
		printf("\t\t\t\t\t\t\t|  |/    \\|  \\||___| |  \\/  |/    \\|  \\|\n");
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t1. PLAY\n\n\t\t\t\t\t\t\t\t\t2. SELECT DIFFICULTY\n\n\t\t\t\t\t\t\t\t\t3. HIGH SCORE\n\n\t\t\t\t\t\t\t\t\t4. EXIT\n\n\t\t\t\t"); 
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					play();
				}break;
			case 2:
				{
					difficulty();
				}break;
			case 3:
				{
					displayscore();
				}break;
			case 4:
				{
					clears();
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tAre you sure you want to quit?");
					printf("\n\n\t\t\t\t\t\t\t1.Yes\t\t\t\t\t\t2.No\n\n\t\t\t\t\t\t\t\t\t\t");
					scanf("%d",&q);
					if(q==1)
					{
						clears();
						exit(1);
					}
					clears();
				}break;
		} 
	}
	while(choice!=0);
	return 0;	
}

void play()
{
	int i,chance=7,check=0,n=60,score=0,level=1,l=0,k,diff_level,quit;
	char word[80],guess[80],w,displayguess[80],dis_letter[50],c;
	clock_t time;
	clears();
	time = clock();
	strcpy(word,random_word());					
    FILE *fptr3;
	if ((fptr3 = fopen("difficulty.txt", "r")) == NULL)				//if file does not exist
    {
        printf("Error! opening file");
        diff_level=2;         
    } 
    while (c != EOF) 
    { 
        fscanf(fptr3,"%d",&diff_level);
        c = fgetc(fptr3);
    }
    fclose(fptr3);
	for(i=0;i<=strlen(word)-1;i++)
	{
		if(i%(diff_level+1)==0)
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
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tGuess the word: %s\n\n",displayguess);
		printf("\t\t\t\t\t\t\t\t\tLevel %d\n\n",level);
		printf("\n\tChances:%d\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tScore:%d\n",chance,score);
		printf("\n");
		printf("\n\t\t\t\t\t\t\t\tHint: %s\n\n",hint());
		printf("\tGuessed Letters: ");
		for(k=0;k<=l-1;k++)
		printf("%c ",dis_letter[k]);							//display used letters
		printf("\n\n\n");
		hangman(chance);
		//printf("\n\n\n\t\t\t\t\t\t\t\t\t%s\n",guess);
		printf("\n\n\n\t\t\t\t\t\t\t\t\t");
		for(i=0;i<=strlen(guess)-1;i++)
		{
			printf(" %c",guess[i]);
		}
		printf("\n");
		check=0;
		printf("\n\n\n\n\t\t\t\t\t\t\t\tEnter a letter:");
		scanf(" %c",&w);										//accept character from user
		if(w=='*')													
		{
			clears();
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t|  |  /\\  |\\  | ---  |\\    /|  /\\  |\\  |\n");
			printf("\t\t\t\t\t\t\t|--| /__\\ | \\ ||  _  | \\  / | /__\\ | \\ |\n");
			printf("\t\t\t\t\t\t\t|  |/    \\|  \\||___| |  \\/  |/    \\|  \\|\n");
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tAre you sure you want to quit?");
			printf("\n\n\t\t\t\t\t\t\t1.Yes\t\t\t\t\t\t2.No");
			scanf("%d",&quit);
			if(quit==1)
			{
				clears();
				return;
			}
		}
		w=toupper(w);										//convert character to upper case
		dis_letter[l]=w;
		l++;
		for(i=0;i<=strlen(word)-1;i++)
		{
			if(word[i]==w)
			{
				guess[i]=w;										//check if character is present in word
			    check=1;
			if (strcmp(word,guess) == 0)
			{
				printf("\n\n\tNext Level\n");
				score=score+5;									// increase the score by 5 and go to next level
				level++;
				l=0;
				if(chance!=0)
				{
					strcpy(word,random_word());					
			
					for(i=0;i<=strlen(word)-1;i++)
					{
						if(i%(diff_level+1)==0)
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
	  			
				}		
			}
			}
		}
		if(check==0)
		{
			chance=chance-1;							//decrease chance by if charcter is not present in word
			score--;									////decrease score by if charcter is not present in word
			if(score<0)
			score=0;
			if(chance==0)				
			{
				clears();
				printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tGame over!!\n");
				printf("\n\t\t\t\t\t\t\t\t\tYour Score:%d\n\n\n\n\n",score);
				time=clock()-time;
				float time_taken = ((float)time)/CLOCKS_PER_SEC;		//calculate time
				checkscore(score,time_taken);
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

void hangman(int c)					//Display hangman
{
	switch(c)
	{
	 case 6:
	 {	
		printf("\t\t\t\t\t\t\t\t\t|---O   \n");
		printf("\t\t\t\t\t\t\t\t\t|      \n");
		printf("\t\t\t\t\t\t\t\t\t|       \n");
		printf("\t\t\t\t\t\t\t\t\t|       \n");
		printf("\t\t\t\t\t\t\t\t\t|       \n");
		break;
	 }
	 case 5:
	 {
		printf("\t\t\t\t\t\t\t\t\t|---O  \n");
		printf("\t\t\t\t\t\t\t\t\t|  /    \n");
		printf("\t\t\t\t\t\t\t\t\t|       \n");
		printf("\t\t\t\t\t\t\t\t\t|      \n");
		printf("\t\t\t\t\t\t\t\t\t|       \n");
		break;
	 }
	 case 4:
	 {
		printf("\t\t\t\t\t\t\t\t\t|---O   \n");
		printf("\t\t\t\t\t\t\t\t\t|  /|    \n");
		printf("\t\t\t\t\t\t\t\t\t|        \n");
		printf("\t\t\t\t\t\t\t\t\t|     \n");
		printf("\t\t\t\t\t\t\t\t\t|       \n");
		break;
		
	 }
	 case 3:
	 {
		printf("\t\t\t\t\t\t\t\t\t|---O   \n");
		printf("\t\t\t\t\t\t\t\t\t|  /|\\    \n");
		printf("\t\t\t\t\t\t\t\t\t|        \n");
		printf("\t\t\t\t\t\t\t\t\t|      \n");
		printf("\t\t\t\t\t\t\t\t\t|       \n");
		break;
	}
	case 2:
	{
		printf("\t\t\t\t\t\t\t\t\t|---O   \n");
		printf("\t\t\t\t\t\t\t\t\t|  /|\\    \n");
		printf("\t\t\t\t\t\t\t\t\t|   |    \n");
		printf("\t\t\t\t\t\t\t\t\t|      \n");
		printf("\t\t\t\t\t\t\t\t\t|       \n");
		break;
	}
	case 1:
	{
		printf("\t\t\t\t\t\t\t\t\t|---O   \n");
		printf("\t\t\t\t\t\t\t\t\t|  /|\\    \n");
		printf("\t\t\t\t\t\t\t\t\t|   |    \n");
		printf("\t\t\t\t\t\t\t\t\t|  /    \n");
		printf("\t\t\t\t\t\t\t\t\t|       \n");
		break;
	}
	case 0:
	{
		printf("\t\t\t\t\t\t\t\t\t|---O   \n");
		printf("\t\t\t\t\t\t\t\t\t|  /|\\    \n");
		printf("\t\t\t\t\t\t\t\t\t|   |    \n");
		printf("\t\t\t\t\t\t\t\t\t|  / \\   \n");
		printf("\t\t\t\t\t\t\t\t\t|       \n");
		break;
	}		
}
}

char* random_word()								//function to read random word from file
{
	int j=0,random_num=0;
	char buffer[50],buffer1[50];
	random_num = (rand() %49+0);
	FILE *fptr;
	hint_line=0;
	if ((fptr = fopen("hangmanword.txt", "r")) == NULL)
    {
        printf("Error! opening file");						//error if file does not exists
        exit(1);         
    } 
    while (fgets(buffer, sizeof(buffer), fptr)) 
    {
		if(j==random_num)
		{
			strcpy(buffer1, buffer);
			hint_line=j;
			break;			
		}
		j++;			
    } 
	char *word=buffer1;
    fclose(fptr);
    return word;	
}

char* hint()								//function to display hint
{
	int j=0;
	char hint[50],hint1[50];
	FILE *fptr1;
	if ((fptr1 = fopen("hints.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    } 
    while (fgets(hint, sizeof(hint), fptr1)) 
    {
		if(j==hint_line)
		{
			strcpy(hint1, hint);
			break;			
		}
		j++;			
    }
   // printf("%s",hint1);
    char *hintword=hint1;
    fclose(fptr1);
    return hintword;
}

void checkscore(int score,float time_taken)
{
	highscore hs[11],temp;
	int i=0,j,n=0;
	char name[100],c;
	FILE *fptr;
	fptr = fopen("score.txt", "a+");
	if(fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	printf("\tEnter your name:");						//accept user name
	scanf("%s",name);
	fprintf(fptr,"\t\t\t%s\t\t%d\t\t%f\n", name,score,time_taken);
	fclose(fptr);
	
	fptr = fopen("score.txt", "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 					//error if file does not exists
        exit(0); 
    }
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        fscanf(fptr,"\t\t\t\t\t\t%s\t\t%d\t\t%f",hs[i].name,&hs[i].hscore,&hs[i].t);
        c = fgetc(fptr);
        i++;
        n++; 
    }
    n--;  
    for(i=0;i<n-1;i++)      								//display score in ascending order
	{ 
		for(j=0;j<n-1-i;j++) 
		{
			if(hs[j].hscore< hs[j+1].hscore)
			{
				temp=hs[j];       
				hs[j]=hs[j+1];
				hs[j+1]=temp;
			}
		} 
	}
	//printf("%d",hs[0].hscore);
	if(score==hs[0].hscore)
	{
		printf("\n\n\n\t\t\t\t\t\t\t\t\tNEW HIGH SCORE");
		clears();
		displaynewhigh();
		clears();
	}
	fclose(fptr);
}

void displayscore()								//function to display score
{
	highscore hs[11],temp;
	int a,i=0,n=0,j,reset=0;
	clears();
	FILE *fptr; 
    char c; 
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t|  |  /\\  |\\  | ---  |\\    /|  /\\  |\\  |\n");
	printf("\t\t\t\t\t\t\t|--| /__\\ | \\ ||  _  | \\  / | /__\\ | \\ |\n");
	printf("\t\t\t\t\t\t\t|  |/    \\|  \\||___| |  \\/  |/    \\|  \\|\n");
    fptr = fopen("score.txt", "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 					//error if file does not exists
        exit(0); 
    }
    printf("\n\n\t\t\t\t\t\t\tName\t\tScore\t\tTime\n"); 
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        fscanf(fptr,"\t\t\t\t\t\t%s\t\t%d\t\t%f",hs[i].name,&hs[i].hscore,&hs[i].t);
        c = fgetc(fptr);
        i++;
        n++; 
    }
    n--;  
    for(i=0;i<n-1;i++)      								//display score in ascending order
	{ 
		for(j=0;j<n-1-i;j++) 
		{
			if(hs[j].hscore< hs[j+1].hscore)
			{
				temp=hs[j];       
				hs[j]=hs[j+1];
				hs[j+1]=temp;
			}
		} 
	}  
    for(i=0;i<=n-1;i++)  
    printf("\t\t\t\t\t\t\t%s\t\t%d\t\t%0.2f\n",hs[i].name,hs[i].hscore,hs[i].t/60); 		//display score
    printf("\n\n\n\t1. Main menu\t\t\t\t\t\t\t\t\t\t\t\t\t\t2.Reset Score\n\t");
    scanf("%d",&a);
	fclose(fptr);
    if(a==2)
    {
		clears();
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tAre you sure you want to reset score?");
		printf("\n\n\t\t\t\t\t\t\t1.Yes\t\t\t\t\t\t2.No");
		scanf("%d",&reset);
        if(reset==1)
		{
			fopen("score.txt","w");	
			fclose(fptr);
			displayscore();
		}
	}
    clears();   
}

void difficulty()						//function to select difficulty level
{
	int n;
	char c;
	clears();
	FILE *fptr;
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t|  |  /\\  |\\  | ---  |\\    /|  /\\  |\\  |\n");
	printf("\t\t\t\t\t\t\t|--| /__\\ | \\ ||  _  | \\  / | /__\\ | \\ |\n");
	printf("\t\t\t\t\t\t\t|  |/    \\|  \\||___| |  \\/  |/    \\|  \\|\n");
	
	if ((fptr = fopen("difficulty.txt", "r")) == NULL)
    {
        n=2;         
    } 
    while (c != EOF) 
    { 
        fscanf(fptr,"%d",&n);
        c = fgetc(fptr);
    }
    fclose(fptr);
	if(n==1)
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t1. EASY <-\n\n\t\t\t\t\t\t\t\t\t2. MEDIUM\n\n\t\t\t\t\t\t\t\t\t3. HARD\n\n\t\t\t\t");
	else
	if(n==2)
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t1. EASY\n\n\t\t\t\t\t\t\t\t\t2. MEDIUM <-\n\n\t\t\t\t\t\t\t\t\t3. HARD\n\n\t\t\t\t");
	else
	if(n==3)
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t1. EASY\n\n\t\t\t\t\t\t\t\t\t2. MEDIUM\n\n\t\t\t\t\t\t\t\t\t3. HARD <-\n\n\t\t\t\t");
	printf("4.Main menu\n\n\t");
	scanf("%d",&n);
	if(n!=4&&n<4)
	{
	fptr = fopen("difficulty.txt", "w");
	if(fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	fprintf(fptr,"%d",n);
	fclose(fptr);
	difficulty();
	}
	clears();	
}

void displaynewhigh()
{
	int n=20;
	clears();
	while(n>=0)
	{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
	printf("\t\t\t\t\t\t\t  |  |    ___        ---  ____  ___   ___   ___  \n");
	printf("\t\t\t\t\t\t\t  |--| | |  _ |__|  |___ |     |   | |___| |___   \n");
	printf("\t\t\t\t\t\t\t  |  | | |___||  |   ___||___  |___| |\\    |___\n");
	printf("\n\t\t\t\t\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
	sleeps(120);
	clears();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
	printf("\t\t\t\t\t\t\t  |  |    ___        ---  ____  ___   ___   ___  \n");
	printf("\t\t\t\t\t\t\t  |--| | |  _ |__|  |___ |     |   | |___| |___ \n");
	printf("\t\t\t\t\t\t\t  |  | | |___||  |   ___||___  |___| |\\    |___  \n");
	printf("\n\t\t\t\t\t\t-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	sleeps(120);
	clears();
	n--;
}
}

void clears()				//clear screen
{
	#ifdef _WIN32			//for windows
	system("cls");
	#elif __linux__			//for linux
	system("clear");
	#endif
}

void sleeps(int x)
{
	#ifdef _WIN32			//for windows
	Sleep(x);
	#elif __linux__			//for linux
	sleep(x*0.001);
	#endif
}

