int n=0;
int n2=0;
printf("---------------------------\n");
printf("Cartas en Juego\n");
printf("---------------------------\n");
Carta_print(*Cartaactual(Ultima));
printf("---------------------------\n");
printf("Cartas en la mano\n");
printf("---------------------------\n");
LList_printAll2(J1,&n2,Ultima);
printf("---------------------------\n");
Carta_print(*Cartaactual(J1));
if (n2==0) {
  printf("Wacho no teni carta jugable\n" );
  Robar(Mazo,J1);
  LList_moveTo(J1,0);
}
else{
  printf("Ingrese carta a jugar: ");
  scanf("%d",&n );
  Carta_print(*Cartaactual(Ultima));
  LList_moveTo(J1,n)  ;
  Carta_print(*Cartaactual(J1));
  if (Esjugable(Cartaactual(J1),Cartaactual(Ultima))==1) {
    printf("%d\n",J1->size );
    printf("%d\n",J1->size );
    LList_moveTo(J1,0);
      }
  else{
    printf("No es Jugable\n");
    LList_moveTo(J1,0);
}}}*/
