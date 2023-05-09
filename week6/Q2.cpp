#include<iostream>
#include <chrono>

using namespace std;

class Node {
public:
    int data;
    Node* Next;
    Node(int data1){
        data =data1;
        Next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }
    void append(int data){
        if(head==NULL){
            head = new Node(data);
            return;
        }
        Node* current = head;
        while(current->Next != NULL){
            current = current->Next;
        }
        current->Next = new Node(data);
    }
    void prepend(int data){
        Node* newHead = new Node(data);
        newHead->Next = head;
        head = newHead;
    }
    void deleteValue(int data){
        if(head==NULL){
            return;
        }
        if(head->data==data){
            head=head->Next;
            return;
        }
        Node* current = head;
        while(current->Next != NULL){
            if(current->Next->data==data){
                current->Next=current->Next->Next;
                return;
            }
            current=current->Next;
        }
    }
    void printval(){
        Node* current = head;
        while(current != NULL){
            cout<<current->data<<endl;
            current=current->Next;
        }
        cout<<"######\n";
    }
    void search(int data){
        Node* current = head;
        while(current != NULL){
            if(current->data==data){
                cout<<"Found\n";
                return;
            }
            current=current->Next;
        }
        cout<<"NIL\n";
    }
};

class Stack {
    LinkedList* stack;
public:
    Stack() {
        stack = new LinkedList();
    }
    void push(int element) {
        stack->append(element);
    }
    int pop() {
        if (stack->head==NULL) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        if(stack->head->Next==NULL){
            int temp = stack->head->data;
            stack->prepend(NULL);
            return temp;
        }
        Node* current = stack->head;
        while(current->Next->Next!=NULL){
            current=current->Next;
        }
        int temp = current->Next->data;
        current->Next = current->Next->Next;
        return temp;
    }
    int peek() {
        if (stack->head==NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        Node* current = stack->head;
        while(current->Next->Next!=NULL){
            current=current->Next;
        }
        int temp = current->Next->data;
        return temp;

    }
    void Display(){
        stack->printval();
    }
    bool isEmpty() {
        return stack->head==NULL;
    }
};
int main(){
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
