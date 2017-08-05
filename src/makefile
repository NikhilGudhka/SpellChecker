CC=gcc
EXEC=spellchecker
CFLAGS= -Wall -ansi -pedantic
OBJ= dictionary.o user.o settings.o spellchecker.o callbackFunc.o check.o write.o

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

spellchecker.o: spellchecker.c dictionary.c dictionary.h user.c user.h settings.c settings.h callbackFunc.c callbackFunc.h check.c check.h write.c write.h
	$(CC) -c spellchecker.c dictionary.c user.c settings.c callbackFunc.c check.c write.c $(CFLAGS)

dictionary.o: dictionary.c dictionary.h
	$(CC) -c dictionary.c $(CFLAGS)

user.o: user.c user.h
	$(CC) -c user.c $(CFLAGS)

settings.o: settings.c settings.h
	$(CC) -c settings.c $(CFLAGS)

callbackFunc.o: callbackFunc.c callbackFunc.h
	$(CC) -c callbackFunc.c $(CFLAGS)

check.o: check.c check.h
	$(CC) -c check.c $(CFLAGS)

write.o: write.c write.h
	$(CC) -c write.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
