using namespace std;

#include <iostream>
#include <string.h>
#include <unistd.h>

struct Node {
    int index, next, size;
    int *arr;

    Node(){
        index = 0;
        next = 0;
        size = 0;
        arr = NULL;
    }

    void appendArray (int *arr_in, int size_in){
        if (arr != NULL)
            return;
        
        size = size_in;
        arr = new int[size];
        memcpy(arr, arr_in, size*sizeof(int));

    }

    int getArrElement(int index){
        if (arr == NULL){
            cout << "arr is NULL";
            return -1;
        }
            
        if (index > size)
            return arr[0];
        
        return arr[index];
    }
};

struct List{
    Node *block;
    int head, maxNumNodes;

    List(){
        maxNumNodes = 100000000 / sizeof(Node*);
        head = -1;
        block = new Node[maxNumNodes];
    }

    
    void push(int* arr, int size){ // Adds a node to the linked list

        if (head == -1){
            head = 0;
            block[head].appendArray(arr,size);
            block[head].next = -1;
            return;
        }

        if (head == maxNumNodes){
            return;
        }

        head ++;
        block[head].appendArray(arr,size);
        block[head].next = head -1;
    }

    int retreive (int nodeIndex, int arrIndex){
        if (nodeIndex > head)
            return -1;

        return block[nodeIndex].getArrElement(arrIndex);
    }
};

int main(){
    List list;
    int arrSize = 100;
    int *arr = new int [arrSize];
    int exp = 1;
    clock_t start, end ;
    double cpuTime;

    start = clock();
    srand(time(NULL));

    for (int i = 0; i <  arrSize; i++){
        arr[i] = i;
    }

    for (int i = 0; i < 1000000; i++){
        list.push(arr, arrSize);
    }
    
    delete [] arr;

    //cout << list.head << endl;
    
    for (int i = 0; i < 500; i ++){
        for (int j = 0; j < 100; j ++){
            // cout << "i:" << i << "\tj: "<< j << '\t' << list.retreive(i,j) << endl;
            list.retreive(i,j) ;
        }
    }

    //cout << "a Done\n"; 
    int randNodeIndex, randArrIndex, randInt;

    for (int i = 0; i < 500000; i ++){
        randNodeIndex = rand() % list.head; // list.head can be used as a reference for the number of nodes in the list
        randArrIndex = rand() % arrSize;

        list.retreive(randNodeIndex, randArrIndex);

        
    }

    //cout << "b Done\n"; 

    arrSize = 200;
    for (int i = 0; i < 20000000; i++){
        randArrIndex = rand() % arrSize;
        arr = new int[randArrIndex];

        for (int j = 0; j < randArrIndex; j ++){
            randInt = rand() % arrSize;

            arr[j] = randInt; 
        }
        list.push(arr,randArrIndex);
        delete [] arr;
    }

    //cout << "c1 Done\n"; 

    for (int i = 0; i < 500000; i ++){
        randNodeIndex = rand() % list.head; // list.head can be used as a reference for the number of nodes in the list
        randArrIndex = rand() % arrSize;

        list.retreive(randNodeIndex, randArrIndex);
    }
    
    //cout << "c2 Done\n"; 

    end = clock();

    cpuTime = ((double) (end-start)) / CLOCKS_PER_SEC;

    cout << "DONE in \t" << cpuTime << "\t seconds or \t" << cpuTime / 60 << "\t minutes\n";
    return 0;
}