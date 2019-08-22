class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(u_int i=0; i<nums.size(); i++)
            umap[nums[i]]++;
        for(auto itr : umap)
            if(itr.second == 1)
                return itr.first;
        return -1;
    }
};
