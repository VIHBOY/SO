#include <stdio.h>
#include <string.h>


int main ( int argc, char **argv )
{
 	FILE *fp;
  FILE *fp2;
 	char buffer[100];
 	fp = fopen ("Cartas.txt","r");
  while (fgets(buffer, 100, fp) != NULL){
    strtok(buffer, "\n");
    fp2= fopen(buffer,"w");
    fclose(fp2);
  }
 	  fclose (fp);
 	return 0;
}
