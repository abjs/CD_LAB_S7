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
    if(isAlphabet(str[0])){
        for (i=1 ; i<=strlen(str) ; i++){
            if(isAlphabet(str[i]) || isNumber(str[i] || str[i] =='_')){
                return 1;
            }
        }
    }
    else{
        return 0;
    }

}
void main()
{

    char test[20] = "N8ame";
    // isAnIdentifier(test);
    // printf("%d", isAlphabet('A'));
    // printf("%d\n", isAlphabet('2'));
    // printf("%d", isNumber(test[1]));
    // printf("%d", isNumber('A'));
    printf("%d", isAnIdentifier("BI_"));
}