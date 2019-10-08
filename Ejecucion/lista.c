#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#define LARGO_MAXIMO 256
#define MAXSTRLEN 208
#define MAXWORD 3
#include "lista.h"
int crearCarpeta(const char *dir, const mode_t mode) {
    char tmp[LARGO_MAXIMO];
    char *p = NULL;
    struct stat sb;
    size_t len;
    /* Copia del dir */
    len = strnlen (dir, LARGO_MAXIMO);
    if (len == 0 || len == LARGO_MAXIMO) {
        return -1;
    }
    memcpy (tmp, dir, len);
    tmp[len] = '\0';

    /* Remueve / sobrante */
    if(tmp[len - 1] == '/') {
        tmp[len - 1] = '\0';
    }

    /* Chequeo de la existencia del directorio */
    if (stat (tmp, &sb) == 0) {
        if (S_ISDIR (sb.st_mode)) {
            return 0;
        }
    }

    /* Recursion */
    for(p = tmp + 1; *p; p++) {
        if(*p == '/') {
            *p = 0;
            /* Prueba del dir */
            if (stat(tmp, &sb) != 0) {
                /* Si no existe - se crea */
                if (mkdir(tmp, mode) < 0) {
                    return -1;
                }
            } else if (!S_ISDIR(sb.st_mode)) {
                /* No es un directorio valido */
                return -1;
            }
            *p = '/';
        }
    }
    /* Prueba del dir */
    if (stat(tmp, &sb) != 0) {
        /* Si no existe - se crea */
        if (mkdir(tmp, mode) < 0) {
            return -1;
        }
    } else if (!S_ISDIR(sb.st_mode)) {
        /* No es un directorio valido */
        return -1;
    }
    return 0;
}
Carta new_Carta(char* c, char* n, char* t){
	Carta card;
	char nombre[90];
	card.color=malloc(sizeof(char)*strlen(c)+1);
	card.numero=malloc(sizeof(char)*strlen(n)+1);
	card.tipo=malloc(sizeof(char)*strlen(t)+1);
	strcpy(card.color,c);
	strcpy(card.numero,n);
	strcpy(card.tipo,t);
	if (strcmp(card.tipo,"Carta")==0 || strcmp(card.tipo,"Especial")==0) {
		sprintf(nombre,"%s %s.txt",card.numero,card.color);
		card.nombre=malloc(sizeof(char)*strlen(nombre)+1);
	}
	if (strcmp(card.tipo,"Especial_R")==0 || strcmp(card.tipo,"Carta_R")==0) {
		sprintf(nombre,"%s %s_2.txt",card.numero,card.color);
		card.nombre=malloc(sizeof(char)*strlen(nombre)+1);
	}
	if (strcmp(card.tipo,"Especial_R2")==0 ) {
		sprintf(nombre,"%s %s_3.txt",card.numero,card.color);
		card.nombre=malloc(sizeof(char)*strlen(nombre)+1);
	}
	if (strcmp(card.tipo,"Especial_R3")==0 ) {
		sprintf(nombre,"%s %s_4.txt",card.numero,card.color);
		card.nombre=malloc(sizeof(char)*strlen(nombre)+1);
	}
	strcpy(card.nombre,nombre);
	return card;
}
void Carta_creado(Carta card){
	FILE* fp;
	fp=fopen(card.nombre,"w");
	fclose(fp);
}
void Carta_print(Carta card) {
	printf("Carta: %s Color: %s\n",card.numero,card.color);
}
void Carta_borrado(Carta card){
	remove(card.nombre);
}
Element new_Element(){
	Element elem;
	elem.next=NULL;
	elem.prev=NULL;
	return elem;
}
void LList_clear(LinkedList* list){
	Element* pnt=list->tail;
	int i,lim=list->size-1;
	free((void*)pnt->card.nombre);
	free((void*)pnt->card.color);
	free((void*)pnt->card.tipo);
	free((void*)pnt->card.numero);
	free(pnt->next);
	for(i=0;i<lim;i++){
		pnt=pnt->prev;
		free((void*)pnt->card.nombre);
		free((void*)pnt->card.color);
		free((void*)pnt->card.tipo);
		free((void*)pnt->card.numero);
		free(pnt->next);
	}
	free(pnt);
	list->size=0;
	list->index=0;
	list->head=NULL;
	list->tail=NULL;
	list->curr=NULL;
}
LinkedList new_LList(int a){
	LinkedList list;
	list.curr=NULL;list.head=NULL;list.tail=NULL;
	list.size=0;list.index=0;list.jugador=a;
	return list;
}
void LList_printAll(LinkedList* list){
  printf("%d\n",list->size );
	Element* p=list->head;
	while(p!=list->tail){
		 printf("Indice: %d Color: %s Numero: %s\n",list->index,p->card.color,p->card.numero);
		 p=p->next;
	}
	if(p==list->curr){printf("Indice: %d Color: %s Numero: %s\n",list->index,p->card.color,p->card.numero);}
		else {printf("Indice: %d Color: %s Numero: %s\n",list->index,p->card.color,p->card.numero);}
}
void LList_printAll2(LinkedList* list, int* n, LinkedList* Ultima){
  Element* p=list->head;
  int i=0;
  for (i = 0; i < list->size; i++) {
      printf("%d. Color: %s Numero: %s\n",i,p->card.color,p->card.numero);
      if (Esjugable(&p->card,Cartaactual(Ultima))==1) {
        *n=*n+1;
      }
      p=p->next;
  }
}
int Esjugable(Carta* Jugada, Carta* Ultima){
  if (strcmp(Jugada->color,Ultima->color)==0) {
    return 1;
  }
  if (strcmp(Jugada->numero,Ultima->numero)==0) {
    return 1;
  }
  else
    return 0;
}
int Efecto(Carta Ultima){
  if (strcmp(Ultima.tipo,"Especial")==0 || strcmp(Ultima.tipo,"Especial_R")==0 || strcmp(Ultima.tipo,"Especial_R2")==0 || strcmp(Ultima.tipo,"Especial_R3")==0  ) {
    if (strcmp(Ultima.numero,"+2")==0 ) {
      return 1;
    }
    if (strcmp(Ultima.numero,"+4")==0 ) {
      return 2;
    }
    if (strcmp(Ultima.numero,"Reversa")==0 ) {
      return 3;
    }
    if (strcmp(Ultima.numero,"Salto")==0 ) {
      return 4;
    }
  }
    return 0;
}
Carta* Cartaactual(LinkedList* list){
	return &(list->curr->card);
}
void Llist_makedir(LinkedList* list){
	Element* p=list->head;
	while(p!=list->tail){
		 Carta_creado(p->card);
		 p=p->next;
	}
	if(p==list->curr){ Carta_creado(p->card);}
		else { Carta_creado(p->card);}
}
void Llist_deletedir(LinkedList* list){
	Element* p=list->head;
	while(p!=list->tail){
		 Carta_borrado(p->card);
		 p=p->next;
	}
	if(p==list->curr){  Carta_borrado(p->card);}
		else {  Carta_borrado(p->card);}
}
int LList_append(LinkedList* list,Carta card){
	Element* elem=(Element *)malloc(sizeof(Element));
	*elem=new_Element();
	elem->card=card;
	if(list->size==0){
		list->head=elem;
		list->curr=elem;
		list->tail=elem;
	} else {
		list->tail->next=elem;
		elem->prev=list->tail;
		list->tail=elem;
	}
	return (list->size)++;
}
int LList_moveTo(LinkedList* list,int pos){
	int i,lim;
	if(pos<list->index){	//Nueva posición está antes de la actual
		if(list->index-pos<pos/2){	//Más cercana a la actual
			lim=list->index-pos;
			for(i=0;i<lim;i++) list->curr=list->curr->prev;
		} else {		//Más cercana al comienzo
			list->curr=list->head;
			for(i=0;i<pos;i++) list->curr=list->curr->next;
		}
	} else {	//Nueva posición está después de la actual
		if(pos>list->index+((list->size-list->index)/2)){	//Más cercana al final
			list->curr=list->tail;
			lim=list->size-pos-1;
			for(i=0;i<lim;i++) list->curr=list->curr->prev;
		} else {		//Más cercana a la actual
			lim=pos-list->index;
			for(i=0;i<lim;i++) list->curr=list->curr->next;
		}
	}
	list->index=pos;
	return pos;
}
int LList_remove(LinkedList* list){
	Element* curr=list->curr;
	if(curr->prev!=NULL){
		curr->prev->next=curr->next;
	} else {
		list->head=curr->next;
		list->curr=list->head;
	}
	if(curr->next!=NULL){
		curr->next->prev=curr->prev;
		list->curr=curr->next;
	} else {
		list->tail=curr->prev;
		list->curr=list->tail;
		list->index--;
	}
	free(curr);
	return list->size--;
}
void LList_reLink(LinkedList* dest,LinkedList* from){
	Carta data=from->curr->card;
	LList_remove(from);
	LList_append(dest,data);
}
void repartir2(Carta* card, int jugador) {
    char name[100]="";
    char name2[100]="";
  	char dir[100]="";
    char mazo[100]="";
    chdir("..");
    chdir("Mazo/");
    if (jugador==1) {
      chdir("..");
   	  chdir("Ultima Jugada/");
      strcat(name2,getcwd(dir, 100));
      strcat(name2,"/");
      strcat(name2,card->nombre);
      chdir("..");
      chdir("Jugador 1/");
      strcpy(mazo,getcwd(dir,100));
      strcat(name,mazo);
      strcat(name,"/");
      strcat(name,card->nombre);
      rename(name,name2);
  	}
    if (jugador==2) {
      chdir("..");
   	  chdir("Ultima Jugada/");
      strcat(name2,getcwd(dir, 100));
      strcat(name2,"/");
      strcat(name2,card->nombre);
      strcat(name,mazo);
      strcat(name,"/");
      strcat(name,card->nombre);
      rename(name,name2);
  	}
   if (jugador==3) {
     chdir("..");
     chdir("Ultima Jugada/");
     strcat(name2,getcwd(dir, 100));
     strcat(name2,"/");
     strcat(name2,card->nombre);
     strcat(name,mazo);
     strcat(name,"/");
     strcat(name,card->nombre);
     rename(name,name2);
   	}
   if (jugador==4) {
     chdir("..");
     chdir("Ultima Jugada/");
     strcat(name2,getcwd(dir, 100));
     strcat(name2,"/");
     strcat(name2,card->nombre);
     strcat(name,mazo);
     strcat(name,"/");
     strcat(name,card->nombre);
     rename(name,name2);
   	}
  	}
