%{
    int identifier = 0;
    int j = 0;
    int key =0 ;
    int l = 0;
    int op = 0;
    int num = 0;
%}
number [0-9]+ 
id [a-zA-Z]+_*[0-9]* 
oprators [+/><*?!=]
%%

"\n" {printf("Identifier %d\nKeyeords %d\nNumber %d\nOprators %d\n", identifier,key,num,op); identifier = 0; key=0; op=0;

    return (0);
}
{number} {num++;}
{oprators} {op++;}
{id} { identifier++;}

%%




int main() {
    yylex();
    return (0);
}


