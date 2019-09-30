CC = gcc
DEBUG = -g
CFLAGS = -Wall $(DEBUG)
LDFLAGS = -Wall $(DEBUG)
EXEC = Creacion_Cartas
OBJS = Creacion_Cartas.o lista.o
all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(EXEC)
Creacion_Cartas.o: Creacion_Cartas.c
	$(CC) $(CFLAGS) -c Creacion_Cartas.c
lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c
clean:
	find . -name ’*.o’ -type f -delete
	rm -f $(EXEC) $(OBJS)
