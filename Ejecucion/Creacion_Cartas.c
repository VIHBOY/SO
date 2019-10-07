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
	 while (fgets(buffer, 100, fp) != NULL){
		pch = strtok (buffer," ");
		while (pch != NULL && i < MAXWORD){strncpy(arr[i++], pch, MAXSTRLEN);pch = strtok (NULL, " ");}
		Carta* Cartita=(Carta*)malloc(sizeof(Carta));
		*Cartita = new_Carta(strtok(arr[2],"\n"),arr[1],arr[0]);
		LList_append(Mazo,*Cartita);
		i=0;free(Cartita);	}
	Llist_makedir(Mazo);
	int count;
	for ( count = 0; count < 7; count++) {
		Robar(Mazo,J1);
    Robar(Mazo,J2);
    Robar(Mazo,J3);
    Robar(Mazo,J4);
	}
	Robar(Mazo,Ultima);
  while (J1->size>0) {
    int n;
    int n2=0;
    printf("----------------------\n");
    Carta_print(*Cartaactual(Ultima));
    if (J1->size==2){
      if (Efecto(*Cartaactual(Ultima))==4) {
      printf("Aplicacion de salto\n" );
      printf("Fin del turno\n");
      break;
    }
    if (Efecto(*Cartaactual(Ultima))==3) {
      printf("Reversa\n" );
      printf("Fin del turno\n");
      break;
    }
    if (Efecto(*Cartaactual(Ultima))==2) {
      printf("Robas 4 Cartas\n");
      Robar(Mazo,J1);
      Robar(Mazo,J1);
      Robar(Mazo,J1);
      Robar(Mazo,J1);
      printf("Fin del turno\n");
      break;
    }
    if (Efecto(*Cartaactual(Ultima))==1) {
      printf("Robas 2 Cartas\n");
      Robar(Mazo,J1);
      Robar(Mazo,J1);
      printf("Fin del turno\n");
      break;
    }
    printf("%d\n",Efecto(*Cartaactual(Ultima)));
    printf("----------------------\n");
    LList_printAll2(J1,&n2,Ultima);
    printf("Cartas posibles de jugar: %d\n",n2 );
    Carta_print(*Cartaactual(J1));
    if (n2!=0) {
      printf("Ingrese carta a jugar: ");
      scanf("%d",&n );
      LList_moveTo(J1,n);
      Carta_print(*Cartaactual(J1));
      if (Esjugable(Cartaactual(J1),Cartaactual(Ultima))==1) {
        printf("Es jugable\n");
        JugarCarta(J1,Ultima);
        printf("UNO!!\n");
      }
      else{
        printf("No Es jugable\n");
      }
    }
    else{
      printf("Robas Carta\n");
      Robar(Mazo,J1);
      printf("Tamaño %d\n",J1->size );
      J1->curr=J1->tail;
      Carta_print(*Cartaactual(J1));
      if (Esjugable(Cartaactual(J1),Cartaactual(Ultima))==1) {
        printf("Es jugable\n");
        JugarCarta(J1,Ultima);
        J1->curr=J1->head;
      }
      else{
        printf("Fin del turno\n");
        J1->curr=J1->head;
        break;
      }

    }
    }
    else{
      if (Efecto(*Cartaactual(Ultima))==4) {
        printf("Aplicacion de salto\n" );
        printf("Fin del turno\n");
        break;
      }
      if (Efecto(*Cartaactual(Ultima))==3) {
        printf("Reversa\n" );
        printf("Fin del turno\n");
        break;
      }
      if (Efecto(*Cartaactual(Ultima))==2) {
        printf("Robas 4 Cartas\n");
        Robar(Mazo,J1);
        Robar(Mazo,J1);
        Robar(Mazo,J1);
        Robar(Mazo,J1);
        printf("Fin del turno\n");
        break;
      }
      if (Efecto(*Cartaactual(Ultima))==1) {
        printf("Robas 2 Cartas\n");
        Robar(Mazo,J1);
        Robar(Mazo,J1);
        printf("Fin del turno\n");
        break;
      }
      printf("%d\n",Efecto(*Cartaactual(Ultima)));
      printf("----------------------\n");
      LList_printAll2(J1,&n2,Ultima);
      printf("Cartas posibles de jugar: %d\n",n2 );
      Carta_print(*Cartaactual(J1));
      if (n2!=0) {
        printf("Ingrese carta a jugar: ");
        scanf("%d",&n );
        LList_moveTo(J1,n);
        Carta_print(*Cartaactual(J1));
        if (Esjugable(Cartaactual(J1),Cartaactual(Ultima))==1) {
          printf("Es jugable\n");
          JugarCarta(J1,Ultima);
        }
        else{
          printf("No Es jugable\n");
        }
      }
      else{
        printf("Robas Carta\n");
        Robar(Mazo,J1);
        printf("Tamaño %d\n",J1->size );
        J1->curr=J1->tail;
        Carta_print(*Cartaactual(J1));
        if (Esjugable(Cartaactual(J1),Cartaactual(Ultima))==1) {
          printf("Es jugable\n");
          JugarCarta(J1,Ultima);
          J1->curr=J1->head;
        }
        else{
          printf("Fin del turno\n");
          J1->curr=J1->head;
          break;
        }

      }
    }
    }
  if (J1->size!=0) {
    LList_clear(J1);
  }
	LList_clear(Mazo);
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
