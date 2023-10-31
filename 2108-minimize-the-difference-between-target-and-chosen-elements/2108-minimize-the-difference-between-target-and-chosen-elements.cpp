class Solution {
public:
    int m, n;
    int dp[70*70+1][70];
    int dfs(vector<vector<int>>& mat, int r, int sum, int target)
    {
        if(r>=m)
        return abs(sum-target);
        if(dp[sum][r]!=-1)
        return dp[sum][r];
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans, dfs(mat, r+1, sum+mat[r][i], target));
            if(ans==0)
            break;
        }
        return dp[sum][r]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp,-1,sizeof(dp));
        m=mat.size();
        n=mat[0].size();
        return dfs(mat, 0, 0, target);
    }
};