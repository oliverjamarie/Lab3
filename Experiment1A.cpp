using namespace std;

#include <iostream>


#ifndef SIZE
#define SIZE 1000
#endif

int sumMethod1();
int sumMethod2();


int arr [SIZE][SIZE];

int main (){
    int sum = 0;

    for (int i = 0; i < SIZE; i ++){
        for(int j = 0; j < SIZE; j++){
            arr[i][j] = j;
        }
    }

    
    for (int i = 0; i < SIZE; i ++){
        for(int j = 0; j < SIZE; j++){
            sum+= arr[i][j];
        }
    }

    return 1;
}
