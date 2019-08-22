#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// FLAG ::: Not working

/*PROBLEM DESCRIPTION
Scientists, researchers, mathematicians and thinkers propose theories for a number of things.
For explaining a single thing, a number of theories are proposed.
A number of theories are rendered invalid after a new and more relevant theory surfaces, giving a better and a more valid explanation for the subject of the theory.
For this problem, we are only concerned with one field of study, lets say, A.
In the field A, a number of theories were proposed for a number of domains in the field.

For a particular theory, the time at which it was proposed be T1 and the time at which it becomes invalid be T2.
We define the theory period for this particular theory as [T1, T2).
Both T1 and T2 are recorded in seconds from some reference point, B.
We are given the theory periods for a number of theories.
It is possible that more than one theory in the field A might be valid at some second, T (Recorded with reference to B ).
Let us call the value of the number of valid theories at the second T as popularity of the field at second T.
The popularity of the field would be maximum at some point in time.
Your task is simple, that is calculate this maximum value of popularity for the field A.
*/

int main(int argc, const char *argv[]){
    int t;
    long long int n, arrival_time, exit_time, max_count, curr_count, i, j;
    long long int *arrivals, *exits;
    scanf("%d", &t);
    while(t--){
        scanf("%llu", &n);
        arrivals = (long long int*)malloc(sizeof(long long int)*n);
        exits = (long long int*)malloc(sizeof(long long int)*n);
        for(int k=0; k<n; k++){
            scanf("%llu %llu", &arrival_time, &exit_time);
            arrivals[k] = arrival_time;
            exits[k] = exit_time;
        }
        sort(arrivals, arrivals + n);
        sort(exits, exits + n);
        i = 1;
        j = 0;
        max_count = 1;
        curr_count = 1;
        while(i<n && j<n){
            if(arrivals[i]<exits[j]){
                curr_count++;
                i++;
                if(curr_count>max_count){
                    max_count = curr_count;
                }
            }
            else{
                curr_count--;
                j++;
            }
        }
    printf("%llu\n", max_count);
    }
    return 0;
}
