#include <bits/stdc++.h>
//ctrl + shift + b
using namespace std;
class Stack {
    public:
    int top;
    int size;
    int* arr;
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;   
        }else {
            cout << "Stack Overflow" << endl;
        }
    }
    int peek() {
        if(top >= 0) 
            return arr[top];
        else
            cout<< "Stack is empty" << endl;
    }
    void pop() {
        if(top >= 0) 
            top--;
        else
            cout << "Stack Underflow" << endl;    
    }
    bool isEmpty() {
        if(top == -1)
            return true;
        else
            return false;    
    }
};
int main() {
    Stack st(5);
    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        st.push(x);
    }
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    cout << st.isEmpty() <<endl;
    
    
    
return 0;
}