output = main
include = -I./include -lm -fopenmp -g -ggdb

main: init objet/main.o objet/function.o
	gcc -o bin/$(output) objet/*.o -Wall $(include)

adventofcode: objet/adventofcode/HistorianHysteria.o
	gcc -o bin/adventofcode/HistorianHysteria objet/adventofcode/HistorianHysteria.o objet/function.o -Wall $(include)

sort: init objet/sort/merge.o objet/sort/quick.o objet/sort/insertion.o objet/sort/heap.o objet/sort/introsort.o objet/sort/selection.o objet/sort/bubble.o objet/sort/bogo.o objet/sort/comb.o objet/sort/test_sort.o objet/function.o
	gcc -o bin/sort/sort objet/sort/*.o objet/function.o -Wall $(include)

init:
	mkdir -p objet/sort
	mkdir -p objet/adventofcode
	mkdir -p bin/sort
	mkdir -p bin/adventofcode

objet/main.o: src/main.c
	gcc -o objet/main.o src/main.c -c -Wall $(include)

objet/adventofcode/HistorianHysteria.o: src/adventofcode/HistorianHysteria.c
	gcc -o objet/adventofcode/HistorianHysteria.o src/adventofcode/HistorianHysteria.c -c -Wall $(include)

objet/sort/test_sort.o: src/sort/test_sort.c
	gcc -o objet/sort/test_sort.o src/sort/test_sort.c -c -Wall $(include)

objet/sort/merge.o: src/sort/merge.c
	gcc -o objet/sort/merge.o src/sort/merge.c -c -Wall $(include)

objet/sort/quick.o: src/sort/quick.c
	gcc -o objet/sort/quick.o src/sort/quick.c -c -Wall $(include)

objet/sort/insertion.o: src/sort/insertion.c
	gcc -o objet/sort/insertion.o src/sort/insertion.c -c -Wall $(include)

objet/sort/heap.o: src/sort/heap.c
	gcc -o objet/sort/heap.o src/sort/heap.c -c -Wall $(include)

objet/sort/introsort.o: src/sort/introsort.c
	gcc -o objet/sort/introsort.o src/sort/introsort.c -c -Wall $(include)

objet/sort/selection.o: src/sort/selection.c
	gcc -o objet/sort/selection.o src/sort/selection.c -c -Wall $(include)

objet/sort/bubble.o: src/sort/bubble.c
	gcc -o objet/sort/bubble.o src/sort/bubble.c -c -Wall $(include)

objet/sort/bogo.o: src/sort/bogo.c
	gcc -o objet/sort/bogo.o src/sort/bogo.c -c -Wall $(include)

objet/sort/comb.o: src/sort/comb.c
	gcc -o objet/sort/comb.o src/sort/comb.c -c -Wall $(include)

objet/function.o: src/function.c
	gcc -o objet/function.o src/function.c -c -Wall $(include)

gdb:
	gdb ./bin/$(output)

run: main
	./bin/$(output)

valgrind: main
	valgrind ./bin/$(output)

clear:
	rm -rf objet/
	rm -rf bin/*