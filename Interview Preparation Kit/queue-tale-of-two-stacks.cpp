#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
public:
    stack<long int> stack_newest_on_top, stack_oldest_on_top;   
    void push(long int x) {
        stack_newest_on_top.push(x);
    }

    void pop() {
        if(stack_oldest_on_top.empty()) {
            updateOldest();
        }
        stack_oldest_on_top.pop();
    }

    int front() {
        if(stack_oldest_on_top.empty()) {
            updateOldest();
        }
        return stack_oldest_on_top.top();
    }
private:
    void updateOldest() {
        while(!stack_newest_on_top.empty()) {
            stack_oldest_on_top.push(stack_newest_on_top.top());
            stack_newest_on_top.pop();
        }
    }};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


