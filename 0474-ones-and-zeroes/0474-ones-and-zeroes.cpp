class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int l = strs.size();
    for(int i = 0; i < l; i++){
        int zero = 0;
        int one = 0;
        for(auto s : strs[i]){
            if(s == '1') one++;
            else zero++;
        }
        //since we are updating for every new string in vector and we want value from prev dp matrix of prev string values we start from bottom right and not top left the dp[j-zero][k-one] is without the values of this new string, ie the previously filled dp matrix value at that location
        for(int j = m; j >= 0; j--){
            for(int k = n; k >= 0; k--){  
                if(one <= k && zero <= j) dp[j][k] = max(dp[j][k], dp[j-zero][k-one] + 1);
            }
        }
    }
    return dp[m][n];
    }
};