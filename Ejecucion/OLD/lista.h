#ifndef _LISTA_H_INCLUDED_
#define _LISTA_H_INCLUDED_


typedef struct{
	char* color;
	char* numero;
	char* tipo;
	char* nombre;
}Carta;

typedef struct Element{
	Carta card;
	struct Element* next;
	struct Element* prev;
}Element;

typedef struct{
	int index;
	int size;
	int jugador;
	Element* curr;
	Element* head;
	Element* tail;
}LinkedList;
void LList_next(LinkedList* list);
int Esjugable(Carta* Jugada, Carta* Ultima);
Carta new_Carta(char* c, char* n, char* t);
void Carta_creado(Carta card);
void Carta_print(Carta card) ;
void Carta_borrado(Carta card);
Element new_Element();
void LList_clear(LinkedList* list);
LinkedList new_LList();
void LList_printAll(LinkedList* list);
Carta* Cartaactual(LinkedList* list);
void Llist_makedir(LinkedList* list);
void Llist_deletedir(LinkedList* list);
int LList_append(LinkedList* list,Carta card);
void LList_printAll2(LinkedList* list, int* n, LinkedList* Ultima);
int LList_moveTo(LinkedList* list,int pos);
int LList_remove(LinkedList* list);
void LList_reLink(LinkedList* dest,LinkedList* from);
void repartir(Carta* card, int jugador) ;
void Robar(LinkedList* Mazo,LinkedList* Jugador);
void Carta_borrado2(Carta card, int jugador );
void Llist_deletedir2(LinkedList* list, int njugador);
int crearCarpeta(const char *dir, const mode_t mode);
void JugarCarta(LinkedList* Mano,LinkedList* Ultima);
void Jugar(Carta* card);
#endif
