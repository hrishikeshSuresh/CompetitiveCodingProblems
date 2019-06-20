#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
    vector<int> plants_dying;
    bool all_healthy = false;
    int no_of_days = 0;
    while(!all_healthy){
      no_of_days++;
	  for(u_int i=0; i<p.size(); i++)
		cout << p[i] << " ";
	  cout << endl;
      for (u_int i = 0; i < p.size()-1; i++) {
        if (p[i] > p[i+1]) {
          plants_dying.push_back(i+1);
        }
      }
      if (plants_dying.size() == 0) {
        all_healthy = true;
        continue;
      }
	  cout << "INDICES : ";
      for(u_int i=0; i<plants_dying.size(); i++){
		cout << plants_dying[i] << " ";
        p.erase(p.begin() + plants_dying[i]-1 - i);
      }
	  cout << endl;
      plants_dying.clear();
    }
    return no_of_days;
} 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);
	cout << result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

