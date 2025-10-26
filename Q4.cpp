#include<iostream>
using namespace std;

struct Node{ char data; Node* next; Node* prev; };

bool isPal(Node* head){
    if(!head) return true;
    Node* end = head;
    while(end->next) end = end->next;
    while(head != end && end->next != head){
        if(head->data != end->data) return false;
        head = head->next; end = end->prev;
    }
    return true;
}

int main(){
    Node* a = new Node{'r',NULL,NULL};
    Node* b = new Node{'a',NULL,a}; a->next = b;
    Node* c = new Node{'d',NULL,b}; b->next = c;
    Node* d = new Node{'a',NULL,c}; c->next = d;
    Node* e = new Node{'r',NULL,d}; d->next = e;
    cout << (isPal(a) ? "True" : "False");
}
