class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n+2, vector<long> (2, 0)); 
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                if(buy == 1){ //you can buy
                    dp[i][buy] = max(-prices[i] + dp[i+1][0], dp[i+1][1]); //buying or not buying
                } else dp[i][buy] = max(prices[i] + dp[i+2][1], dp[i+1][0]); //selling or not selling
            }
        }
        return dp[0][1];
    }
};