class Solution {
public:
    string longestPalindrome(string s) {
        int low, high, start = 0;
        // every character is a palindrome on its own
        int maxLength = 1;
        int n = s.length();
        for(int i=0; i<n; i++){
            // for finding palindrome of even length
            low = i-1;
            high = i;
            while(low>=0 && high<n && s[low] == s[high]){
                if(high-low+1 > maxLength){
                    start = low;
                    maxLength = high-low+1;
                }
                --low;
                ++high;
            }
            // for finding palindrome of odd length
            low = i-1;
            high = i+1;
            while(low>=0 && high<n && s[low] == s[high]){
                if(high-low+1 > maxLength){
                    start = low;
                    maxLength = high-low+1;
                }
                --low;
                ++high;
            }
        }
        std::cout << maxLength << "\n";
        return s.substr(start, maxLength); 
    }
};
