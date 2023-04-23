db: cli.o 
	gcc cli.o -o db

cli.o: cli.c cli.h db.c db.h
	gcc -ggdb -Wall -std=gnu99 -Wextra -pedantic db.c cli.c -c

clean:
	rm *.o db
