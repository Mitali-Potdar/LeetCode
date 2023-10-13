class Solution {
public:
    int find_max(int l, int h, vector <int>& ar){
        int maxi = 0;
        for(int i = l; i <= h; i++){
            maxi = max(ar[i], maxi);
        }
        return maxi;
    }
    int soln(vector<int> a, int s, int e, vector<vector<int>> &dp){
        if(s == e)
            return dp[s][e] = 0;

        if(dp[s][e] != -1)
            return dp[s][e];
        
        int ans = INT_MAX;
        
        for(int i = s; i < e; i++){
            int one = soln(a, s, i, dp);
            int two = soln(a, i+1, e, dp);
            int tmp = one + two + (find_max(s, i, a))*(find_max(i+1, e, a));
            
            ans = min(ans, tmp);
        }
        
        return dp[s][e] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(50,vector<int>(50,-1));
        return soln(arr, 0, arr.size()-1, dp);
    }
};