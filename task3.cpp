
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
        if (!head) {
            head = tail = n;
            n->next = head;
        } else {
            tail->next = n;
            tail = n;
            tail->next = head;
        }
    }

    void PrintList() {
        if (!head) {
        cout << "Empty list\n"; 
        return; 
    }
        node *p = head;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }

    int CountNodes() {
        if (!head) return 0;
        int count = 0;
        node *p = head;
        do {
            count++;
            p = p->next;
        } while (p != head);
        return count;
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

    l.PrintList();
    cout << "Count: " << l.CountNodes() << endl;
    l.ClearList();
}