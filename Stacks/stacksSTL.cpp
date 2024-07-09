#include <bits/stdc++.h>
using namespace std;
int main() {
    //creation of a stack
    stack<int> s;

    //push command to add data
    s.push(3);
    s.push(5);
     
     //displaying data using empty and pop function
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}