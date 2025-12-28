#include <iostream>
#include <string>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {};
    Node(int x) : val(x), next(nullptr) {};
    Node(int x, Node* p) : val(x), next(p) {};
};

struct Stack {
    Node* head;
    int capacity;
    Stack() {
        head = nullptr;
        capacity = 0;
    }
    ~Stack() {
        empty();
    }
    bool push(int x) {
        Node* tmp = new Node(x, head);
        head = tmp;
        capacity++;
        return true;
    }
    bool pop(int& x) {
        if (!capacity) return false;
        x = head->val;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        capacity--;
        return true;
    }
    bool isEmpty() {
        return capacity == 0;
    }
    void empty() {
        Node* cur = head;
        while (cur) {
            head = head->next;
            delete cur;
            cur = head;
        }
        capacity = 0;
    }
    int size() {
        return capacity;
    }
};

struct Queue {
    Node* head;
    Node* tail;
    int capacity;
    Queue() {
        head = nullptr;
        tail = nullptr;
        capacity = 0;
    }
    ~Queue() {
        empty();
    }
    bool enqueue(int x) {
        if (!tail || !head) {
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
    bool dequeue(int& x) {
        if (!head && !tail) return false;
        Node* tmp = head;
        x = tmp->val;
        head = head->next;
        if (!head) tail = nullptr;
        delete tmp;
        capacity--;
        return true;
    }
    bool isEmpty() {
        return capacity == 0;
    }
    void empty() {
        Node* tmp = head;
        while (tmp) {
            head = head->next;
            delete tmp;
            tmp = head;
        }
        tail = nullptr;
        head = nullptr;
        capacity = 0;
    }
    int size() {
        return capacity;
    }
};

long long myPower(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

char valToHexChar(int v) {
    if (v >= 0 && v <= 9) return v + '0';
    return v - 10 + 'A';
}

int hexCharToVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

void decimalToBinary(unsigned int num) {
    if (num == 0) {
        cout << "0" << endl;
        return;
    }

    Stack s; 
    while (num > 0) {
        s.push(num % 2);
        num /= 2;
    }

    // Pop and print
    int bit;
    while (s.pop(bit)) {
        cout << bit;
    }
    cout << endl;
}

void binaryToDecimal(string binStr) {
    Stack s;
    for (int i = 0; i < binStr.length(); i++) {
        s.push(binStr[i]); 
    }

    unsigned long long decimalVal = 0;
    int power = 0;
    int charCode;

    while (s.pop(charCode)) {
        char bit = (char)charCode;
        if (bit == '1') {
            decimalVal += myPower(2, power);
        }
        power++;
    }
    cout << decimalVal << endl;
}

void decimalToHex(unsigned int num) {
    if (num == 0) {
        cout << "0" << endl;
        return;
    }

    Stack s;
    while (num > 0) {
        int rem = num % 16;
        char hexChar = valToHexChar(rem); 
        s.push((int)hexChar);
        num /= 16;
    }

    int charVal;
    while (s.pop(charVal)) {
        cout << (char)charVal;
    }
    cout << endl;
}

void hexToDecimal(string hexStr) {
    Stack s;
    for (int i = 0; i < hexStr.length(); i++) {
        s.push(hexStr[i]);
    }

    unsigned long long decimalVal = 0;
    int power = 0;
    int charCode;

    while (s.pop(charCode)) {
        char c = (char)charCode;
        int val = hexCharToVal(c);
        decimalVal += val * myPower(16, power);
        power++;
    }
    cout << decimalVal << endl;
}

int main() {
    int choice;
    unsigned int numInput;
    string strInput;

    while (true) {
        cout << "\n=== MANUAL BASE CONVERTER ===" << endl;
        cout << "1. Decimal to Binary" << endl;
        cout << "2. Binary to Decimal" << endl;
        cout << "3. Decimal to Hex" << endl;
        cout << "4. Hex to Decimal" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting..." << endl;
            break;
        }

        switch (choice) {
        case 1:
            cout << "Enter Decimal: ";
            cin >> numInput;
            cout << "Result: ";
            decimalToBinary(numInput);
            break;
        case 2:
            cout << "Enter Binary: ";
            cin >> strInput;
            cout << "Result: ";
            binaryToDecimal(strInput);
            break;
        case 3:
            cout << "Enter Decimal: ";
            cin >> numInput;
            cout << "Result: ";
            decimalToHex(numInput);
            break;
        case 4:
            cout << "Enter Hex: ";
            cin >> strInput;
            cout << "Result: ";
            hexToDecimal(strInput);
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}