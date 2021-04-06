all: Experiment1A.o Experiment1B.o Experiment2A.o
	g++ Experiment1A.o -o outExp1A
	g++ Experiment1B.o -o outExp1B
	g++ Experiment2A.o -o outExp2A


Experiment1A.o: Experiment1A.cpp
	g++ -c Experiment1A.cpp -o Experiment1A.o

Experiment1B.o: Experiment1B.cpp
	g++ -c Experiment1B.cpp -o Experiment1B.o

Experiment2A.o: Experiment2A.cpp
	g++ -c Experiment2A.cpp -o Experiment2A.o

BigClean:
	rm *.o outExp1A outExp1B outExp2A callgrind.*.*

clean:
	rm *.o outExp1A outExp1B outExp2A


#valgrind --tool=callgrind ./outExp1A
#valgrind --tool=callgrind --simulate-cache=yes ./outExp1B
