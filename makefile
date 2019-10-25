sudoku: main.o sudoku.o
	g++ main.o sudoku.o -o sudoku
	echo "Done."

main.o: main.cpp sudoku.h
	g++ -Wall -g -c main.cpp -o main.o
	echo "main.o correctly produced."

sudoku.o: sudoku.cpp sudoku.h
	g++ -Wall -g -c sudoku.cpp -o sudoku.o
	echo "sudoku.o correctly produced."

clean:
	rm -f *.o sudoku

.PHONY: clean
