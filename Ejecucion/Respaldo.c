/*fclose(fp);
int count;
int pid, pid1, pid2,fd12[2],fd23[2],fd34[2],fd41[2],fd122[2],fd232[2],fd342[2],fd412[2];
char    readbuffer[80];
pipe(fd12);pipe(fd23);pipe(fd34);pipe(fd41),pipe(fd13);pipe(fd24);
char turno[3] ="M1";
char *arr2[8];
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
        close(fd23[1]);
        read(fd23[0], readbuffer, sizeof(readbuffer));
        char *p=strtok (readbuffer, " ");
        while (p != NULL){
          arr2[i2++] = p;
          p = strtok (NULL," ");
      }
      strcpy(turno,arr2[0]);
      if (strcmp(arr2[1],"-1")!=0) {
        printf("ddd\n" );
        LList_Actualizacion(Mazo,arr2[1],arr2[2],arr2[3]);
      };
      if (strcmp(arr2[4],"-1")!=0 && strcmp(arr2[5],"-1")!=0 && strcmp(arr2[6],"-1")!=0) {
        Carta* Cartita=(Carta*)malloc(sizeof(Carta));
        *Cartita = new_Carta(arr2[5],arr2[6],arr2[4]);
        LList_remove(Ultima);
        LList_append(Ultima,*Cartita);
        free(Cartita);
      }
        turno2(Mazo,J4,Ultima,turno,fd34);
        }
    LList_clear(J4);
    free(J4);
}
else {
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
            close(fd12[1]);
            read(fd12[0], readbuffer, sizeof(readbuffer));
            char *p=strtok (readbuffer, " ");
            while (p != NULL){
              arr2[i2++] = p;
              p = strtok (NULL," ");
          }
          strcpy(turno,arr2[0]);
          if (strcmp(arr2[1],"-1")!=0) {
+              LList_Actualizacion(Mazo,arr2[1],arr2[2],arr2[3]);
          };
          if (strcmp(arr2[4],"-1")!=0 && strcmp(arr2[5],"-1")!=0 && strcmp(arr2[6],"-1")!=0) {
            Carta* Cartita=(Carta*)malloc(sizeof(Carta));
            *Cartita = new_Carta(arr2[5],arr2[6],arr2[4]);
            LList_remove(Ultima);
            LList_append(Ultima,*Cartita);
            free(Cartita);
          }
            turno2(Mazo,J2,Ultima,turno,fd23);
          }
        LList_clear(J2);
        free(J2);
    }
    else {
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
                if (f!=0) {
                  close(fd41[1]);
                  read(fd41[0], readbuffer, sizeof(readbuffer));
                  char *p=strtok (readbuffer, " ");
                  while (p != NULL){
                    arr2[i2++] = p;
                    p = strtok (NULL," ");
                }
                strcpy(turno,arr2[0]);
                if (strcmp(arr2[1],"-1")!=0) {
                  LList_Actualizacion(Mazo,arr2[1],arr2[2],arr2[3]);
                }
                if (strcmp(arr2[4],"-1")!=0 && strcmp(arr2[5],"-1")!=0 && strcmp(arr2[6],"-1")!=0) {
                  Carta* Cartita=(Carta*)malloc(sizeof(Carta));
                  *Cartita = new_Carta(arr2[5],arr2[6],arr2[4]);
                  LList_remove(Ultima);
                  LList_append(Ultima,*Cartita);
                  free(Cartita);
                }
                }
                f++;
                turno2(Mazo,J1,Ultima,turno,fd12);
              }
          LList_clear(J1);
          free(J1);
        }
        else {
}              sleep(3);
            LinkedList* J4=(LinkedList*)malloc(sizeof(LinkedList));
            *J4=new_LList(4);
            for ( count = 0; count < 2; count++) {
              Robar(Mazo,J4);}
              while (strcmp(Juego_terminado,"1")==0 && J4->size>0)  {
                int i2=0;
                close(fd34[1]);
                read(fd34[0], readbuffer, sizeof(readbuffer));
                char *p=strtok (readbuffer, " ");
                while (p != NULL){
                  arr2[i2++] = p;
                  p = strtok (NULL," ");
              }
              strcpy(turno,arr2[0]);
              if (strcmp(arr2[1],"-1")!=0) {
                printf("ddd\n" );
                LList_Actualizacion(Mazo,arr2[1],arr2[2],arr2[3]);
              }
              if (strcmp(arr2[4],"-1")!=0 && strcmp(arr2[5],"-1")!=0 && strcmp(arr2[6],"-1")!=0) {
                Carta* Cartita=(Carta*)malloc(sizeof(Carta));
                *Cartita = new_Carta(arr2[5],arr2[6],arr2[4]);
                LList_remove(Ultima);
                LList_append(Ultima,*Cartita);
                free(Cartita);
              }
                turno2(Mazo,J4,Ultima,turno,fd41);
                }
            LList_clear(J4);
            free(J4);
        }
    }
}*/
