prog:main.o enemy.o collisionBB.o
	gcc main.o enemy.o collisionBB.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -g
enemy.o:enemy.c
	gcc -c enemy.c -g
collisionBB.o:collisionBB.c
	gcc -c collisionBB.c -g

