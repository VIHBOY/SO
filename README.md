# Tarea 1 SO UNO

_Segundo Entregable de la tarea de Sistema Operativo_

## Comenzando 🚀

_Estas instrucciones te permitirán obtener una copia del proyecto en funcionamiento en tu máquina local para propósitos de desarrollo y pruebas._

### Pre-requisitos 📋

_Que cosas necesitas para instalar el software y como instalarlas_

```
Se debe tener instalado git en la maquina en la cual se probara.
```

### Instalación 🔧

_Se debe seguir estos pasos para poder ejecutar la tarea_

```
git clone https://github.com/VIHBOY/SO
cd SO
cd Ejecucion
make
```
## Ejecutando las pruebas ⚙️

```
./Creacion_Cartas
```
_Se crearan carpetas para cada jugardor en la raiz de SO, además de carpetas para mazo y ultima carta_

_Con el jugador 1, se pondra a prueba la implementación de reglas y condiciones de termino_

## Notas 📦

_Se reparten Cartas a cada jugador, y por ultimo a ultima carta._

_De igual forma, se implemento con listas enlazadas, pensando en un futuro para un mejor manejo a la hora de jugar_

-La carpeta OLD tiene respaldado el trabajo anterior.

## Construido con 🛠️

* [Atom] - Editor de texto

## Autores ✒️

* **Joaquin Concha** - 201773569-4 *VIHBOY*
   -_Funciones referentes a Cartas, main_
   
        -Carta new_Carta(char* c, char* n, char* t);    
        -void Carta_creado(Carta card);   
        -Carta* Cartaactual(LinkedList* list);    
        -void Carta_print(Carta card) ;  
        -void Carta_borrado(Carta card);  
        -void repartir(Carta* card, int jugador);    
        -void MoverCarta(LinkedList* Mazo, int numero_carta,LinkedList* Jugador,int numero_jugador);  
        -void Carta_borrado2(Carta card, int jugador );  
        -void Llist_deletedir2(LinkedList* list, int njugador);    
        -int crearCarpeta(const char *dir, const mode_t mode);
        -int Esjugable(Carta* Jugada, Carta* Ultima);
        -int Efecto(Carta Ultima);
        -void Robar(LinkedList* Mazo,LinkedList* Jugador);
* **Renato Bassi** - 201773521-K *SIDABOY-bassisi*
  -_Funciones referentes a listas, creacion_  
  
        -Element new_Element();  
        -void LList_clear(LinkedList* list);  
        -LinkedList new_LList();  
        -void LList_printAll(LinkedList* list);    
        -void Llist_makedir(LinkedList* list);  
        -void Llist_deletedir(LinkedList* list);  
        -int LList_append(LinkedList* list,Carta card);  
        -int LList_moveTo(LinkedList* list,int pos);  
        -int LList_remove(LinkedList* list);  
        -void LList_reLink(LinkedList* dest,LinkedList* from);
        -void JugarCarta(LinkedList* Mano,LinkedList* Ultima);
        -void Jugar(Carta* card);
