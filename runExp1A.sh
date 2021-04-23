echo "RUNNING Experiment 1A"
callgrind="valgrind --tool=callgrind --simulate-cache=yes --branch-sim=yes -v"
cachegrind="valgrind --tool=cachegrind  --branch-sim=yes -v"

./Experiment1A & 
./Experiment1A &
./Experiment1A & 
./Experiment1A &
./Experiment1A &

wait

./Experiment1A & 
./Experiment1A &
./Experiment1A & 
./Experiment1A &
./Experiment1A &

wait

$callgrind ./Experiment1A

echo "Ran Experiment 1A"
