G = g++
CFLAGS = -Wall \
		 -g \
		 -Werror \
		 -ansi \
		 -pedantic \
		 -std=c++11 \
		 
EXE = main
OFILES = Main.o \
		 Catalogue.o \
		 Trajet.o \
		 TrajetSimple.o \
		 TrajetCompose.o \

all: $(EXE)

clean:
	rm $(EXE) *.o

$(EXE): $(OFILES)
	$(G) $(CFLAGS) -o $(EXE) $(OFILES)

Caalogue.o: Catalogue.cpp Catalogue.h Trajet.h TrajetCompose.h TrajetSimple.h
	$(G) $(CFLAGS) -c Catalogue.cpp

Main.o: Main.cpp Catalogue.h
	$(G) $(CFLAGS) -c Main.cpp

Trajet.o: Trajet.cpp Trajet.h
	$(G) $(CFLAGS) -c Trajet.cpp

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Trajet.h
	$(G) $(CFLAGS) -c TrajetCompose.cpp

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h Trajet.h
	$(G) $(CFLAGS) -c TrajetSimple.cpp