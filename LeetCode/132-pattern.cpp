class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> minimum(n, 0);
        if(n<3) return false;
        minimum[0] = nums[0];
        for(int i=1; i<n; i++)
            minimum[i] = min(nums[i], minimum[i-1]);
        stack<int> s;
        for(int i=n-1; i>=0; i--){
           if(nums[i] > minimum[i]){
               while((!s.empty()) && (s.top() <= minimum[i]))
                   s.pop();
               if((!s.empty()) && (s.top() < nums[i]))
                   return true;
               s.push(nums[i]);           
           }
        }
        return false;
    }
};
