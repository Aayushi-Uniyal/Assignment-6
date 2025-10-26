#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};
Node *head = NULL, *tail = NULL;

void insertFirst(int val) {
    Node *t = new Node{val, NULL, NULL};
    if (!head) head = tail = t;
    else {
        t->next = head;
        head->prev = t;
        head = t;
    }
}

void insertLast(int val) {
    Node *t = new Node{val, NULL, NULL};
    if (!tail) head = tail = t;
    else {
        tail->next = t;
        t->prev = tail;
        tail = t;
    }
}

void deleteNode(int val) {
    Node *p = head;
    while (p && p->data != val) p = p->next;
    if (!p) { cout << "Node not found\n"; return; }
    if (p == head) head = head->next;
    if (p == tail) tail = tail->prev;
    if (p->prev) p->prev->next = p->next;
    if (p->next) p->next->prev = p->prev;
    delete p;
}

void searchNode(int val) {
    Node *p = head;
    while (p) {
        if (p->data == val) { cout << "Found\n"; return; }
        p = p->next;
    }
    cout << "Not Found\n";
}

void display() {
    Node *p = head;
    while (p) { cout << p->data << " "; p = p->next; }
    cout << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\n1.Insert First\n2.Insert Last\n3.Delete Node\n4.Search\n5.Display\n6.Exit\n";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; insertFirst(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertLast(val); break;
            case 3: cout << "Enter value to delete: "; cin >> val; deleteNode(val); break;
            case 4: cout << "Enter value to search: "; cin >> val; searchNode(val); break;
            case 5: display(); break;
        }
    } while (choice != 6);
}
