#include <stdio.h>
#include <string.h>
int isAlphabet(char x)
{
    int i = 0;
    char c_low = 'a', c_up = 'A';
    int isLetter = 0;
    for (i = 0; i <= 26; i++)
    {
        if (x == c_low + i)
        {
            isLetter = 1;
        }
    }
    for (i = 0; i <= 26; i++)
    {
        if (x == c_up + i)
        {
            isLetter = 1;
        }
    }
    if (isLetter == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int isNumber(int x)
{
    if (x >= '0' && x <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isAnIdentifier(char str[])
{
    int i = 0, flag = 0;
    if (isAlphabet(str[0]))
    {
        for (i = 1; i <= strlen(str); i++)
        {
            if (isAlphabet(str[i]) || isNumber(str[i] || str[i] == '_'))
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}
int isKeyWord(char x[]){
        FILE *keyWords = fopen("Keywords.txt", "r");
        char key[100] , temp[100];
	int i,j;
        printf("%s\n",x);	
	while (fscanf(keyWords, "%s", key) != EOF)
        {
	    i=0	;
	    printf("KeyWord in lIST %s\n",key);	
	 
	if(strcmp(key,x) == 0){
		printf("Key Word\t:\t%s\n",key);
		return 1;
		break;	
	}
	keyWordCheck(key,x);
	
}

int keyWordCheck(char key[], char str[]){
printf("\t%s \t : \t %s",key, str);
}



void main(){
    char prog[100], key[100], opt[100], sym[100], temp[100];
    FILE *Operators = fopen("Operators.txt", "r");
    FILE *Symbols = fopen("Symbols.txt", "r");
    FILE *Input = fopen("Input.txt", "r");
    int flag, i;
    while (fscanf(Input, "%s", prog) != EOF)
    {
	printf("\n\n\n%d\n\n",isKeyWord(prog));  
    }
}


