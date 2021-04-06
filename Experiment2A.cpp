using namespace std;
#include <iostream>
#include <stdio.h>
#include <string.h> // necessary for memcpy
#include <cstdlib> // used to generate random numbers 
#include <time.h>


struct Node {
    int size;
    int *val;
    Node *next;
    
    Node(){
        next = NULL;
        val = NULL;
        size = 0;
    }

    Node (int *val_in, int size_in){
        size = size_in;
        val = new int[size_in];

        memcpy(val,val_in, size_in*sizeof(int));
    }

    void dispNode(){
        for(int i = 0; i < size; i ++){
            cout << val[i] << "\t";
        }

        cout << endl;
    }
};

struct List {
    Node *head;

    List(){
        head = NULL;
    }

    void push(int *val, int size){
        Node *temp;

        if (head == NULL){
            head = new Node(val, size);
            return;
        }

        temp = head;
        head = new Node(val,size);
        head->next = temp;
    }

    int retrieve(int i, int j){
        Node *curr = head;
        int count = 0;

        if (curr == NULL){
            return -1;
        }

        while(curr != NULL && (count < i || i == 0)){
            if (curr == NULL)
                return -1;
            if (count == i){
                
                if (curr->size >= j){
                    return curr->val[j];
                }
                return -2;
            }
            curr = curr->next;
            count ++;
        }

        return -3;              
    }

    void dispNode(int index){
        int i = 0;
        Node *curr = head;

        if (curr == NULL){
            return;
        }

        while(curr != NULL && (i < i || index == 0)){
            if (curr == NULL)
                return ;
            if (i == i){
                curr->dispNode();
            }
            curr = curr->next;
            i ++;
        }
    }
};

int main(){
    int arrLen = 100, numArrays = 1000000, maxNum = 100;
    int *arr;
    double cpu_time_used;
    clock_t start, end;
    List *list = new List();

    start = clock();

    srand(time(0));
    

    for (int i = 0; i < numArrays; i++){
        arr = new int[arrLen];
        
        for (int k = 0; k < 100; k++){
            arr[k] = rand()%maxNum;
        }

        list->push(arr, 100);
        
    }

    for (int i = 0; i < 500; i ++){
        for (int j = 0; j < 100; j++){
            list->retrieve(i,j);
        }
    }

    cout << "#1\n";

    for (int i = 0; i < 500; i ++){
        for (int j = 0; j < 100; j++){
            list->retrieve(rand()%numArrays, rand()%arrLen);
        }
    }

    cout << "#2\n";

    
    for (int i = 0; i < 2000000; i ++){
        arrLen = 1 + rand()%199;
        arr = new int[arrLen];

        for (int k = 0; k < arrLen; k++){
            arr[k] = rand()%maxNum;
        }

        list->push(arr,arrLen);
    }
    cout << "#3\n";
    for (int i = 0; i < 500000; i ++){
        
        list->retrieve(i,0);
    }

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

    cout << "DONE in \t" << cpu_time_used << "\t seconds or \t" << cpu_time_used / 60 << "\t minutes\n";
       
    return 1;
}