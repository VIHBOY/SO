#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>    // time()
#include "funciones.h"
void MoverCarta(LinkedList* Mazo, int numero_carta,LinkedList* Jugador){
	LList_moveTo(Mazo,numero_carta);
	repartir(Cartaactual(Mazo),1);
	LList_reLink(Jugador,Mazo);
}
int main ( int argc, char **argv )
{
 	FILE *fp;
	char arr[MAXWORD][MAXSTRLEN+1] = {0};
	int i=0;
	time_t t;
	srand((unsigned) time(&t));
 	char buffer[100];
	char delim[] = " ";
	char* pch;
 	fp = fopen ("Cartas.txt","r");
	LinkedList* Mazo=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* J1=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* J2=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* J3=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* J4=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* Ultima=(LinkedList*)malloc(sizeof(LinkedList));
	*Mazo=new_LList();
	*J1=new_LList();
	*J2=new_LList();
	*J3=new_LList();
	*J4=new_LList();
	*Ultima=new_LList();
	 while (fgets(buffer, 100, fp) != NULL){
		pch = strtok (buffer," ");
		while (pch != NULL && i < MAXWORD){strncpy(arr[i++], pch, MAXSTRLEN);pch = strtok (NULL, " ");}
		Carta* Cartita=(Carta*)malloc(sizeof(Carta));
		*Cartita = new_Carta(strtok(arr[2],"\n"),arr[1],arr[0]);
		LList_append(Mazo,*Cartita);
		i=0;free(Cartita);
		}
	int count;
	Llist_deletedir(Mazo);
	printf("------------------\n");
	LList_clear(Mazo);
	free(J1);
	free(J2);
	free(J3);
	free(J4);
	free(Mazo);
 	fclose (fp);
return 0;
}
