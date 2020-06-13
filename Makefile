CC=gcc

clean:
	rm *.o

build: tester.c queue.c baseline.c baseline_x2.c
	$(CC) tester.c queue.c baseline.c baseline_x2.c -o tester.o

run: build
	./tester.o