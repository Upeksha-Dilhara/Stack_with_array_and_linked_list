#include <iostream>
#include <chrono>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    void Push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    int Pop() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    void Display() {
        Node* p = top;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }
};

int main() {
    int n = 100;
    int avg_time = 0;

    for(int i=0;i<10;i++){
        Stack s;
        auto start = chrono::high_resolution_clock::now();
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Display();
        s.Pop(); 
        s.Pop();
        s.Pop();
        s.Pop();
        s.Pop();
        s.Display();
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Push(rand()%n);
        s.Display();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "time taken " << duration.count() << " microseconds." << endl;
        avg_time +=duration.count();
    }
    cout << "Average time taken " <<avg_time /10 << " microseconds." << endl;
    return 0;
}
