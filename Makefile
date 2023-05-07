timdb: 
	gcc -ggdb -Wall -std=gnu99 -Wextra -pedantic timdb.c -o timdb

clean:
	rm *.o timdb
