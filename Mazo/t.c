#include <stdio.h>
#include <string.h>

#define MAXSTRLEN 20
#define MAXWORD 6

int main(void)
{
    char arr[MAXWORD][MAXSTRLEN+1] = {0};
    char str[] ="This is my text example";
    char *pch;
    int i = 0;
    pch = strtok (str," ");
    while (pch != NULL && i < MAXWORD)
    {
        strncpy(arr[i++], pch, MAXSTRLEN);
        pch = strtok (NULL, " ");
    }
    printf("%s\n",arr[0] );
    return 0;
}
