using namespace std;

#include <iostream>
#include <time.h>

#ifndef SIZE
#define SIZE 1000
#endif

int sumMethod1();
int sumMethod2();


int arr [SIZE][SIZE];

int main (){
    int sum = 0;

    clock_t start, end ;
    double cpuTime;

    start = clock();

    for (int i = 0; i < SIZE; i ++){
        for(int j = 0; j < SIZE; j++){
            arr[i][j] = j;
        }
    }

    for (int j = 0; j < SIZE; j ++){
        for(int i = 0; i < SIZE; i++){
            sum+= arr[i][j];
        }
    }


    end = clock();

    cpuTime = ((double) (end-start)) / CLOCKS_PER_SEC;

    cout << "DONE in \t" << cpuTime << "\t seconds or \t" << cpuTime / 60 << "\t minutes\n";
   
    return 0;
}

