#include <stdio.h>
#include <string.h>
int dfa = 0;
void q0(char c)
{
    if (c == 'a')
    {
        dfa = 1;
    }
    else if (c == 'b')
    {
        dfa = 3;
    }
    else
    {
        dfa = -1;
    }
}
void q1(char c)
{
    if (c == 'a')
    {
        dfa = 2;
    }
    else if (c == 'b')
    {
        dfa = 4;
    }
    else
    {
        dfa = -1;
    }
}
void q2(char c)
{
    if (c == 'b')
    {
        dfa = 3;
    }
    else if (c == 'a')
    {
        dfa = 1;
    }
    else
    {
        dfa = -1;
    }
}
void q3(char c)
{
    if (c == 'b')
    {
        dfa = 3;
    }
    else if (c == 'a')
    {
        dfa = 4;
    }
    else
    {
        dfa = -1;
    }
}
void q4(char c)
{
    dfa = -1;
}

int isAccepted(char str[])
{
    int i, len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (dfa == 0)
            q0(str[i]);
        else if (dfa == 1)
            q1(str[i]);
        else if (dfa == 2)
            q2(str[i]);
        else if (dfa == 3)
            q3(str[i]);
        else if (dfa == 4)
            q4(str[i]);
        else
            return 0;
    }
    if (dfa == 3)
        return 1;
    else
        return 0;
}
int main()
{
    char str[100];
    printf("Enter The Input String:");
    gets(str);
    if (isAccepted(str))
        printf("String ACCEPTED");
    else
        printf("String NOT ACCEPTED");
    return 0;
}
