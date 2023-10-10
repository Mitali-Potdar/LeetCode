class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        int c = 1;
        while(c*c <= n){
            int sq = c*c;
            for(int i = sq; i < n+1; i++){
                dp[i] = min(dp[i-sq] + 1, dp[i]);
            }
            c++;
        }
        return dp[n];

        // int m = pow(n, 0.5);
        // vector <int> sq(m);
        // for(int i = 0; i < m; i++){
        //     sq[i] = pow(i+1, 2);
        // }

        // vector<vector<int>> dp(m+1, vector<int> (n+1));
        // for(int i = 0; i < m+1; i++){
        //     for(int j = 0; j < n+1; j++){
        //         if(j == 0) dp[i][j] = 0;
        //         if(i == 0) dp[i][j] = INT_MAX - 1;
        //     }
        // }

        // int i = 1;
        // for(int j = 1; j < n+1; j++){
        //     if(j % sq[0] != 0) dp[i][j] = INT_MAX - 1;
        //     else dp[i][j] = j/sq[0];
        // }

        // for(int i = 1; i < m+1; i++){
        //     for(int j = 1; j < n+1; j++){
        //         if(sq[i-1] <= j) dp[i][j] = min(1+dp[i][j-sq[i-1]], dp[i-1][j]);
        //         else dp[i][j] = dp[i-1][j];
        //     }
        // }
        
        // if(dp[m][n] == INT_MAX -1)
        //     return 0;
        // return dp[m][n];
    }
};