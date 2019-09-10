#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>    // time()
char* getcard(){
  char* color;
  char result[10];
  char Carta_final[30];
  char *Carta_final2= malloc(sizeof(char)*30);
  int x2=rand() % (9 + 1 - 0) + 0;
  int x=rand() % (3 + 1 - 0) + 0;
  sprintf(result,"%d",x2);
  switch (x) {
    case 0:
      color=" Rojo";
      strcpy(Carta_final,strcat(result,color));
      strcpy(Carta_final2,strcat(Carta_final,".txt"));
      return Carta_final2;
    case 1:
      color=" Verde";
      strcpy(Carta_final,strcat(result,color));
      strcpy(Carta_final2,strcat(Carta_final,".txt"));
      return Carta_final2;
    case 2:
      color=" Amarilla";
      strcpy(Carta_final,strcat(result,color));
      strcpy(Carta_final2,strcat(Carta_final,".txt"));
      return Carta_final2;
    case  3:
      color=" Azul";
      strcpy(Carta_final,strcat(result,color));
      strcpy(Carta_final2,strcat(Carta_final,".txt"));
      return Carta_final2;
  }

}
void repartir(char* carta, int jugador) {
  char ruta1[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 1/";
  char ruta2[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 2/";
  char origen[]= "/home/sida/Desktop/GIT/SO2/SO/Mazo/";
  if (jugador==1) {
    int n=rename(strcat(origen,carta),strcat(ruta1,carta));
    if(!n)
    {
        printf("%s\n", "Repartido");
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
  time_t t;
  srand((unsigned) time(&t));
  FILE *fp2;
 	char buffer[100];
  char ruta1[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 1/";
  char ruta2[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 2/";
 	fp = fopen ("Cartas.txt","r");
  rename("a.txt","/home/sida/Desktop/GIT/SO2/SO/Jugador 1/a2.txt");
  /*while (fgets(buffer, 100, fp) != NULL){
    strtok(buffer, "\n");
    fp2= fopen(buffer,"r");
    fclose(fp2);
  }*/
  /*DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d){
    while ((dir = readdir(d)) != NULL){
      printf("%s\n", dir->d_name);}
    closedir(d);}*/
  for (size_t i = 0; i < 10; i++) {
    printf("%s\n",getcard());
    repartir(getcard(),1);
  }

 	fclose (fp);
 	return 0;
}
