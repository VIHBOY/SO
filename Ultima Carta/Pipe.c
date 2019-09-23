#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[]) {
      int fd[2];
      pid_t pidC;
      int num;
      pipe(fd);
      char buf[20];
      pidC=fork();
      switch (pidC) {
        case 0: /*Hijo */
          close(fd[0]);
          write(fd[1],"Hola culiao",11);
          close(fd[1]);
          exit(0);
          break;
        case -1:
          break;
        default: /*Padre*/
          close(fd[1]);
          num=read(fd[0],buf,20);
          printf("%d %s\n",num,buf);
          close(fd[0]);
          break;
      }
  return 0;
}
