#include<bits/stdc++.h>

#define loop(i, a, b)\
for(int i=a; i<b; i++)

long long int mod = 1000000007;

int main(int argc, const char *argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin >> T;
    loop(t, 1, T+1){
        int friends, a, b, x, y, p, q, travel_time;
        std::cin >> friends;
        scanf("%d:%d", &x, &y);
        int in_time = (x*60)%mod+y;
        scanf("%d:%d", &p, &q);
        int wake_up = (p*60)%mod+q;
        scanf("%d:%d", &a, &b);
        int open_time = (a*60)%mod+b;
        int R, S;
        std::cin >> R;
        std::cin >> S;
        int begin_travel = std::max(wake_up, open_time);
        travel_time = 2*R + S;
        int ans = -1;
        int time_taken;
        int last = 1000000007;
        loop(i, 1, friends+1){
            int fhleave, fmleave, fhback, fmback;
            scanf("%d:%d %d:%d", &fhleave, &fmleave, &fhback, &fmback);
            int departure_time = (fhleave*60)%mod+fmleave;
            int arrival_time = (fhback*60)%mod+fmleave;
            if(begin_travel+travel_time<departure_time && begin_travel+travel_time<in_time){
                if(ans==-1 || begin_travel+travel_time<last){
                    ans = i;
                    last = begin_travel+travel_time;
                }
                else if(std::max(begin_travel, arrival_time)+travel_time < in_time){
                    time_taken = std::max(begin_travel, arrival_time) + travel_time;
                    if(time_taken<last){
                        last = time_taken;
                        ans = i;
                    }
                }
            }
        }
        std::cout << "Case " << t << ": " << ans << std::endl;
    }
    return 0;
}
