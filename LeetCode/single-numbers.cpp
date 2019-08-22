class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int x = nums[0];
        for(u_int i=1; i<nums.size(); i++){
            x = x ^ nums[i];
        }
        return x;
    }
};
