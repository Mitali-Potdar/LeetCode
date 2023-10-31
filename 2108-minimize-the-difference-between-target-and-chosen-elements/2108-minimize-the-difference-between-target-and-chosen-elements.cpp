
class Solution {
public:
    
    int m, n;
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        m = mat.size();
        n = mat[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(target+1, INT_MAX));
        
        // dp[i][j] ans for upto ith row and j target val
        
        for(int j=0; j<=target; j++) dp[0][j] = j;
        
        for(int i=1; i<=m; i++){
            for(int j=0; j <= target; j++){
                for(int k=0; k<n; k++){
                    if(j >= mat[i-1][k]) dp[i][j] = min(dp[i][j], dp[i-1][j - mat[i-1][k]]);
                    else dp[i][j] = min(dp[i][j], (mat[i-1][k] - j) + dp[i-1][0]);
                }
            }
        }
        
        int ans = dp[m][target];
        
        return ans;
    }
};