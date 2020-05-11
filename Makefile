CompilerName = gcc
Object = main

all :
	${CompilerName} game.c cell.c arena.c main.c -o ${Object}

exec:
	./${Object}


dist:
	mkdir game && cp game.c main.c arena.c cell.c game.h arena.h cell.h game && tar -czvf game.tar.gz game && rm -rf game

clean:
	rm -rf ${Object}	