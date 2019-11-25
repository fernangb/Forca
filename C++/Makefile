CPP = g++
CPPFLAGS = -Wall -std=c++11 -I/usr/lib/x86_64-linux-gnu/perl/5.26.1/CORE/
#CPPFLAGS = $(shell -I/usr/lib/x86_64-linux-gnu/perl/5.26/CORE/)
LD = g++
#LDLIBS = -I//Documents/LingProg/Trabalho/Forca/C++ LingProg - GabrielFernandes/modulo.pm
LDFLAGS = -lm #-lperl #-lm
#LDFLAGS = $(shell -lperl -lm)

all: main

.cpp.o:
	$(CPP) $(CPPFLAGS) -o $@ -c $<

main: Main.o Jogo.o Jogador.o Palavra.o Arquivo.o #arquivo.o #perl_cpp.o
	$(LD) -o $@ $? $(LDFLAGS)

clean:
	rm -f main *.o


#g++ -L/usr/lib/x86_64-linux-gnu/libperl.so.5.26/ -I/usr/lib/x86_64-linux-gnu/perl/5.26.1/CORE/ -o main main.cpp perltocpp.cpp -lperl -lm
#g++ -o main  main.cpp perltocpp.cpp `perl -MExUtils::Embed -e ccopts -e ldopts`

