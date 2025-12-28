#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node() : val(0), next(nullptr){};
    Node(int x) : val(x), next(nullptr){};
    Node(int x, Node* p) : val(x), next(p){};
};
struct Queue{
    Node* head;
    Node* tail;
    int capacity;
    Queue(){
        head = nullptr;
        tail = nullptr;
        capacity = 0;
    }
    ~Queue(){
        empty();
    }
    bool enqueue(int x){
        if(!tail || !head){
            head = new Node(x);
            tail = head;
            capacity++;
            return true;
        }
        tail->next = new Node(x);
        tail = tail->next;
        capacity++;
        return true;
    }
    bool dequeue(int &x){
        if(!head && !tail) return false;
        Node* tmp = head;
        x = tmp->val;
        head = head->next;
        if(!head) tail = nullptr;
        delete tmp;
        capacity--;
        return true;
    }
    bool isEmpty(){
        return capacity == 0;
    }
    void empty(){
        Node* tmp = head;
        while(tmp){
            head = head->next;
            delete tmp;
            tmp = head;
        }
        tail = nullptr;
        head = nullptr;
        capacity = 0;
    }
    int size(){
        return capacity;
    }
};