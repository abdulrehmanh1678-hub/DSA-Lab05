#include <iostream>
using namespace std;

class LinkedStack {
    struct node {
        int data;
        node *next;
        node(int v) : data(v), next(nullptr) {}
    };
    node *top = nullptr;

public:
    bool IsEmpty() { 
        return top == nullptr;
    }

    void Push(int v) {
        node *n = new node(v);
        n->next = top;
        top = n;
    }

    void Pop() {
        if (IsEmpty()) { 
            cout << "Underflow\n"; 
            return; 
        }
        node *p = top;
        cout << "Popped: " << p->data << endl;
        top = top->next;
        delete p;
    }

    void Peek() {
        if (IsEmpty()) { 
            cout << "Stack empty\n"; return; 
        }
        cout << "Top: " << top->data << endl;
    }

    void Display() {
        if (IsEmpty()) { 
            cout << "Stack empty\n"; return; 
        }
        for (node *p = top; p; p = p->next)
            cout << p->data << " ";
        cout << endl;
    }

    void ClearStack() {
        while (!IsEmpty()) {
            node *p = top;
            top = top->next;
            delete p;
        }
    }
};

int main() {
    LinkedStack s;
    int choice, value;

    do {
        cout << "\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value: ";
                cin >> value;
                s.Push(value);
                break;
            case 2:
                s.Pop();
                break;
            case 3:
                s.Peek();
                break;
            case 4:
                s.Display();
                break;
            case 5:
                s.ClearStack();
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);
}