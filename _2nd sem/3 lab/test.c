#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin.h"

void s_gets(char *str, int n)
{
    int i = 0;
    fgets(str, n, stdin);
    while(str[i] != '\n' && str[i] != '\0')
        i++;
    if(str[i] == '\n')
        str[i] = '\0' ;
    // else // требуется наличие words[i] == '\0'
    //     while (getchar() != '\n')
    //         continue;
}

void charToBin(char *name)
{
    FILE *f;
    f=fopen(name, "wb");
    char text[255];
    printf("Give string:\n");
    s_gets(text, 255);

    int i = 0;
    while(text[i] != '\0')
    {
        fwrite(&text[i], sizeof(char), 1, f);
        i++;
    }
    fwrite(&text[i], sizeof(char), 1, f);
    fclose(f);
}

void charFromBin(char *name)
{
    FILE *f;
    f = fopen(name, "rb");
    char *text;
    text = (char*)malloc(1);
    fseek(f, 0, SEEK_SET);
    int i = 0;

    while(text[i-1] != '\0') 
    {
        fread(&text[i], sizeof(char), 1, f);
        text = (char*)realloc(text, i+2);
        i++;
    }
    // if(text[i-1]=='\0')
    //     printf("YEEEEES\n");
    printf("%s\n", text);
    free(text);
    fclose(f);
}

int main()
{
    // char name[] = "filik";
    // FILE *f;
    // f = fopen(name, "w+b");
    // fclose(f);
    // charToBin(name);
    // charFromBin(name);
    int a = 0, *p = &a;
    printf("*p = %d\n", *p);
    a = 9;
    printf("*p = %d\n", *p);
    getchar();
    return 0;
}