#include <stdio.h>
#include <string.h>

int main()
{
    char prog[100], key[100], opt[100], sym[100];
    FILE *keyWords = fopen("Keywords.txt", "r");
    FILE *Operators = fopen("Operators.txt", "r");
    FILE *Symbols = fopen("Symbols.txt", "r");
    FILE *Input = fopen("Input.txt", "r");
    while (fscanf(Input, "%s", prog) != EOF)
    {
        rewind(keyWords);
        printf("%s\n", prog);

        while (fscanf(keyWords, "%s", key) != EOF)
        {

            if (strcmp(key, prog) == 0)
            {
                printf("%s\n", prog);
                printf("\n Keyword - %s\n", key);
                // flag = 1;
                break;
            }
            // printf("%s\n", key);
        }
        rewind(Operators);
        while (fscanf(Operators, "%s", opt) != EOF)
        {
            if (strcmp(opt, prog) == 0)
            {
                printf("%s\n", opt);
                printf("\n Operator - %s\n", opt);
                // flag = 1;
                break;
            }
        }
        // rewind(Symbols);
        // while (fscanf(Symbols, "%s", sym) != EOF)
        // {
        //     printf("%s\n", sym);
        // }
    }
}