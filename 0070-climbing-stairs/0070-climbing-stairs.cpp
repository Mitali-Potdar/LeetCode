class Solution {
public:
    int climbStairs(int n) {
        vector <int> dp(n+2, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        //for 3 steps it is like going to step 1 and then 2 climb or going to step 2 and then 1 climb. so knowing ways to climb 2 steps and 1 step gives the answer
        for(int i = 3; i < n+1; i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        return dp[n];
    }
};