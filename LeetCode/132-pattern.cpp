class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        for(u_int i=0; i<nums.size(); i++){
            for(u_int j=i+1; j<nums.size(); j++){
                for(u_int k=j+1; k<nums.size(); k++){
                    if(a[i] < a[k] && a[k] < a[j])
                        return true;
                }
            }
        }
        return false;
    }
};
