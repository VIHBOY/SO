#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>    // time()
void repartir(char* carta, int jugador) {
  char ruta1[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 1/";
  char ruta2[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 2/";
  char origen[]= "/home/sida/Desktop/GIT/SO2/SO/Mazo/";
  if (jugador==1) {
    int n=rename(strcat(origen,carta),strcat(ruta1,carta));
    if(!n)
    {
        printf("%s", "File name changed successfully");
    }
    else
    {
        perror("Error");
    }
  }
}
int main ( int argc, char **argv )
{
 	FILE *fp;
  FILE *fp2;
  time_t t;
 	char buffer[100];
  char ruta1[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 1/";
  char ruta2[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 2/";
 	fp = fopen ("Cartas.txt","r");
  printf("%s\n",ruta1 );
  srand((unsigned) time(&t));
  printf("%d\n", rand() % (9 + 1 - 0) + 0);
  repartir("9 Rojo.txt",1);
  rename("a.txt","/home/sida/Desktop/GIT/SO2/SO/Jugador 1/a2.txt");
  /*while (fgets(buffer, 100, fp) != NULL){
    strtok(buffer, "\n");
    fp2= fopen(buffer,"r");
    fclose(fp2);
  }*/
  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d){
    while ((dir = readdir(d)) != NULL){
      printf("%s\n", dir->d_name);}
    closedir(d);}
 	fclose (fp);
 	return 0;
}
