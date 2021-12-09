#include <stdio.h>
#include <string.h>
int isAlphabet(char x);
int isNumber(int x);
int isAnIdentifier(char str[]);
int isAnKeyWords(char str[]);
int haveKeyWord(char str[]);
int isSymbol(char str[]);
int isOperator(char str[]);
void main()
{

    FILE *InputProgramFile = fopen("Input.txt", "r");
    char programTemp[100];
    while (fscanf(InputProgramFile, "%s", programTemp) != EOF)
    {
        if (isAnKeyWords(programTemp) == 1)
        {
            printf("%s is a keyword\n", programTemp);
        }
        else
        {
            if (!haveKeyWord(programTemp))
            {
                if (isAnIdentifier(programTemp))
                {
                    printf("%s is an identifier\n", programTemp);
                }
                else if (isOperator(programTemp))
                {
                    printf("%s is a Operator\n", programTemp);
                }
                else if (isSymbol(programTemp))
                {
                    printf("%s is a symbol\n", programTemp);
                }
            }
        }
    }
}

int isAlphabet(char x)
{
    int i = 0;
    char c_low = 'a', c_up = 'A';
    int isLetter = 0;
    for (i = 0; i < 26; i++)
    {
        if (x == c_low + i)
        {
            isLetter = 1;
        }
    }
    for (i = 0; i < 26; i++)
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
    int flag = 0;
    if (isAlphabet(str[0]) == 1)
    {
        flag = 1;
    }
    for (int i = 0; i < strlen(str); i++)
    {

        if (isAlphabet(str[i]) || isNumber(str[i]) || str[i] == '_')
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int isAnKeyWords(char str[])
{
    FILE *KeywordsFile = fopen("Keywords.txt", "r");
    char keywordsTemp[100];
    int flag = 0;
    while (fscanf(KeywordsFile, "%s", keywordsTemp) != EOF)
    {
        if (strcmp(str, keywordsTemp) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
int haveKeyWord(char str[])
{
    FILE *O_Keyword = fopen("O_Keyword.txt", "w");
    int haveOpeningBracket = 0, openingBracketIndex;
    char temp[100];
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(')
        {
            haveOpeningBracket = 1;
            openingBracketIndex = i;
        }
    }
    if (haveOpeningBracket == 1)
    {
        for (int i = 0; i < openingBracketIndex; i++)
        {
            temp[i] = str[i];
        }
        temp[openingBracketIndex] = '\0';
        if (isAnKeyWords(temp))
        {
            printf("%s is a keyword\n", temp);
            return 1;
        }
    }
    else
    {
        return 0;
    }
}
int isSymbol(char str[])
{
    FILE *Symbols = fopen("Symbols.txt", "r");
    char symbol[100];
    int flag = 0;
    while (fscanf(Symbols, "%s", symbol) != EOF)
    {
        if (strcmp(str, symbol) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
int isOperator(char str[])
{
    int flag = 1;
    char Operator[100];
    FILE *Operators = fopen("Operators.txt", "r");
    while (fscanf(Operators, "%s", Operator) != EOF)
    {

        if (strcmp(str, Operator) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
