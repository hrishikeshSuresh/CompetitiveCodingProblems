class NumArray {
public:
    vector<int> prefixArray;
    NumArray(vector<int>& nums) {
        if(nums.size() == 0) return;
        prefixArray = vector<int>(nums.size()+1, 0);
        prefixArray[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
            prefixArray[i] = prefixArray[i-1] + nums[i];
    }
    
    int sumRange(int i, int j) {
        if(prefixArray.size() == 0) return 0;
        if(i==0) return prefixArray[j];
        return prefixArray[j] - prefixArray[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
