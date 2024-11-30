output = main
include = -I./include

main: init objet/merge.o objet/quick.o objet/insert.o objet/tas.o objet/introsort.o objet/selection.o objet/bubble.o objet/bogo.o objet/comb.o objet/main.o objet/function.o
	gcc -o bin/$(output) objet/*.o -Wall $(include)

init:
	mkdir -p objet/
	mkdir -p bin/

objet/main.o: src/main.c
	gcc -o objet/main.o src/main.c -c -Wall $(include)

objet/merge.o: src/merge.c
	gcc -o objet/merge.o src/merge.c -c -Wall $(include)

objet/quick.o: src/quick.c
	gcc -o objet/quick.o src/quick.c -c -Wall $(include)

objet/insert.o: src/insert.c
	gcc -o objet/insert.o src/insert.c -c -Wall $(include)

objet/tas.o: src/tas.c
	gcc -o objet/tas.o src/tas.c -c -Wall $(include)

objet/introsort.o: src/introsort.c
	gcc -o objet/introsort.o src/introsort.c -c -Wall $(include)

objet/selection.o: src/selection.c
	gcc -o objet/selection.o src/selection.c -c -Wall $(include)

objet/bubble.o: src/bubble.c
	gcc -o objet/bubble.o src/bubble.c -c -Wall $(include)

objet/bogo.o: src/bogo.c
	gcc -o objet/bogo.o src/bogo.c -c -Wall $(include)

objet/comb.o: src/comb.c
	gcc -o objet/comb.o src/comb.c -c -Wall $(include)

objet/function.o: src/function.c
	gcc -o objet/function.o src/function.c -c -Wall $(include)

run: main
	./bin/$(output)

valgrind: main
	valgrind ./bin/$(output)

clear:
	rm -rf objet/
	rm -f bin/*