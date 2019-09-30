#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#define MAXSTRLEN 208
#define MAXWORD 3
#include "lista.h"
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
	printf("%s %s\n",card.numero,card.color);
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
LinkedList new_LList(){
	LinkedList list;
	list.curr=NULL;list.head=NULL;list.tail=NULL;
	list.size=0;list.index=0;
	return list;
}
void LList_printAll(LinkedList* list){
	Element* p=list->head;
	while(p!=list->tail){
		 Carta_print(p->card);
		 p=p->next;
	}
	if(p==list->curr){Carta_print(p->card);}
		else {Carta_print(p->card);}
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
			lim=list->size-pos;
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
void repartir(Carta* card, int jugador) {
  char name[100]="";
  char name2[100]="";
	char dir[100]="";
  char ruta1[]= "./Jugador 1/";
  char ruta2[]= "/home/joaquin.concha/Escritorio/GIT/SO/Jugador 2/";
  char ruta3[]= "/home/joaquin.concha/Escritorio/GIT/SO/Jugador 3/";
  char ruta4[]= "/home/joaquin.concha/Escritorio/GIT/SO/Jugador 4/";
  char rutaUltima[]= "/home/joaquin.concha/Escritorio/GIT/SO/Ultima Carta/";
  char origen[]= "/home/joaquin.concha/Escritorio/GIT/SO/Mazo/";
  if (jugador==1) {
	 chdir("..")
	 chdir("/Jugador 1");
	 printf("%s\n",getcwd(s, 100));
	 strcat(name2,ruta1);
 	 strcat(name2,card->nombre);
	 strcat(name,origen);
	 strcat(name,card->nombre);
     rename(name,name2);
	}
  if (jugador==2) {
	 strcat(name2,ruta2);
  	 strcat(name2,card->nombre);
 	 strcat(name,origen);
 	 strcat(name,card->nombre);
	 rename(name,name2);
	}
 if (jugador==3) {
	 strcat(name2,ruta3);
 	 strcat(name2,card->nombre);
	 strcat(name,origen);
	 strcat(name,card->nombre);
	 rename(name,name2);
 	}
 if (jugador==4) {
	 strcat(name2,ruta4);
 	 strcat(name2,card->nombre);
	 strcat(name,origen);
	 strcat(name,card->nombre);
	 rename(name,name2);
 	}
 if (jugador==5) {
    strcat(name2,rutaUltima);
    strcat(name2,card->nombre);
    strcat(name,origen);
    strcat(name,card->nombre);
    rename(name,name2);
   }
	}

void MoverCarta(LinkedList* Mazo, int numero_carta,LinkedList* Jugador,int numero_jugador){
	LList_moveTo(Mazo,numero_carta);
	repartir(Cartaactual(Mazo),numero_jugador);
	LList_reLink(Jugador,Mazo);
    }
void Carta_borrado2(Carta card, int jugador){
		char name2[100]="";
		char ruta1[]= "/home/joaquin.concha/Escritorio/GIT/SO/Jugador 1/";
		char ruta2[]= "/home/joaquin.concha/Escritorio/GIT/SO/Jugador 2/";
		char ruta3[]= "/home/joaquin.concha/Escritorio/GIT/SO/Jugador 3/";
		char ruta4[]= "/home/joaquin.concha/Escritorio/GIT/SO/Jugador 4/";
	    if (jugador==1) {
	  	 strcat(name2,ruta1);
	  	 strcat(name2,strtok(card.nombre,"\n"));
	  	 remove(name2);
	  	}
		if (jugador==2) {
	  	 strcat(name2,ruta2);
	  	 strcat(name2,strtok(card.nombre,"\n"));
	  	 remove(name2);
	  	}
		if (jugador==3) {
	  	 strcat(name2,ruta3);
	  	 strcat(name2,strtok(card.nombre,"\n"));
	  	 remove(name2);
	  	}
		if (jugador==4) {
	  	 strcat(name2,ruta4);
	  	 strcat(name2,strtok(card.nombre,"\n"));
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
