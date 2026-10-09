
#include <iostream>
using namespace std;

class CircularList {
    struct node {
        int data;
        node *next;
        node(int v) : data(v), next(nullptr) {}
    };
    node *head = nullptr, *tail = nullptr;

public:
    void AddNode(int v) {
        node *n = new node(v);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
        tail->next = head;
    }

    void DeleteNode(int v) {
        if (!head) { cout << "Empty list\n"; return; }

        node *p = head, *prev = tail;
        do {
            if (p->data == v) {
                if (p == head && p == tail)
                    head = tail = nullptr;
                else {
                    prev->next = p->next;
                    if (p == head) head = p->next;
                    if (p == tail) tail = prev;
                    tail->next = head;
                }
                delete p;
                return;
            }
            prev = p;
            p = p->next;
        } while (p != head);

        cout << "Value not found\n";
    }

    void PrintList() {
        if (!head) { cout << "Empty list\n"; return; }
        node *p = head;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
        cout << "Count: " << CountNodes() << endl;
    }

    int CountNodes() {
        if (!head) return 0;
        int c = 0;
        node *p = head;
        do {
            c++;
            p = p->next;
        } while (p != head);
        return c;
    }

    void ClearList() {
        if (!head) return;
        tail->next = nullptr;
        while (head) {
            node *p = head;
            head = head->next;
            delete p;
        }
        tail = nullptr;
    }
};

int main() {
    CircularList l;
    l.AddNode(10);
    l.AddNode(20);
    l.AddNode(30);

    l.DeleteNode(10);
    l.PrintList();

    l.DeleteNode(30);
    l.PrintList();

    l.DeleteNode(20);
    l.PrintList();

    l.ClearList();
}