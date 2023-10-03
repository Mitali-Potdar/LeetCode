class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else 
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        int i = m;
        int j = n;
        string s = "";
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                s = str1[i-1] + s;
                i--;
                j--;
            } else if(dp[i][j-1] > dp[i-1][j]){
                s = str2[j-1] + s;
                j--;
            } else{
                s = str1[i-1] + s;
                i--;
            }
        }
        while(i > 0){
            s = str1[i-1] + s;
                i--;
        }
        while(j > 0){
            s = str2[j-1] + s;
                j--;
        }
        return s;
    }
};