#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node() : val(), next(nullptr){};
    Node(int x): val(x), next(nullptr){};
    Node(int x, Node* p) : val(x), next(p){};
};
struct Stack{
    Node* head;
    int capacity;
    Stack() {
        head = nullptr;
        capacity = 0;
    }
    ~Stack(){
        empty();
    }
    bool push(int x){
        Node* tmp = new Node(x,head);
        head = tmp;
        capacity++;
        return true;
    }
    bool pop(int &x){
        if(!capacity) return false;
        x = head->val;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        capacity--;
        return true;
    }
    bool isEmpty(){
        return capacity == 0;
    }
    void empty(){
        Node* cur = head;
        while(cur){
            head = head->next;
            delete cur;
            cur = head;
        }
        capacity = 0;
    }
    int size(){
        return capacity;    
    }
};
