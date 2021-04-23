!/bin/bash
echo "RUNNING Experiment 1B"
valgrind="valgrind --tool=callgrind --simulate-cache=yes --branch-sim=yes -v"

./Experiment1B & 
./Experiment1B &
./Experiment1B & 
./Experiment1B &
./Experiment1B &

wait

./Experiment1B & 
./Experiment1B &
./Experiment1B & 
./Experiment1B &
./Experiment1B &

wait

$valgrind ./Experiment1B

echo "Ran Experiment 1B"
