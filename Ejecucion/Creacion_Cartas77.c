#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "lista.h"
#include<sys/wait.h>
#define MAXSTRLEN 208
#define MAXWORD 3
int main ( int argc, char **argv )
{
 	FILE *fp;
	char arr[MAXWORD][MAXSTRLEN+1] = {0};
	int i=0;
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
	LinkedList* Ultima=(LinkedList*)malloc(sizeof(LinkedList));
	*Mazo=new_LList(0);
	*Ultima=new_LList(5);
	 while (fgets(buffer, 100, fp) != NULL){
		pch = strtok (buffer," ");
		while (pch != NULL && i < MAXWORD){strncpy(arr[i++], pch, MAXSTRLEN);pch = strtok (NULL, " ");}
		Carta* Cartita=(Carta*)malloc(sizeof(Carta));
		*Cartita = new_Carta(strtok(arr[2],"\n"),arr[1],arr[0]);
		LList_append(Mazo,*Cartita);
		i=0;free(Cartita);	}
	Llist_makedir(Mazo);
  Robar(Mazo,Ultima);
  /*while (J4->size>0) {
    int n;
    int n2=0;
    printf("----------------------\n");
    Carta_print(*Cartaactual(Ultima));
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
      Robar(Mazo,J4);
      Robar(Mazo,J4);
      Robar(Mazo,J4);
      Robar(Mazo,J4);
      printf("Fin del turno\n");
      break;
    }
    if (Efecto(*Cartaactual(Ultima))==1) {
      printf("Robas 2 Cartas\n");
      Robar(Mazo,J4);
      Robar(Mazo,J4);
      printf("Fin del turno\n");
      break;
    }
    printf("%d\n",Efecto(*Cartaactual(Ultima)));
    printf("----------------------\n");
    LList_printAll2(J4,&n2,Ultima);
    printf("Cartas posibles de jugar: %d\n",n2 );
    Carta_print(*Cartaactual(J4));
    if (n2!=0) {
      printf("Ingrese carta a jugar: ");
      scanf("%d",&n );
      LList_moveTo(J4,n);
      Carta_print(*Cartaactual(J4));
      if (Esjugable(Cartaactual(J4),Cartaactual(Ultima))==1) {
        printf("Es jugable\n");
        JugarCarta(J4,Ultima);
      }
      else{
        printf("No Es jugable\n");
      }
    }
    else{
      printf("Robas Carta\n");
      Robar(Mazo,J4);
      printf("Tamaño %d\n",J4->size );
      J4->curr=J4->tail;
      Carta_print(*Cartaactual(J4));
      if (Esjugable(Cartaactual(J4),Cartaactual(Ultima))==1) {
        printf("Es jugable\n");
        JugarCarta(J4,Ultima);
        J4->curr=J4->head;
      }
      else{
        printf("Fin del turno\n");
        J4->curr=J4->head;
        break;
      }

    }
  }*/
  fclose(fp);
  int count;
  int pid, pid1, pid2,fd12[2],fd23[2],fd34[2],fd41[2],fd122[2],fd232[2],fd342[2],fd412[2];
  char    readbuffer[80];
  pipe(fd12);pipe(fd23);pipe(fd34);pipe(fd41),pipe(fd13);pipe(fd24);
  char turno[3] ="M1";
  char *arr2[8];
  char* Juego_terminado="1";
  pid = fork();
  if (pid == 0) {
      sleep(2);
      LinkedList* J4=(LinkedList*)malloc(sizeof(LinkedList));
      *J4=new_LList(3);
      for ( count = 0; count < 2; count++) {
        Robar(Mazo,J4);}
        while (strcmp(Juego_terminado,"1")==0 && J4->size>0) {
          char mensaje[20]="";
          char k[3]="";
          int i2=0;
          /*TURNO */
          close(fd23[1]);
          read(fd23[0], readbuffer, sizeof(readbuffer));
          char *p=strtok (readbuffer, " ");
          while (p != NULL){
            arr2[i2++] = p;
            p = strtok (NULL," ");
        }
        strcpy(turno,arr2[0]);
        if (strcmp(arr2[1],"-1")!=0) {
          printf("ddd\n" );
          LList_Actualizacion(Mazo,arr2[1],arr2[2],arr2[3]);
        };
        if (strcmp(arr2[4],"-1")!=0 && strcmp(arr2[5],"-1")!=0 && strcmp(arr2[6],"-1")!=0) {
          Carta* Cartita=(Carta*)malloc(sizeof(Carta));
          *Cartita = new_Carta(arr2[5],arr2[6],arr2[4]);
          LList_remove(Ultima);
          LList_append(Ultima,*Cartita);
          free(Cartita);
        }
          /*TURNO */
          turno2(Mazo,J4,Ultima,turno,fd34);
          }
      LList_clear(J4);
      free(J4);
  }
  else {
    /* turno 2*/
      pid1 = fork();
      if (pid1 == 0) {
          sleep(1);
          LinkedList* J2=(LinkedList*)malloc(sizeof(LinkedList));
          *J2=new_LList(2);
          for ( count = 0; count < 2; count++) {
            Robar(Mazo,J2);}
            while (strcmp(Juego_terminado,"1")==0 && J2->size>0) {
              char mensaje[30]="";
              char k[3]="";
              int i2=0;
              /*TURNO */
              close(fd12[1]);
              read(fd12[0], readbuffer, sizeof(readbuffer));
              char *p=strtok (readbuffer, " ");
              while (p != NULL){
                arr2[i2++] = p;
                p = strtok (NULL," ");
            }
            strcpy(turno,arr2[0]);
            if (strcmp(arr2[1],"-1")!=0) {
+              LList_Actualizacion(Mazo,arr2[1],arr2[2],arr2[3]);
            };
            if (strcmp(arr2[4],"-1")!=0 && strcmp(arr2[5],"-1")!=0 && strcmp(arr2[6],"-1")!=0) {
              Carta* Cartita=(Carta*)malloc(sizeof(Carta));
              *Cartita = new_Carta(arr2[5],arr2[6],arr2[4]);
              LList_remove(Ultima);
              LList_append(Ultima,*Cartita);
              free(Cartita);
            }
              turno2(Mazo,J2,Ultima,turno,fd23);
            }
          LList_clear(J2);
          free(J2);
      }
      else {
        /* turno 1*/
          pid2 = fork();
          if (pid2 == 0) {
              LinkedList* J1=(LinkedList*)malloc(sizeof(LinkedList));
              *J1=new_LList(1);
              int f=0;
              int i2=0;
              for ( count = 0; count < 2; count++) {
             		Robar(Mazo,J1);}
                while (strcmp(Juego_terminado,"1")==0 && J1->size>0) {
                  char mensaje[30]="";
                  char k[3]="";
                  int i2=0;
                  /*TURNO */
                  if (f!=0) {
                    close(fd41[1]);
                    read(fd41[0], readbuffer, sizeof(readbuffer));
                    char *p=strtok (readbuffer, " ");
                    while (p != NULL){
                      arr2[i2++] = p;
                      p = strtok (NULL," ");
                  }
                  strcpy(turno,arr2[0]);
                  if (strcmp(arr2[1],"-1")!=0) {
                    LList_Actualizacion(Mazo,arr2[1],arr2[2],arr2[3]);
                  }
                  if (strcmp(arr2[4],"-1")!=0 && strcmp(arr2[5],"-1")!=0 && strcmp(arr2[6],"-1")!=0) {
                    Carta* Cartita=(Carta*)malloc(sizeof(Carta));
                    *Cartita = new_Carta(arr2[5],arr2[6],arr2[4]);
                    LList_remove(Ultima);
                		LList_append(Ultima,*Cartita);
                    free(Cartita);
                  }
                  }
                  f++;
                  turno2(Mazo,J1,Ultima,turno,fd12);
                }
            LList_clear(J1);
            free(J1);
          }
          else {
            /* turno 4*/
              sleep(3);
              LinkedList* J4=(LinkedList*)malloc(sizeof(LinkedList));
              *J4=new_LList(4);
              for ( count = 0; count < 2; count++) {
             		Robar(Mazo,J4);}
                while (strcmp(Juego_terminado,"1")==0 && J4->size>0)  {
                  /*TURNO */
                  int i2=0;
                  close(fd34[1]);
                  read(fd34[0], readbuffer, sizeof(readbuffer));
                  char *p=strtok (readbuffer, " ");
                  while (p != NULL){
                    arr2[i2++] = p;
                    p = strtok (NULL," ");
                }
                strcpy(turno,arr2[0]);
                if (strcmp(arr2[1],"-1")!=0) {
                  printf("ddd\n" );
                  LList_Actualizacion(Mazo,arr2[1],arr2[2],arr2[3]);
                }
                if (strcmp(arr2[4],"-1")!=0 && strcmp(arr2[5],"-1")!=0 && strcmp(arr2[6],"-1")!=0) {
                  Carta* Cartita=(Carta*)malloc(sizeof(Carta));
                  *Cartita = new_Carta(arr2[5],arr2[6],arr2[4]);
                  LList_remove(Ultima);
              		LList_append(Ultima,*Cartita);
                  free(Cartita);
                }
                  turno2(Mazo,J4,Ultima,turno,fd41);
                  }
              LList_clear(J4);
              free(J4);
          }
      }
  }
	LList_clear(Mazo);
  LList_clear(Ultima);
	free(Mazo);
	free(Ultima);
return 0;
}
