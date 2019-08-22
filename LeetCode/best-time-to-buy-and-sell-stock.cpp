class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int n = prices.size();
        int minElement = prices[0];
        int maxDiff = prices[1] - minElement;
        for(int i=1; i<n; i++){
            if(prices[i] - minElement > maxDiff)
                maxDiff = prices[i] - minElement;
            if(minElement > prices[i])
                minElement = prices[i];   
        }
        return max(maxDiff, 0);
    }
};
