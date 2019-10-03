G = g++
CFLAGS = -Wall \
		 -g \
		 -Werror \
		 -ansi \
		 -pedantic \
		 -std=c++11 \
		 
EXE = main
OFILES = Main.o \
		 TrajetCompose.o \
		 Catalogue.o \
		 Collection.o \
		 Menu.o \
		 Trajet.o \
		 TrajetSimple.o \

all: $(EXE)

clean:
	rm $(EXE) *.o

$(EXE): $(OFILES)
	$(G) $(CFLAGS) -o $(EXE) $(OFILES) -D MAP

Catalogue.o: Catalogue.cpp Catalogue.h Trajet.h TrajetCompose.h TrajetSimple.h Collection.h
	$(G) $(CFLAGS) -c Catalogue.cpp -o Catalogue.o

Collection.o: Collection.cpp Collection.h Trajet.h
	$(G) $(CFLAGS) -c Collection.cpp -o Collection.o

Main.o: Main.cpp Catalogue.h
	$(G) $(CFLAGS) -c Main.cpp -o Main.o

Trajet.o: Trajet.cpp Trajet.h
	$(G) $(CFLAGS) -c Trajet.cpp -o Trajet.o

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Trajet.h
	$(G) $(CFLAGS) -c TrajetCompose.cpp -o TrajetCompose.o

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h Trajet.h
	$(G) $(CFLAGS) -c TrajetSimple.cpp -o TrajetSimple.o