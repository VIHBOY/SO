# Tarea 1 SO UNO

_Primer Entregable de la tarea de Sistema Operativo_

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

## Notas 📦

_Se reparten Cartas a cada jugador, y por ultimo a ultima carta._
_De igual forma, se implemento con listas enlazadas, pensando en un futuro para un mejor manejo a la hora de jugar_

## Construido con 🛠️

* [Atom] - Editor de texto

## Autores ✒️

* **Joaquin Concha** - 201773569-4 *VIHBOY*
  _Funciones referentes a Cartas, main
    Carta new_Carta(char* c, char* n, char* t);
    void Carta_creado(Carta card);
    void Carta_print(Carta card) ;
    void Carta_borrado(Carta card);_
* **Renato Bassi** - 201773521-K *SIDABOY-bassisi*
  _Funciones referentes a listas, creacion_
