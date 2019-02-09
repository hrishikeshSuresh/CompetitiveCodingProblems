#include<bits/stdc++.h>

bool isPrime(int number){
    if(number<=1) return false;
    else if(number<=3) return true;
    else if(number%2==0 || number%3==0) return false;
    else{
        for(int i=5; i*i<=number; i+=6){
            if(number%i==0 || number%(i+2)==0) return false;
        }
    }
    return true;
}

int main(int argc, const char *agv[]){
    int T, index = 0;
    std::cin >> T;
    int alphabets[26];
    //printf("1\n");
    for(int i=65; i<=90; i++){
        if(isPrime(i)){
            alphabets[index] = i;
            index++;
        }
    }
    for(int i=97; i<=122; i++){
        if(isPrime(i)){
            alphabets[index] = i;
            index++;
        }
    }
    //printf("2\n");
    /*for(int y=0; y<index; y++){
        printf("%d\t", alphabets[y]);
    }*/
    //printf("\n");
    //index would become length of array
    while(T--){
        int l;
        std::cin >> l;
        std::string S;
        std::cin >> S;
        for(int i=0; i<l; i++){
            //std::cout << S[i] << " ";
            int val = (int)S[i];
            for(int j=0; j<index; j++){
                //printf("%d %d\n", val, alphabets[j]);
                if(val == alphabets[j])
                    break;
                else if(j+1!=index){
                    if(alphabets[j]<val && alphabets[j+1]>val){
                        //printf("%d %d %d\n", val, alphabets[j], alphabets[j+1]);
                        if(val <= (alphabets[j]+alphabets[j+1])/2){
                            S[i] = (char)alphabets[j];
                            break;
                        }
                        else{
                            S[i] = (char)alphabets[j+1];
                            break;
                        }
                    }
                }
                else if(val>alphabets[index-1]){
                    S[i] = (char)alphabets[index-1];
                    break;
                }
                else if(val<alphabets[0]){
                    S[i] = (char)alphabets[0];
                    break;
                }
            }
        }
        std::cout << S << std::endl;
    }
    return 0;
}