void repartir(Carta* card, int jugador) {
    char name[100]="";
    char name2[100]="";
  	char dir[100]="";
    char mazo[100]="";
    chdir("..");
    chdir("Mazo/");
    strcpy(mazo,getcwd(dir,100));
    if (jugador==1) {
  	 chdir("..");
  	 chdir("Jugador 1/");
  	 strcat(name2,getcwd(dir, 100));
  	 strcat(name2,"/");
   	 strcat(name2,card->nombre);
  	 strcat(name,mazo);
     strcat(name,"/");
  	 strcat(name,card->nombre);
     rename(name,name2);
  	}
    if (jugador==2) {
      chdir("..");
      chdir("Jugador 2/");
      strcat(name2,getcwd(dir, 100));
      strcat(name2,"/");
      strcat(name2,card->nombre);
      strcat(name,mazo);
      strcat(name,"/");
      strcat(name,card->nombre);
      rename(name,name2);
  	}
   if (jugador==3) {
      chdir("..");
      chdir("Jugador 3/");
      strcat(name2,getcwd(dir, 100));
      strcat(name2,"/");
      strcat(name2,card->nombre);
      strcat(name,mazo);
      strcat(name,"/");
      strcat(name,card->nombre);
      rename(name,name2);
   	}
   if (jugador==4) {
      chdir("..");
      chdir("Jugador 4/");
      strcat(name2,getcwd(dir, 100));
      strcat(name2,"/");
      strcat(name2,card->nombre);
      strcat(name,mazo);
      strcat(name,"/");
      strcat(name,card->nombre);
      rename(name,name2);
   	}
   if (jugador==5) {
  	 chdir("..");
  	 chdir("Ultima Jugada/");
     strcat(name2,getcwd(dir, 100));
     strcat(name2,"/");
     strcat(name2,card->nombre);
     strcat(name,mazo);
     strcat(name,"/");
     strcat(name,card->nombre);
     rename(name,name2);
     }
  	}
