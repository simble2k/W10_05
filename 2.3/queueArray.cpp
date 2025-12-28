#include <iostream>
using namespace std;

struct Queue{
    int *data;
    int in;
    int out;
    int capacity;
    Queue(int x = 10){
        init(x);
    }
    void init(int x){
        capacity = x;
        data = new int[capacity];
        in = 0;
        out = 0;
    }
    ~Queue(){
        if(data) delete[] data;
    }
    void resize(){
        capacity *= 2;
        int *newlist = new int[capacity];
        for(int i = 0; i < in-out; i++){
            newlist[i] = data[out+i];
        }
        in = in - out;
        out = 0;
        delete[] data;
        data = newlist;
    }
    bool enqueue(int x){
        if(in == capacity) resize();
        data[in] = x;
        in++;
        return true;
    }
    bool dequeue(int &x){
        if(in == out) return false;
        x = data[out];
        out++;
        return true;
    }
    bool isEmpty(){
        return in == out;
    }
    void empty(){
        in = 0;
        out = 0;
    }
    int size(){
        return in - out;
    }
};