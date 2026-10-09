#include <iostream>
using namespace std;

class ArrayStack {
    int items[5], top = -1;

public:
    bool IsEmpty() { 
        return top == -1;
     }
    bool IsFull() {
         return top == 4; 
        }

    void Push(int v) {
        if (IsFull()) { cout << "Overflow\n"; return; }
        items[++top] = v;
    }

    void Pop() {
        if (IsEmpty()) { 
            cout << "Underflow\n"; return; 
        }
        cout << "Popped: " << items[top--] << endl;
    }

    void Peek() {
        if (IsEmpty()) {
             cout << "Underflow\n"; return; 
            }
        cout << "Top: " << items[top] << endl;
    }

    void Display() {
        for (int i = top; i >= 0; i--)
            cout << items[i] << " ";
        cout << endl;
    }
};

int main() {
    ArrayStack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Push(50);
    s.Push(60);

    s.Display();
    s.Pop();
    s.Peek();
    
    while (!s.IsEmpty()) s.Pop();
    //List Empty
    s.Pop();
}