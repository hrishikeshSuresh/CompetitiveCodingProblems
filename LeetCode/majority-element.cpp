class Solution {
public:
    int findCandidate(vector<int> &nums){
        int maj_index = 0, count = 1;
        for(u_int i=0; i<nums.size(); i++){
            if(nums[i] == nums[maj_index])
                count++;
            else
                count--;
            
            if(count == 0)
                maj_index = i, count = 1;
        }
        return nums[maj_index];
    }
    
    bool isMajority(vector<int> &nums, int candidate){
        int count = 0;
        for(u_int i=0; i<nums.size(); i++){
            if(nums[i] == candidate) count++;
        }
        if(count > nums.size()/2) return true;
        else return false;
    }
    
    int majorityElement(vector<int>& nums) {
        int candidate = findCandidate(nums);
        return (isMajority(nums, candidate))? candidate:-1;
    }
};
