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
int main()
{
    char prog[100], key[100], opt[100], sym[100], temp[100];
    FILE *keyWords = fopen("Keywords.txt", "r");
    FILE *Operators = fopen("Operators.txt", "r");
    FILE *Symbols = fopen("Symbols.txt", "r");
    FILE *Input = fopen("Input.txt", "r");
    int flag, i;
    while (fscanf(Input, "%s", prog) != EOF)
    {
        rewind(keyWords);
        flag = 0;
        while (fscanf(keyWords, "%s", key) != EOF)
        {

            if (strcmp(key, prog) == 0)
            {
                printf("%s\n", prog);
                printf("\n Keyword - %s\n", key);
                flag = 1;
                break;
            }
        }
        rewind(Operators);
        while (fscanf(Operators, "%s", opt) != EOF)
        {
            if (strcmp(opt, prog) == 0)
            {
                printf("%s\n", opt);
                printf("\n Operator - %s\n", opt);
                break;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            i = 0;

            while (strlen(prog) != i)
            {
                temp[i] = prog[i];
                rewind(keyWords);
                while (fscanf(keyWords, "%s", key) != EOF)
                {
                    if (strcmp(temp, key) == 0)
                    {
                        printf("\n Keyword - %s\n", temp);
                        flag = 1;
                        break;
                    }
                }
                i++;
            }
        }
        if (flag != 1)
        {
            if (isAnIdentifier(prog))
            {
                printf("Identifier : %s\n", prog);
            }
        }
    }
}