void Robar(LinkedList* Mazo,LinkedList* Jugador){
  int numero_carta=rand()%Mazo->size;
  int numero_jugador=Jugador->jugador;
  LList_moveTo(Mazo,numero_carta);
	repartir(Cartaactual(Mazo),numero_jugador);
	LList_reLink(Jugador,Mazo);
    }
void JugarCarta(LinkedList* Mano,LinkedList* Ultima){
  Carta_borrado2(*(Cartaactual(Ultima)),5);
  repartir2(&(Mano->curr->card),1);
  LList_reLink(Ultima,Mano);
  free((void*)Ultima->curr->card.nombre);
  free((void*)Ultima->curr->card.color);
  free((void*)Ultima->curr->card.tipo);
  free((void*)Ultima->curr->card.numero);
  LList_remove(Ultima);
    }
void Carta_borrado2(Carta card, int jugador){
		char name2[100]="";
		char dir[100]="";
	    if (jugador==1) {
			 chdir("..");
		 	 chdir("Jugador 1/");
		 	 strcat(name2,getcwd(dir, 100));
		 	 strcat(name2,"/");
		   strcat(name2,card.nombre);
	  	 remove(name2);
	  	}
      if (jugador==5) {
			 chdir("..");
		 	 chdir("Ultima Jugada/");
		 	 strcat(name2,getcwd(dir, 100));
		 	 strcat(name2,"/");
		   strcat(name2,card.nombre);
	  	 remove(name2);
	  	}
			if (jugador==2) {
			 chdir("..");
		 	 chdir("Jugador 2/");
		 	 strcat(name2,getcwd(dir, 100));
		 	 strcat(name2,"/");
		   strcat(name2,card.nombre);
	  	 remove(name2);
		 }if (jugador==3) {
			 chdir("..");
		 	 chdir("Jugador 3/");
		 	 strcat(name2,getcwd(dir, 100));
		 	 strcat(name2,"/");
		   strcat(name2,card.nombre);
	  	 remove(name2);
		 }if (jugador==4) {
			 chdir("..");
		 	 chdir("Jugador 4/");
		 	 strcat(name2,getcwd(dir, 100));
		 	 strcat(name2,"/");
		   strcat(name2,card.nombre);
	  	 remove(name2);
	  	}

	}
void Llist_deletedir2(LinkedList* list, int njugador){
		Element* p=list->head;
		while(p!=list->tail){
			 Carta_borrado2(p->card, njugador);
			 p=p->next;
		}
		if(p==list->curr){  Carta_borrado2(p->card,njugador);}
			else {  Carta_borrado2(p->card,njugador);}
	}
