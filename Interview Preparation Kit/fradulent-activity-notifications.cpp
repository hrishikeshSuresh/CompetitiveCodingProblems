#include<bits/stdc++.h>

using namespace std;

int median(deque<int> t, int window_half, bool flag ){
    int median_val;
    if(flag){
        median_val = (t[window_half] + t[window_half + 1])/2;
    }
    else{
        median_val = t[window_half];
    }
	return median_val;
}

int counting_sort(int arr[], int n, int notifications, int start, int stop, bool flag, int window_half){
    int max_val = *max_element(arr+start, arr+stop);
    //cout << "Max. element is " << max_val << endl;
    int *aux = (int*)malloc(sizeof(int)*(max_val+1));
    //memset(aux, 0, sizeof(aux));
    for(int i=0; i<=max_val; i++)
        aux[i] = 0;
    for(int i=start; i<stop; i++){
        //cout << arr[i] << " ";
        aux[arr[i]]++;
    }
    //cout << endl;
    int *sorted_arr = (int*)malloc(sizeof(int)*(stop-start));
    int j=0;
    memset(sorted_arr, 0, sizeof(sorted_arr));
    //for(int i=0; i<=max_val; i++){
    //    cout << i << " " << aux[i] << endl;
    //}
    for(int i=0; i<=max_val; i++){
        //cout << aux[i] << endl;
        int tmp = aux[i];
        while(tmp--){
            sorted_arr[j] = i;
            j++;
        }
    }
    //for(int i=0; i<j; i++)
    //    cout << sorted_arr[i] << " ";
    //cout << endl;
    float median_val;
    if(flag){
        //cout << "here" << endl;
        median_val = float((sorted_arr[window_half] + sorted_arr[window_half - 1]))/2;
    }
    else{
        median_val = sorted_arr[window_half];
    }
    //cout << "Median value " << median_val << " Next transaction " << arr[stop] << endl;
    if(arr[stop]>=2*median_val)
        notifications++;
    return notifications;
}

int main(int argc, const char *argv[]){
    int N, a, d, median_val, notifications;
    cin >> N >> d;
    int window_half = d/2;
    bool flag = false;
    int arr[N];
    if(d%2 == 0){
        flag = true;
    }
    for(int i=0; i<N; i++)
        cin >> arr[i];
    notifications = 0;
    for(int m=0; m<N-d; m++){
        notifications = counting_sort(arr, N, notifications, m, m+d, flag, window_half);
    }
    cout << notifications << endl;
}
