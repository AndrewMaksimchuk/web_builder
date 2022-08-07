default: clear
	gcc -std=c99 src/main.c && ./a.out ./project

build:
	gcc -std=c99 src/main.c && ./a.out ./project

clear:
	rm -r dist