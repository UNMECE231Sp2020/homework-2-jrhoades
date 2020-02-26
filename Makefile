FNS=con_fun.cpp
MAIN=main.cpp $(FNS)

all:
	g++ $(MAIN) -o make
clean:
	rm make
