#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertEnd(int val) {
    Node* t = new Node{val, NULL};
    if (!head) {
        head = t;
        t->next = head;
    } else {
        Node* p = head;
        while (p->next != head) p = p->next;
        p->next = t;
        t->next = head;
    }
}

void display() {
    Node* p = head;
    if (!head) return;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << head->data << endl; // repeat head at end
}

int main() {
    int arr[] = {20,100
