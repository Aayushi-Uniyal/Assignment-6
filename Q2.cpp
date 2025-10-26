#include<iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

void insertEnd(int x){
    Node* t = new Node{x, NULL};
    if(!head){ head = t; t->next = head; }
    else {
        Node* p = head;
        while(p->next != head) p = p->next;
        p->next = t;
        t->next = head;
    }
}

void display(){
    Node* p = head;
    if(!p) return;
    do {
        cout << p->data << " ";
        p = p->next;
    } while(p != head);
    cout << head->data; // repeat head
}

int main(){
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        insertEnd(x);
    }
    display();
}
