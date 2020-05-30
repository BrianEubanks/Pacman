pacman: pacman.c
	gcc pacman.c game.c gfx.c data.c screen.c -o pacman -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
