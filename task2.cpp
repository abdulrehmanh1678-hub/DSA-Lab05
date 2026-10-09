
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

    void InsertBefore(int pos, int v) {
        if (pos < 1) { cout << "Invalid position\n"; return; }

        node *p = head;
        for (int i = 1; p && i < pos; i++)
            p = p->next;

        if (!p) { cout << "Invalid position\n"; return; }

        node *n = new node(v);
        n->next = p;
        n->prev = p->prev;

        if (p->prev) p->prev->next = n;
        else head = n;

        p->prev = n;
    }

    void DeleteNode(int v) {
        node *p = head;
        while (p && p->data != v) p = p->next;

        if (!p) { cout << "Value not found\n"; return; }

        if (p->prev) p->prev->next = p->next;
        else head = p->next;

        if (p->next) p->next->prev = p->prev;
        else tail = p->prev;

        delete p;
    }

    void PrintForward() {
        if (!head) cout << "Empty list";
        for (node *p = head; p; p = p->next)
            cout << p->data << " ";
        cout << endl;
    }

    void PrintReverse() {
        if (!tail) cout << "Empty list";
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
    l.AddNode(10);
    l.AddNode(20);
    l.AddNode(30);

    l.InsertBefore(2, 15);
    l.DeleteNode(20);

    l.PrintForward();
    l.PrintReverse();
    l.ClearList();
}