#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
 int main(void)
{
    DIR *d;
    struct dirent *dir;
    char Name[100];
    char* j="/home/joaquin.concha/Escritorio/GIT/SO/Jugador 1/";
    d = opendir("/home/joaquin.concha/Escritorio/GIT/SO/Jugador 1/");
   if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) {
                printf("%s\n", dir->d_name);
                if (remove("0 Verde_2.txt") == 0)  printf("Deleted successfully");
                else printf("Unable to delete the file");
          }
        }
        closedir(d);
    }

    return(0);
}
