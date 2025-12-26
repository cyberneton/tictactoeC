# Compile file (linux)

build: 
	gcc ./tictactoe.c -o tictactoe
run: build
	./tictactoe
clean: 
	rm tictactoe
