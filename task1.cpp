#include <iostream>
using namespace std;

struct node { 
    int data;
    node* next;
    node* prev;
     };

node *head = nullptr, *tail = nullptr;

void AddNode(int v) {
    node* n = new node{v, nullptr, tail};
    if (tail) tail->next = n; else head = n;
    tail = n;
}

void PrintForward() {
    if (!head) { cout << "List is empty\n"; return; }
    for (node* p = head; p; p = p->next) cout << p->data << " ";
    cout << "\n";
}

void PrintReverse() {
    if (!tail) { cout << "List is empty\n"; return; }
    for (node* p = tail; p; p = p->prev) cout << p->data << " ";
    cout << "\n";
}

void ClearList() {
    while (head) { node* t = head; head = head->next; delete t; }
    tail = nullptr;
}

int main() {
    int n, v;
    cout << "Count: "; cin >> n;
    for (int i = 0; i < n; i++) { cin >> v; AddNode(v); }
    PrintForward();
    PrintReverse();
    ClearList();
}