class Solution {
public:
    vector<vector<int>> dp{101,vector<int> (100001,-1)};
    int solve(int k, int n){
        if(dp[k][n] != -1){
            return dp[k][n];
        }
        if(k == 1) return dp[k][n] = n;
        if(n <= 1) return dp[k][n] = n;
        int res = INT_MAX;
        int l = 1;
        int h = n;
        while(l <= h){
            int mid = (l+h)/2;
            int left = solve(k-1, mid-1);
            int right = solve(k, n-mid);
            int temp = 1 + max(left, right);
            if(left < right){
                l = mid+1;
            } else h = mid - 1;
            res = min(res, temp);
        }
        // for(int i = 1; i <= n; i++){
        //     int temp = 1 + max(solve(k-1, i-1), solve(k, n-i));
        //     res = min(res, temp);
        // }
        return dp[k][n] = res;
    }
    int superEggDrop(int k, int n) {
        return solve(k, n);
    }
};