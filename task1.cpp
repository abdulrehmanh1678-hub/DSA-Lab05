
#include <iostream>
using namespace std;

class DoublyList {
    struct node {
        int data;
        node *next, *prev;
        node(int v) : data(v), next(nullptr), prev(nullptr) {}
    };
    node *head = nullptr, *tail = nullptr;

public:
    void AddNode(int v) {
        node *n = new node(v);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void PrintForward() {
        if (!head) { cout << "Empty list\n"; return; }
        for (node *p = head; p; p = p->next)
            cout << p->data << " ";
        cout << endl;
    }

    void PrintReverse() {
        if (!tail) { cout << "Empty list\n"; return; }
        for (node *p = tail; p; p = p->prev)
            cout << p->data << " ";
        cout << endl;
    }

    void ClearList() {
        while (head) {
            node *p = head;
            head = head->next;
            delete p;
        }
        tail = nullptr;
    }
};

int main() {
    DoublyList l;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        l.AddNode(x);
    }
    l.PrintForward();
    l.PrintReverse();
    l.ClearList();
}