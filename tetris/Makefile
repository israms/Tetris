
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -I../graficos/include -I$(INC) -c
LDFLAGS = -Llib -L../graficos/lib  -lgraficos -lSDL -lSDL_gfx -lSDL_ttf -lfreetype

OBJETOS = $(OBJ)/tetris.o $(OBJ)/matriz.o $(OBJ)/pieza.o $(OBJ)/tablero.o $(OBJ)/imagen.o $(OBJ)/cola.o $(OBJ)/color.o $(OBJ)/visualizador.o $(OBJ)/vistexto.o $(OBJ)/vistab.o $(OBJ)/viscola.o

CABECERAS = $(INC)/matriz.h $(INC)/pieza.h $(INC)/tablero.h $(INC)/cola.h $(INC)/imagen.h $(INC)/color.h $(INC)/visualizador.h $(INC)/vistexto.h $(INC)/vistab.h $(INC)/viscola.h

# ************ Objetivos principales ************
all : tetris

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/matriz.o : $(SRC)/matriz.cpp $(INC)/matriz.h
	$(CXX) $(CPPFLAGS) $(SRC)/matriz.cpp -o $(OBJ)/matriz.o

$(OBJ)/pieza.o : $(SRC)/pieza.cpp $(INC)/pieza.h $(INC)/matriz.h
	$(CXX) $(CPPFLAGS) $(SRC)/pieza.cpp -o $(OBJ)/pieza.o

$(OBJ)/tablero.o : $(SRC)/tablero.cpp  $(INC)/tablero.h $(INC)/pieza.h $(INC)/matriz.h
	$(CXX) $(CPPFLAGS) $(SRC)/tablero.cpp -o $(OBJ)/tablero.o

$(OBJ)/cola.o : $(SRC)/cola.cpp  $(INC)/cola.h $(INC)/pieza.h
	$(CXX) $(CPPFLAGS) $(SRC)/cola.cpp -o $(OBJ)/cola.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) -c $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/color.o: $(SRC)/color.cpp $(INC)/color.h
	$(CXX) -c $(CPPFLAGS) $(SRC)/color.cpp -o $(OBJ)/color.o 

$(OBJ)/visualizador.o: $(SRC)/visualizador.cpp $(INC)/visualizador.h
	$(CXX) -c $(CPPFLAGS) $(SRC)/visualizador.cpp -o $(OBJ)/visualizador.o

$(OBJ)/vistexto.o: $(SRC)/vistexto.cpp $(INC)/vistexto.h
	$(CXX) -c $(CPPFLAGS) $(SRC)/vistexto.cpp -o $(OBJ)/vistexto.o

$(OBJ)/vistab.o: $(SRC)/vistab.cpp $(INC)/vistab.h
	$(CXX) -c $(CPPFLAGS) $(SRC)/vistab.cpp -o $(OBJ)/vistab.o

$(OBJ)/viscola.o: $(SRC)/viscola.cpp $(INC)/viscola.h
	$(CXX) -c $(CPPFLAGS) $(SRC)/viscola.cpp -o $(OBJ)/viscola.o

$(OBJ)/tetris.o : $(SRC)/tetris.cpp $(CABECERAS)
	$(CXX) $(CPPFLAGS) $(SRC)/tetris.cpp -o $(OBJ)/tetris.o

# ************ Enlazado y creación de ejecutables ************
tetris : $(BIN)/tetris
$(BIN)/tetris : $(OBJETOS)
	$(CXX) -o $(BIN)/tetris $(OBJETOS) $(LDFLAGS)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*