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
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            stack<int> enq, deq;
            stack_newest_on_top.push(x);
            enq = stack_newest_on_top;
            while(enq.size() != 0){
                deq.push(enq.top());
                enq.pop();
            }
            stack_oldest_on_top = deq;
        }

        void pop() {
            stack<int> enq, deq;
            stack_oldest_on_top.pop();
            enq = stack_oldest_on_top;
            while(enq.size() != 0){
                deq.push(enq.top());
                enq.pop();
            }
            stack_newest_on_top = deq;
        }

        int front() {
            return stack_oldest_on_top.top();
        }
};

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


