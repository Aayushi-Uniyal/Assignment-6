#include<iostream>
using namespace std;

struct Node{ int data; Node* next; };

bool isCircular(Node* head){
    if(!head) return false;
    Node* p = head->next;
    while(p && p != head) p = p->next;
    return (p == head);
}

int main(){
    Node* a = new Node{2,NULL};
    Node* b = new Node{4,NULL};
    Node* c = new Node{6,NULL};
    a->next = b; b->next = c; c->next = a; // make circular
    cout << (isCircular(a) ? "True" : "False");
}
