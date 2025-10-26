#include<iostream>
using namespace std;

struct Node { int data; Node *prev, *next; };
Node* head = NULL;

void insertEnd(int x){
    Node* t = new Node{x, NULL, NULL};
    if(!head) head = t;
    else {
        Node* p = head;
        while(p->next) p = p->next;
        p->next = t;
        t->prev = p;
    }
}

void del(int x){
    Node* p = head;
    while(p && p->data != x) p = p->next;
    if(!p) return;
    if(p->prev) p->prev->next = p->next;
    if(p->next) p->next->prev = p->prev;
    if(p == head) head = p->next;
    delete p;
}

void search(int x){
    Node* p = head;
    while(p){
        if(p->data == x){ cout << "Found\n"; return; }
        p = p->next;
    }
    cout << "Not Found\n";
}

void display(){
    for(Node* p = head; p; p = p->next)
        cout << p->data << " ";
    cout << endl;
}

int main(){
    int ch, x;
    do{
        cout << "\n1.Insert  2.Delete  3.Search  4.Display  5.Exit\n";
        cin >> ch;
        switch(ch){
            case 1: cout << "Enter value: "; cin >> x; insertEnd(x); break;
            case 2: cout << "Enter value to delete: "; cin >> x; del(x); break;
            case 3: cout << "Enter value to search: "; cin >> x; search(x); break;
            case 4: display(); break;
        }
    } while(ch != 5);
}
