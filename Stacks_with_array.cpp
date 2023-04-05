#include <iostream>
#include <chrono>
using namespace std;
#define MAX 10

int top = -1;
int arr[MAX];

int isFull(){
    if(top == MAX-1){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top ==-1){
        return 1;
    }
    return 0;
}

void Push(int num){
    if (isFull()){
        cout << "Stack overflow" << endl;
        return ;
    }
    top +=1;
    arr[top] = num;
}

void Pop(){
    if(isEmpty()){
        cout<<"Stack underflow"<< endl;
        return;
    }
    top-=1;
}

void Display(){
    cout << "[" ;
    for(int i=0;i<top+1;i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void StackTop(){
    cout << arr[top]<< endl;
}

int main(){
    int n = 100;
    int avg_time = 0;
    for(int i=0;i<10;i++){
        top = -1;
        int arr[MAX];
        auto start = chrono::high_resolution_clock::now();
        Push(rand()%n);
        Push(rand()%n);
        Push(rand()%n);
        Push(rand()%n);
        Push(rand()%n);
        Push(rand()%n);
        Push(rand()%n);
        Push(rand()%n);
        Push(rand()%n);
        Push(rand()%n);
        Display();
        Pop(); 
        Pop();
        Pop();
        Pop();
        Pop();
        Display();
        Push(rand()%n);
        Push(rand()%n);
        Push(rand()%n);
        Push(rand()%n);
        Display();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "time taken " << duration.count() << " microseconds." << endl;
        avg_time +=duration.count();
    }
    cout << "Average time taken " <<avg_time /10 << " microseconds." << endl;
}