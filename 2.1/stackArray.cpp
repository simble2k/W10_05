#include <iostream>
using namespace std;
struct Stack{
        int* data;
        int top;
        int capacity;
        void init(int x){
            capacity = x;
            top = -1;
            data = new int[capacity];
        }
        ~Stack(){
            delete[] data;
        }
        void resize(){
            capacity *= 2;
            int* newList = new int[capacity];
            for(int i = 0; i < top + 1; i++){
                newList[i] = data[i];
            }
            delete[] data;
            data = newList;
        }
        bool push(int x){
            if(top == capacity - 1) resize();
            data[++top] = x;
            return true;
        }
        bool pop(int &x){
            if(top < 0) return false;
            x = data[top];
            top--;
            return true;
        }
        bool isEmpty(){
            return top == -1;
        }
        void empty(){
            top = -1;
        }
        int size(){
            return top + 1;
        }

};