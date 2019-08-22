#include<bits/stdc++.h>

int main(int argc, const char *argv[]){
    int T;
    std::string S;
    std::cin >> T;
    if(T==0){
        std::cout << "Invalid Test\n";
        return 0;
    }
    while(T--){
        std::cin >> S;
        bool space_flag = false;
        int upper_count = 0, lower_count = 0, digit_count = 0, spec_count = 0;
        for(int i=0; S[i]!='\0'; i++){
            if(int(S[i])>=65 && int(S[i])<=90){
                upper_count++;
            }
            else if(int(S[i])>=97 && int(S[i])<=122){
                lower_count++;
            }
            else if(int(S[i]) == 32){
                space_flag = true;
            }
            else if (isdigit(S[i])){
                digit_count++;
            }
            else{
                spec_count++;
            }
        }
        if(space_flag){
            std::cout << "Invalid Input" << std::endl;
        }
        else if(lower_count!=0 && upper_count!=0){
            if(lower_count>=upper_count){
                std::cout << upper_count << std::endl;
            }
            else{
                std::cout << lower_count << std::endl;
            }
        }
        else if(S.length()>100 || S.length()<1)
            std::cout << "Invalid Input\n";
        else if(lower_count==0 && upper_count==0)
            std::cout << "Invalid Input\n";
        else if(lower_count>0 && upper_count==0)
            std::cout << 0 << std::endl;
        else if(upper_count>0 && lower_count==0)
            std::cout << 0 << std::endl;
    }
    return 0;
}
