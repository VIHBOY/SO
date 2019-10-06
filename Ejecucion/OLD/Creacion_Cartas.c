#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "lista.h"
#define MAXSTRLEN 208
#define MAXWORD 3
int main ( int argc, char **argv )
{
 	FILE *fp;
	char arr[MAXWORD][MAXSTRLEN+1] = {0};
	int i=0;
	time_t t;
	srand((unsigned) time(&t));
 	char buffer[100];
	char* pch;
 	fp = fopen ("Cartas.txt","r");
  char cwd[256] = "";
  chdir("..");
  crearCarpeta(strcat(getcwd(cwd, 256), "/Jugador 1"), 0777);
  crearCarpeta(strcat(getcwd(cwd, 256), "/Jugador 2"), 0777);
  crearCarpeta(strcat(getcwd(cwd, 256), "/Jugador 3"), 0777);
  crearCarpeta(strcat(getcwd(cwd, 256), "/Jugador 4"), 0777);
  crearCarpeta(strcat(getcwd(cwd, 256), "/Ultima Jugada"), 0777);
  crearCarpeta(strcat(getcwd(cwd, 256), "/Mazo"), 0777);
  chdir("Mazo");
	LinkedList* Mazo=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* J1=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* J2=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* J3=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* J4=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* Ultima=(LinkedList*)malloc(sizeof(LinkedList));
	*Mazo=new_LList(0);
	*J1=new_LList(1);
	*J2=new_LList(2);
	*J3=new_LList(3);
	*J4=new_LList(4);
	*Ultima=new_LList(5);
  printf("ddddddd\n" );
	 while (fgets(buffer, 100, fp) != NULL){
		pch = strtok (buffer," ");
		while (pch != NULL && i < MAXWORD){strncpy(arr[i++], pch, MAXSTRLEN);pch = strtok (NULL, " ");}
		Carta* Cartita=(Carta*)malloc(sizeof(Carta));
		*Cartita = new_Carta(strtok(arr[2],"\n"),arr[1],arr[0]);
		LList_append(Mazo,*Cartita);
    printf("ddddddd\n" );
		i=0;free(Cartita);}
  printf("aaa\n" );
  LList_printAll(Mazo);
	Llist_makedir(Mazo);
  printf("aaa\n" );
	int count;
	for ( count = 0; count < 7; count++) {
		Robar(Mazo,J1);
    Robar(Mazo,J2);
    Robar(Mazo,J3);
    Robar(Mazo,J4);
    printf("aaa\n" );
	}
	Robar(Mazo,Ultima);
	LList_clear(Mazo);
  LList_clear(J1);
	LList_clear(J2);
	LList_clear(J3);
	LList_clear(J4);
	LList_clear(Ultima);
	free(J1);
	free(J2);
	free(J3);
	free(J4);
	free(Mazo);
	free(Ultima);
 	fclose (fp);
return 0;
}
