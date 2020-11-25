CC=gcc
OBJS=genral.o main.o NumberGame.o  PictureManipulation.o
EXEC=first
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

genral.o: genral.c genral.h
main.o: main.c PictureManipulation.h NumberGame.h
NumberGame.o: NumberGame.c NumberGame.h genral.h
PictureManipulation.o: PictureManipulation.c PictureManipulation.h genral.h

clean:
	rm -f $(EXEC) $(OBJS)	
