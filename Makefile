CALLGRIND = valgrind --tool=callgrind --simulate-cache=yes -v

all: Dockerfile Experiment1A.cpp Experiment1B.cpp Experiment2A.cpp 
	docker build -t lab3:latest .

runExp1A: 
	docker run -ti -v $PWD lab3:latest bash -c " $(CALLGRIND) ./Experiment1A"

runExp1B:
	docker run -ti -v $PWD lab3:latest bash -c " $(CALLGRIND) ./Experiment1B"

runExp2A:
	docker run -ti -v $PWD lab3:latest bash -c " $(CALLGRIND) ./Experiment2A"

runExp2B:
	docker run -ti -v $PWD lab3:latest bash -c " $(CALLGRIND) ./Experiment2B"
	
# docker run --rm -it lab3:latest 
#valgrind --tool=callgrind ./outExp1A
#valgrind --tool=callgrind --simulate-cache=yes ./outExp1B
