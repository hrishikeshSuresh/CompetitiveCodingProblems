#include<bits/stdc++.h>

using namespace std;

void show_mem_rep(char *start, int n)  
{ 
    int i; 
    for (i = 0; i < n; i++) 
         printf(" %.2x", start[i]); 
    printf("\n"); 
}

int main() 
{ 
   int i = 0x01234567; 
   show_mem_rep((char *)&i, sizeof(i));
   return 0; 
} 
