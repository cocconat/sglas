CC= g++
CFLAGS= -I -std=c++11
make:
	$(CC) -o sglas main.cpp reticle.cpp montecarlo.cpp $(CFLAGS) 
debug:
	$(CC) -o sglas main.cpp reticle.cpp montecarlo.cpp $(CFLAGS) -DDEBUG=$(DEBUG)
clean:
	rm *.o


