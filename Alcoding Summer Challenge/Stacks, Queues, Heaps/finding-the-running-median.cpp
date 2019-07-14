#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */

vector<double> runningMedian(vector<double> arr) {
    priority_queue<double> s;  
    vector<double> ans;
    priority_queue<double,vector<double>,greater<double> > g; 
    double med = arr[0]; 
    s.push(arr[0]); 
    ans.push_back(arr[0]);
    for (int i=1; i < arr.size(); i++) { 
        double x = arr[i];  
        if (s.size() > g.size()) { 
            if (x < med) { 
                g.push(s.top()); 
                s.pop(); 
                s.push(x); 
            } 
            else
                g.push(x); 
            med = (s.top() + g.top())/2.0; 
        }  
        else if (s.size()==g.size()) { 
            if (x < med) { 
                s.push(x); 
                med = (double)s.top(); 
            } 
            else{ 
                g.push(x); 
                med = (double)g.top(); 
            } 
        }  
        else{ 
            if (x > med) { 
                s.push(g.top()); 
                g.pop(); 
                g.push(x); 
            } 
            else
                s.push(x); 
            med = (s.top() + g.top())/2.0; 
        }
        ans.push_back(med); 
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<double> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        double a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

