#include<stdio.h>

int Identifiers(char input[]){
	char c;
	char CapitalLetters[1][26] , SmallLetters[1][26];
	count = 0 ;
    f	for (c = 'A'; c <= 'Z'; ++c){
		CapitalLetters[count]=c;
		count++;
	}
  f	for (c = 'a'; c <= 'b'; ++c){
		SmallLetters[count]=c;
		count++;
	}
	
        printf("%c ", c);
	printf("%s",input);
}
int Keywords(char input[]){
	printf("%s",input);
}

int Operators(char input[]){
	printf("%s",input);
}

int Symbols(char input[1]){
	printf("%s",input);
}


void main() {
/*
   FILE *fp;
   fp = fopen("./test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);

   FILE *fp;
   char buff[255];

   fp = fopen("/tmp/test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
   
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);

	FILE *keyWords;
	char keys[200];
	keyWords = fopen("key.txt", "r");
	while(1){
		fscanf(keyWords, "%s", keys);
		if(keys=="--END--"){
			break;
		}
		printf("%s\n",keys);

	}

	fclose(keyWords);
*/


Identifiers("Hello");




}
