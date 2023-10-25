dungeon_crawlers: main.o
	gcc -o dungeon_crawlers main.o

main.o: main.c
	gcc -c main.c

clean:
	del *.o

all: dungeon_crawlers
	dungeon_crawlers.exe
	make clean
