#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>    // time()
#define MAXSTRLEN 208
#define MAXWORD 3

typedef struct{
	char* color;
	char* numero;
	char* tipo;
	char* nombre;
}Carta;

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
typedef struct Element{
	Carta card;
	struct Element* next;
	struct Element* prev;
}Element;
Element new_Element(){
	Element elem;
	elem.next=NULL;
	elem.prev=NULL;
	return elem;
}
typedef struct{
	int index;
	int size;
	Element* curr;
	Element* head;
	Element* tail;
}LinkedList;
void LList_clear(LinkedList* list){
	Element* pnt=list->tail;
	int i,lim=list->size-1;
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
char* getcard(){
  char* color;
  char result[10];
  char Carta_final[30];
  char *Carta_final2= malloc(sizeof(char)*40);
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
      color=" Ama";
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
	return list->size--;
}
void LList_reLink(LinkedList* dest,LinkedList* from){
	Carta data=from->curr->card;
	LList_remove(from);
	LList_append(dest,data);
}

void repartir(Carta* card, int jugador) {
  char ruta1[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 1/";
  char ruta2[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 2/";
  char ruta3[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 3/";
  char ruta4[]= "/home/sida/Desktop/GIT/SO2/SO/Jugador 4/";
  char origen[]= "/home/sida/Desktop/GIT/SO2/SO/Mazo/";
	if (jugador==1) {
    rename(strcat(origen,card->nombre),strcat(ruta1,card->nombre));
  }
  }
int main ( int argc, char **argv )
{
 	FILE *fp;
	char arr[MAXWORD][MAXSTRLEN+1] = {0};
	int i=0;
 	char buffer[100];
	char delim[] = " ";
	char* pch;
 	fp = fopen ("Cartas.txt","r");
	LinkedList* Mazo=(LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* J1=(LinkedList*)malloc(sizeof(LinkedList));
	*Mazo=new_LList();
	*J1=new_LList();
  while (fgets(buffer, 100, fp) != NULL){
		pch = strtok (buffer," ");
		while (pch != NULL && i < MAXWORD)
    {strncpy(arr[i++], pch, MAXSTRLEN);pch = strtok (NULL, " ");}
		Carta* Cartita=(Carta*)malloc(sizeof(Carta));
		*Cartita = new_Carta(strtok(arr[2],"\n"),arr[1],arr[0]);
		LList_append(Mazo,*Cartita);
		i=0;free(Cartita);
	}
	repartir(Cartaactual(Mazo),1);
	LList_reLink(J1,Mazo);
	LList_printAll(J1);
	printf("------------------\n");
	LList_printAll(Mazo);
	LList_clear(Mazo);
	free(J1);
	free(Mazo);
 	fclose (fp);
return 0;
}
