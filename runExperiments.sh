echo "" > Output/Out1A.txt
echo "" > Output/Out1B.txt
echo "" > Output/Out2A.txt
echo "" > Output/Out2B.txt

./runExp1A.sh &
wait 

./runExp1B.sh &
wait 

./runExp2A.sh &
wait 

./runExp2B.sh &
wait 