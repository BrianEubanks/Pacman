pacman: pacman.c
	gcc pacman.c gfx.c -o pacman -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
