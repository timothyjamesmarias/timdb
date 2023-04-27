timdb: 
	gcc -ggdb -Wall -std=gnu99 -Wextra -pedantic timdb.c db.c -o timdb

clean:
	rm *.o timdb
