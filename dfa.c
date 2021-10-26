#include <stdio.h>
#include <string.h>
int NextState = 0;
void q0(char c)
{
    if (c == 'a')
    {
        NextState = 1;
    }
    else if (c == 'b')
    {
        NextState = 3;
    }
    else
    {
        NextState = -1;
    }
}
void q1(char c)
{
    if (c == 'a')
    {
        NextState = 2;
    }
    else if (c == 'b')
    {
        NextState = 4;
    }
    else
    {
        NextState = -1;
    }
}
void q2(char c)
{
    if (c == 'b')
    {
        NextState = 3;
    }
    else if (c == 'a')
    {
        NextState = 1;
    }
    else
    {
        NextState = -1;
    }
}
void q3(char c)
{
    if (c == 'b')
    {
        NextState = 3;
    }
    else if (c == 'a')
    {
        NextState = 4;
    }
    else
    {
        NextState = -1;
    }
}
void q4(char c)
{
    NextState = -1;
}

int isAccepted(char str[])
{
    int i, len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (NextState == 0)
            q0(str[i]);
        else if (NextState == 1)
            q1(str[i]);
        else if (NextState == 2)
            q2(str[i]);
        else if (NextState == 3)
            q3(str[i]);
        else if (NextState == 4)
            q4(str[i]);
        else
            return 0;
    }
    if (NextState == 3)
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
