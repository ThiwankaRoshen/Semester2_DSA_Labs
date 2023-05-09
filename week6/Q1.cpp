#include <iostream>
#include <climits>
#include <chrono>

using namespace std;

const int size1 = 100;

class Stack {
public:
    int arr[size1];
    int top;
    Stack() {
        top = -1;
    }

    void push(int item) {
        if (top == size1 - 1) {
            cout << "Stack overflow\n";
            return;
        }
        top++;
        arr[top] = item;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return INT_MIN;
        }
        int temp = arr[top];
        top--;
        return temp;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return arr[top];
    }

    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << endl;
        }
        cout << "###\n";
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.Display();
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.Display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.Display();
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Execution time: " << duration.count() << " microseconds\n";
    return 0;
}
