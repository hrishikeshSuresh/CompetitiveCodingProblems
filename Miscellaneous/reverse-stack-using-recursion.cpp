#include<bits/stdc++.h>

using namespace std;

void insert_at_bottom(stack<int> &s, int x){
    if(s.size() == 0)
        s.push(x);
    else{
        int a = s.top();
        s.pop();
        insert_at_bottom(s, x);
        s.push(a);
    }
}

void reverse_stack(stack<int> &s){
    if(s.size() > 0){
        int x = s.top();
        s.pop();
        reverse_stack(s);
        insert_at_bottom(s, x);
    }
}

int main(int argc, const char *argv[]){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.top() << endl;
	reverse_stack(s);
	cout << s.top() << endl;
	return 0;
}
