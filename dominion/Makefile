CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1:
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2:
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3:
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4:
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1:
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2:
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3:
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4:
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

utests: unittest1 unittest2 unittest3 unittest4

ctests: cardtest1 cardtest2 cardtest3 cardtest4

results: utests ctests
	unittest1 > unittestresults.out
	gcov unittest1 >> unittestresults.out
	unittest2 >> unittestresults.out
	gcov unittest2 >> unittestresults.out
	unittest3 >> unittestresults.out
	gcov unittest3 >> unittestresults.out
	unittest4 >> unittestresults.out
	gcov unittest4 >> unittestresults.out
	cardtest1 >> unittestresults.out
	gcov cardtest1 >> unittestresults.out
	cardtest2 >> unittestresults.out
	gcov cardtest2 >> unittestresults.out
	cardtest3 >> unittestresults.out
	gcov cardtest3 >> unittestresults.out
	cardtest4 >> unittestresults.out
	gcov cardtest4 >> unittestresults.out

all: playdom player results

dsm:
	rm -rf *.dSYM

rdm: 
	gcc ./randomtestadventurer.c dominion.c ./rngs.c -lm -g

clean: dsm
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a

