CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp Administrador.cpp Arco.cpp Biblioteca_paquetes.cpp Computadora.cpp Conexion.cpp Etiqueta.cpp Pagina.cpp Paquete.cpp Router.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=final_AyED

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) *.o *.gch *.dot *.png

fullclean:
	rm -rf $(EXECUTABLE) *.o *.gch *.dot *.png *~
