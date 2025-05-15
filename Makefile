all:
	g++ -DMEMTRACE -Wall -Werror -pedantic *.cpp ./gates/*.cpp -o main

test:
	g++ -DMEMTRACE -Wall -Werror -pedantic *.cpp ./gates/*.cpp -o main

use:
	g++ -DMEMTRACE -DSIM -Wall -Werror -pedantic *.cpp ./gates/*.cpp -o main