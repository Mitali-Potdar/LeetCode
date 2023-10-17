class Solution {
public:
    int countPrimes(int n) {
        vector<bool> dp(n+1, true);
        dp[0] = false;
        dp[1] = false;
        //dp[2] = true;
        for(int i = 2; i*i <= n; i++){
            if(dp[i]){
                for(int j = i*2; j < n; j += i){
                    dp[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(dp[i] == true) cnt++;
        }
        return cnt;
    }
};