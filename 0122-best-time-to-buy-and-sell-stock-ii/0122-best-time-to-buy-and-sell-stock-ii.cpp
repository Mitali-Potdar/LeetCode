class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n+1, vector<long> (2, 0)); //buy = 1 means you can buy
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                if(buy == 1){
                    dp[i][buy] = max(-prices[i] + dp[i+1][0], dp[i+1][1]); //buying or not buying
                } else dp[i][buy] = max(prices[i] + dp[i+1][1], dp[i+1][0]); //selling or not selling
            }
        }
        return dp[0][1];
    }
};