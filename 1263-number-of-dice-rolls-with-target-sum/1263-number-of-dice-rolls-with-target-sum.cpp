class Solution {
public:
    int numRollsToTarget(int n, int f, int target) {
        int MOD = 1000000007;
        if(n == 1){
            if(target <= f) return 1;
            else return 0;
        }
        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                for(int k = 1; k <= f; k++){
                    if(j >= k)
                        dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
                }
            }
        }
        return dp[n][target];
    }
};
