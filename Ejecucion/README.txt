---------------------------------------
-Joaquin Concha 201773569-4           -
-Renato Bassi   201773521-k           -
------------------------------------------------
Documentacion Tarea1 SISTEMAS OPERATIVOS -
------------------------------------------------
Saludos, a continuación presentaremos algunas consideraciones que tomamos
y explicaremos como hicimos algunas funciones.

*Se debe abrir una terminal en la carpeta "Ejecucion", y luego se debe ejecutar make.

*Para crear las cartas y repartirlas, se debe ejecutar en la terminal el comando "./Creacion_Cartas".

*Para borrar todo y dejar la carpeta con los archivos por defecto, primero se debe ejecutar "./Eliminar", y luego "make clean".

*Se agregan varios textos que explican cada accion.
-----------------------------------------------------------------------------------------------
*Carta new_Carta(char* c, char* n, char* t);
*void Carta_creado(Carta card);
*void Carta_print(Carta card) ;
*void Carta_borrado(Carta card);
*Element new_Element();
*void LList_clear(LinkedList* list);
*LinkedList new_LList();
*void LList_printAll(LinkedList* list);
*Carta* Cartaactual(LinkedList* list);
*void Llist_makedir(LinkedList* list);
*void Llist_deletedir(LinkedList* list);
*int LList_append(LinkedList* list,Carta card);
*int LList_moveTo(LinkedList* list,int pos);
*int LList_remove(LinkedList* list);
*void LList_reLink(LinkedList* dest,LinkedList* from);
*void repartir(Carta* card, int jugador) ;
*void MoverCarta(LinkedList* Mazo, int numero_carta,LinkedList* Jugador,int numero_jugador);
*void Carta_borrado2(Carta card, int jugador );
*void Llist_deletedir2(LinkedList* list, int njugador);
*int crearCarpeta(const char *dir, const mode_t mode);
-------------------------------------------------------------------------------------------------

Disclaimer: En el presente documento se han omitido intencionalmente los tildes, para no tener problemas de compatibilidad con cualquier editor de textos.
