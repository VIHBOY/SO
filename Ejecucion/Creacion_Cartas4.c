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
  int pid, pid1, pid2,fd12[2],fd23[2],fd34[2],fd41[2],fd13[2],fd24[2],num;
  char    readbuffer[80];
  char    readbuffer2[80];
  pipe(fd12);pipe(fd23);pipe(fd34);pipe(fd41),pipe(fd13);pipe(fd24);
  char turno[3] ="M1";
  char *arr2[6];
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
          LList_moveTo(Mazo,atoi(arr2[1]));
          LList_remove(Mazo);
        }
        if (strcmp(arr2[2],"-1")!=0 && strcmp(arr2[3],"-1")!=0 && strcmp(arr2[4],"-1")!=0) {
          Carta_print(*Cartaactual(Ultima));
          Carta* Cartita=(Carta*)malloc(sizeof(Carta));
      		*Cartita = new_Carta(arr2[3],arr2[4],arr2[2]);
          LList_remove(Ultima);
      		LList_append(Ultima,*Cartita);
          free(Cartita);
          Carta_print(*Cartaactual(Ultima));
        }
          /*TURNO */
          if (strcmp(turno,"M3")==0) {
            printf("Mi turno 3\n");
              int n;
              int num;
              int n2=0;
              printf("----------------------\n");
              Carta_print(*Cartaactual(Ultima));
              printf("----------------------\n");
              LList_printAll2(J4,&n2,Ultima);
              Carta_print(*Cartaactual(J4));
              if (n2!=0) {
                printf("Ingrese carta a jugar: ");
                scanf("%d",&n );
                LList_moveTo(J4,n);
                if (Esjugable(Cartaactual(J4),Cartaactual(Ultima))==1) {
                  printf("Es jugable\n");
                  JugarCarta(J4,Ultima);
                  /*TURNO */
                  strcat(mensaje,"M4");
                  strcat(mensaje," -1 ");
                  strcat(mensaje, Ultima->curr->card.tipo);
                  strcat(mensaje," ");
                  strcat(mensaje, Ultima->curr->card.color);
                  strcat(mensaje," ");
                  strcat(mensaje, Ultima->curr->card.numero);
                  close(fd34[0]);
                  write(fd34[1], mensaje, (strlen(mensaje)+1));
                  strcpy(turno,"M4");
                  /*TURNO */
                }
                else{
                  printf("No Es jugable\n");
                }
              }
              else{
                printf( "Robas Carta\n");
                Robar2(Mazo,J4,&num);
                J4->curr=J4->tail;
                if (Esjugable(Cartaactual(J4),Cartaactual(Ultima))==1) {
                  printf("Es jugable\n");
                  JugarCarta(J4,Ultima);
                  J4->curr=J4->head;
                  /*TURNO */
                  strcat(mensaje,"M4 ");
                  sprintf(k,"%d",num);
                  strcat(mensaje,k);
                  strcat(mensaje," ");
                  strcat(mensaje, Ultima->curr->card.tipo);
                  strcat(mensaje," ");
                  strcat(mensaje, Ultima->curr->card.color);
                  strcat(mensaje," ");
                  strcat(mensaje, Ultima->curr->card.numero);
                  close(fd34[0]);
                  write(fd34[1], mensaje, (strlen(mensaje)+1));
                  strcpy(turno,"M4");
                }
                else{
                  printf("Fin del turno\n");
                  J4->curr=J4->head;
                  strcat(mensaje,"M4 ");
                  sprintf(k,"%d",num);
                  strcat(mensaje,k);
                  strcat(mensaje," ");
                  strcat(mensaje, Ultima->curr->card.tipo);
                  strcat(mensaje," ");
                  strcat(mensaje, Ultima->curr->card.color);
                  strcat(mensaje," ");
                  strcat(mensaje, Ultima->curr->card.numero);
                  close(fd34[0]);
                  write(fd34[1], mensaje, (strlen(mensaje)+1));
                  strcpy(turno,"M4");
                }

              }
          }}
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
              LList_moveTo(Mazo,atoi(arr2[1]));
              LList_remove(Mazo);

            }
            if (strcmp(arr2[2],"-1")!=0 && strcmp(arr2[3],"-1")!=0 && strcmp(arr2[4],"-1")!=0) {
              Carta_print(*Cartaactual(Ultima));
              Carta* Cartita=(Carta*)malloc(sizeof(Carta));
              *Cartita = new_Carta(arr2[3],arr2[4],arr2[2]);
              LList_remove(Ultima);
              LList_append(Ultima,*Cartita);
              free(Cartita);
              Carta_print(*Cartaactual(Ultima));
            }
              /*TURNO */
              if (strcmp(turno,"M2")==0) {
                printf("Mi turno 2\n");
                  int n;
                  int num;
                  int n2=0;
                  printf("----------------------\n");
                  Carta_print(*Cartaactual(Ultima));
                  printf("----------------------\n");
                  LList_printAll2(J2,&n2,Ultima);
                  Carta_print(*Cartaactual(J2));
                  if (n2!=0) {
                    printf("Ingrese carta a jugar: ");
                    scanf("%d",&n );
                    LList_moveTo(J2,n);
                    if (Esjugable(Cartaactual(J2),Cartaactual(Ultima))==1) {
                      printf("Es jugable\n");
                      JugarCarta(J2,Ultima);
                      /*TURNO */
                      strcat(mensaje,"M3");
                      strcat(mensaje," -1 ");
                      strcat(mensaje, Ultima->curr->card.tipo);
                      strcat(mensaje," ");
                      strcat(mensaje, Ultima->curr->card.color);
                      strcat(mensaje," ");
                      strcat(mensaje, Ultima->curr->card.numero);
                      close(fd23[0]);
                      write(fd23[1], mensaje, (strlen(mensaje)+1));
                      strcpy(turno,"M3");
                      /*TURNO */
                    }
                    else{
                      printf("No Es jugable\n");
                    }
                  }
                  else{
                    printf("Robas Carta\n");
                    Robar2(Mazo,J2,&num);
                    J2->curr=J2->tail;
                    if (Esjugable(Cartaactual(J2),Cartaactual(Ultima))==1) {
                      printf("Es jugable\n");
                      JugarCarta(J2,Ultima);
                      J2->curr=J2->head;
                      /*TURNO */
                      strcat(mensaje,"M3 ");
                      sprintf(k,"%d",num);
                      strcat(mensaje,k);
                      strcat(mensaje," ");
                      strcat(mensaje, Ultima->curr->card.tipo);
                      strcat(mensaje," ");
                      strcat(mensaje, Ultima->curr->card.color);
                      strcat(mensaje," ");
                      strcat(mensaje, Ultima->curr->card.numero);
                      close(fd23[0]);
                      write(fd23[1], mensaje, (strlen(mensaje)+1));
                      strcpy(turno,"M3");
                    }
                    else{
                      printf("Fin del turno\n");
                      J2->curr=J2->head;
                      strcat(mensaje,"M3 ");
                      sprintf(k,"%d",num);
                      strcat(mensaje,k);
                      strcat(mensaje," ");
                      strcat(mensaje, Ultima->curr->card.tipo);
                      strcat(mensaje," ");
                      strcat(mensaje, Ultima->curr->card.color);
                      strcat(mensaje," ");
                      strcat(mensaje, Ultima->curr->card.numero);
                      close(fd23[0]);
                      write(fd23[1], mensaje, (strlen(mensaje)+1));
                      strcpy(turno,"M3");
                    }

                  }
              }}
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
                  printf("%s\n",arr2[1] );
                  if (strcmp(arr2[1],"-1")!=0) {
                    LList_moveTo(Mazo,atoi(arr2[1]));
                    LList_remove(Mazo);
                  }
                  if (strcmp(arr2[2],"-1")!=0 && strcmp(arr2[3],"-1")!=0 && strcmp(arr2[4],"-1")!=0) {
                    Carta_print(*Cartaactual(Ultima));
                    Carta* Cartita=(Carta*)malloc(sizeof(Carta));
                		*Cartita = new_Carta(arr2[3],arr2[4],arr2[2]);
                    LList_remove(Ultima);
                		LList_append(Ultima,*Cartita);
                    free(Cartita);
                    Carta_print(*Cartaactual(Ultima));
                  }
                  }
                  if (strcmp(turno,"M1")==0) {
                    int n;
                    int num;
                    int n2=0;
                    printf("----------------------\n");
                    Carta_print(*Cartaactual(Ultima));
                    printf("----------------------\n");
                    LList_printAll2(J1,&n2,Ultima);
                    Carta_print(*Cartaactual(J1));
                    if (n2!=0) {
                      printf("Ingrese carta a jugar: ");
                      scanf("%d",&n );
                      LList_moveTo(J1,n);
                      if (Esjugable(Cartaactual(J1),Cartaactual(Ultima))==1) {
                        printf("Es jugable\n");
                        JugarCarta(J1,Ultima);
                        /*TURNO */
                        strcat(mensaje,"M2");
                        strcat(mensaje," -1 ");
                        strcat(mensaje, Ultima->curr->card.tipo);
                        strcat(mensaje," ");
                        strcat(mensaje, Ultima->curr->card.color);
                        strcat(mensaje," ");
                        strcat(mensaje, Ultima->curr->card.numero);
                        close(fd12[0]);
                        write(fd12[1], mensaje, (strlen(mensaje)+1));
                        close(fd12[0]);
                        write(fd13[1], mensaje, (strlen(mensaje)+1));
                        strcpy(turno,"M2");
                        f++;
                        /*TURNO */
                      }
                      else{
                        printf("No Es jugable\n");
                      }
                    }
                    else{
                      printf("Robas Carta\n");
                      Robar2(Mazo,J1,&num);
                      J1->curr=J1->tail;
                      if (Esjugable(Cartaactual(J1),Cartaactual(Ultima))==1) {
                        printf("Es jugable\n");
                        JugarCarta(J1,Ultima);
                        J1->curr=J1->head;
                        /*TURNO */
                        strcat(mensaje,"M2 ");
                        sprintf(k,"%d",num);
                        strcat(mensaje,k);
                        strcat(mensaje," ");
                        strcat(mensaje, Ultima->curr->card.tipo);
                        strcat(mensaje," ");
                        strcat(mensaje, Ultima->curr->card.color);
                        strcat(mensaje," ");
                        strcat(mensaje, Ultima->curr->card.numero);
                        close(fd12[0]);
                        write(fd12[1], mensaje, (strlen(mensaje)+1));
                        strcpy(turno,"M2");
                        f++;

                      }
                      else{
                        printf("Fin del turno\n");
                        J1->curr=J1->head;
                        strcat(mensaje,"M2 ");
                        sprintf(k,"%d",num);
                        strcat(mensaje,k);
                        strcat(mensaje," ");
                        strcat(mensaje, Ultima->curr->card.tipo);
                        strcat(mensaje," ");
                        strcat(mensaje, Ultima->curr->card.color);
                        strcat(mensaje," ");
                        strcat(mensaje, Ultima->curr->card.numero);
                        close(fd12[0]);
                        write(fd12[1], mensaje, (strlen(mensaje)+1));
                        strcpy(turno,"M2");
                        f++;
                      }
                    }
                }}
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
                  char mensaje[20]="";
                  char k[3]="";
                  int i2=0;
                  /*TURNO */
                  close(fd34[1]);
                  read(fd34[0], readbuffer, sizeof(readbuffer));
                  char *p=strtok (readbuffer, " ");
                  while (p != NULL){
                    arr2[i2++] = p;
                    p = strtok (NULL," ");
                }
                strcpy(turno,arr2[0]);
                if (strcmp(arr2[1],"-1")!=0) {
                  LList_moveTo(Mazo,atoi(arr2[1]));
                  LList_remove(Mazo);
                }
                if (strcmp(arr2[2],"-1")!=0 && strcmp(arr2[3],"-1")!=0 && strcmp(arr2[4],"-1")!=0) {
                  Carta_print(*Cartaactual(Ultima));
                  Carta* Cartita=(Carta*)malloc(sizeof(Carta));
              		*Cartita = new_Carta(arr2[3],arr2[4],arr2[2]);
                  LList_remove(Ultima);
              		LList_append(Ultima,*Cartita);
                  free(Cartita);
                  Carta_print(*Cartaactual(Ultima));
                }
                  if (strcmp(turno,"M4")==0) {
                    printf("Mi turno 4\n");
                      int n;
                      int num;
                      int n2=0;
                      printf("----------------------\n");
                      Carta_print(*Cartaactual(Ultima));
                      printf("----------------------\n");
                      LList_printAll2(J4,&n2,Ultima);
                      Carta_print(*Cartaactual(J4));
                      if (n2!=0) {
                        printf("Ingrese carta a jugar: ");
                        scanf("%d",&n );
                        LList_moveTo(J4,n);
                        if (Esjugable(Cartaactual(J4),Cartaactual(Ultima))==1) {
                          printf("Es jugable\n");
                          JugarCarta(J4,Ultima);
                          /*TURNO */
                          strcat(mensaje,"M1");
                          strcat(mensaje," -1 ");
                          strcat(mensaje, Ultima->curr->card.tipo);
                          strcat(mensaje," ");
                          strcat(mensaje, Ultima->curr->card.color);
                          strcat(mensaje," ");
                          strcat(mensaje, Ultima->curr->card.numero);
                          printf("%s\n",mensaje );
                          close(fd41[0]);
                          write(fd41[1], mensaje, (strlen(mensaje)+1));
                          close(fd24[0]);
                          write(fd24[1], "Hola", (strlen("Hola")+1));
                          strcpy(turno,"M1");
                          /*TURNO */
                        }
                        else{
                          printf("No Es jugable\n");
                        }
                      }
                      else{
                        printf("Robas Carta\n");
                        Robar2(Mazo,J4,&num);
                        J4->curr=J4->tail;
                        if (Esjugable(Cartaactual(J4),Cartaactual(Ultima))==1) {
                          printf("Es jugable\n");
                          JugarCarta(J4,Ultima);
                          J4->curr=J4->head;
                          /*TURNO */
                          strcat(mensaje,"M1 ");
                          sprintf(k,"%d",num);
                          strcat(mensaje,k);
                          strcat(mensaje," ");
                          strcat(mensaje, Ultima->curr->card.tipo);
                          strcat(mensaje," ");
                          strcat(mensaje, Ultima->curr->card.color);
                          strcat(mensaje," ");
                          strcat(mensaje, Ultima->curr->card.numero);
                          printf("%s\n",mensaje );
                          close(fd41[0]);
                          write(fd41[1], mensaje, (strlen(mensaje)+1));
                          strcpy(turno,"M1");
                        }
                        else{
                          printf("Fin del turno\n");
                          J4->curr=J4->head;
                          strcat(mensaje,"M1 ");
                          sprintf(k,"%d",num);
                          strcat(mensaje,k);
                          strcat(mensaje," ");
                          strcat(mensaje, Ultima->curr->card.tipo);
                          strcat(mensaje," ");
                          strcat(mensaje, Ultima->curr->card.color);
                          strcat(mensaje," ");
                          strcat(mensaje, Ultima->curr->card.numero);
                          printf("%s\n",mensaje );
                          close(fd41[0]);
                          write(fd41[1], mensaje, (strlen(mensaje)+1));
                          strcpy(turno,"M1");
                        }
                      }
                  }}
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
