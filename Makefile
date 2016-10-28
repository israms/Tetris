# Makefile Superior

all:
# Hace make de graficos
	make -C graficos
#Hace make de tetris
	make -C tetris	
clean:
# Hace clean de tetris
	make -C tetris clean
# Hace clean de graficos
	make -C graficos clean
mrproper: 
# Hace mrproper de tetris
	make -C tetris mrproper
# Hace mrproper de graficos
	make -C graficos mrproper
documentacion: 
# Hace documentacion de tetris
	make -C tetris documentacion
# Hace documentacion de graficos
	make -C graficos documentacion
