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
	int count;
	for ( count = 0; count < 7; count++) {
	}
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
  int pid, pid1, pid2,fd12[2],fd23[2],fd34[2],fd41[2],fd13[2],fd24[2],num;
  char    readbuffer[80];
  pipe(fd12);pipe(fd23);pipe(fd34);pipe(fd41),pipe(fd13);pipe(fd24);
  char turno[3] ="M1";
  char *arr2[3];
  char* Juego_terminado="1";
  pid = fork();
  if (pid == 0) {
      sleep(2);
      LinkedList* J3=(LinkedList*)malloc(sizeof(LinkedList));
      *J3=new_LList(3);
      for ( count = 0; count < 7; count++) {
    		Robar(Mazo,J3);
    	}
      while (strcmp(Juego_terminado,"1")==0) {
        close(fd23[1]);
        read(fd23[0], readbuffer, sizeof(readbuffer));
        if (strcmp(readbuffer,"M3")==0) {
          strcpy(turno,readbuffer);
        }
        else{
          printf("3: %s\n", readbuffer);
        }
        if (strcmp(turno,"M3")==0) {
          printf("Mi turno 3\n");
          close(fd34[0]);
          write(fd34[1], "M4", (strlen("M4")+1));
          strcpy(turno,"M4");
        }}
      LList_clear(J3);
      free(J3);
  }
  else {
      pid1 = fork();
      if (pid1 == 0) {
          sleep(1);
          LinkedList* J2=(LinkedList*)malloc(sizeof(LinkedList));
          *J2=new_LList(2);
          for ( count = 0; count < 7; count++) {
         		Robar2(Mazo,J2,&num);
          }
            while (strcmp(Juego_terminado,"1")==0) {
              close(fd12[1]);
              read(fd12[0], readbuffer, sizeof(readbuffer));
              strcpy(turno,readbuffer);
              if (strcmp(turno,"M2")==0) {
                printf("Mi turno 2\n");
                close(fd23[0]);
                write(fd23[1], "M3", (strlen("M3")+1));
                strcpy(turno,"M3");
              }}
          LList_clear(J2);
          free(J2);
      }
      else {
          pid2 = fork();
          if (pid2 == 0) {
              LinkedList* J4=(LinkedList*)malloc(sizeof(LinkedList));
              *J4=new_LList(1);
              int f=0;
              int i2=0;
              for ( count = 0; count < 7; count++) {
             		Robar(Mazo,J4);}
                while (strcmp(Juego_terminado,"1")==0) {
                  if (f!=0) {
                    close(fd41[1]);
                    read(fd41[0], readbuffer, sizeof(readbuffer));
                    printf("BBBBBBBB: %s\n",readbuffer );
                      char *p=strtok (readbuffer, " ");
                    while (p != NULL){
                      arr2[i2++] = p;
                      p = strtok (NULL," ");
                  }
                  strcpy(turno,arr2[0]);
                  if (strcmp(arr2[1],"-1")!=0) {
                    printf("%d\n",Mazo->size);
                    LList_moveTo(Mazo,atoi(arr2[2]));
                    LList_remove(Mazo);
                    printf("%d\n",Mazo->size);

                  }
                  }
                  if (strcmp(turno,"M1")==0) {
                    printf("Mi turno 1\n");
                    char xc[10];
                    printf("ACA:" );
                    scanf("%s",xc);
                    if (strcmp(xc,"FIN")==0) {
                      close(fd12[0]);
                      write(fd12[1], "M2", (strlen("M2")+1));
                      strcpy(turno,"M2");
                      f++;
                    }
                  }}
              LList_clear(J4);
              free(J4);
          }
          else {
              sleep(3);
              LinkedList* J4=(LinkedList*)malloc(sizeof(LinkedList));
              *J4=new_LList(4);
              for ( count = 0; count < 7; count++) {
             		Robar(Mazo,J4);}
                while (strcmp(Juego_terminado,"1")==0) {
                  char mensaje[20]="";
                  char k[3]="";
                  /*TURNO */
                  close(fd34[1]);
                  read(fd34[0], readbuffer, sizeof(readbuffer));
                  strcpy(turno,readbuffer);
                  /*TURNO */
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
                          strcat(mensaje," -1");
                          close(fd41[0]);
                          write(fd41[1], mensaje, (strlen(mensaje)+1));
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
	free(Mazo);
	free(Ultima);
 	fclose (fp);


return 0;
}
