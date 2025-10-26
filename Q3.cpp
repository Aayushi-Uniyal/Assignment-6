#include<iostream>
using namespace std;

struct Node { int data; Node *next, *prev; };
Node *dhead = NULL, *chead = NULL;

int sizeDLL(){
    int c = 0;
    for(Node* p = dhead; p; p = p->next) c++;
    return c;
}

int sizeCLL(){
    if(!chead) return 0;
    int c = 0;
    Node* p = chead;
    do { c++; p = p->next; } while(p != chead);
    return c;
}

int main(){
  
    Node* a = new Node{1,NULL,NULL};
    Node* b = new Node{2,NULL,a};
    Node* c = new Node{3,NULL,b};
    a->next = b; b->next = c;
    dhead = a;

    
    Node* x = new Node{10,NULL,NULL};
    Node* y = new Node{20,NULL,NULL};
    x->next = y; y->next = x;
    chead = x;

    cout << "DLL size: " << sizeDLL() << endl;
    cout << "CLL size: " << sizeCLL() << endl;
}
