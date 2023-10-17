class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> dp(right+1, true);
        dp[0] = false;
        dp[1] = false;
        //dp[2] = true;
        for(int i = 2; i*i <= right; i++){
            if(dp[i]){
                for(int j = i*2; j <= right; j += i){
                    dp[j] = false;
                }
            }
        }
        vector<int> res(2, -1);
        vector<int> v;
        for(int i = left; i <= right; i++){
            if(dp[i]){
                v.push_back(i);
            }
        }
        int diff = INT_MAX;
        int n1 = -1, n2 = -1;
        for(int i = 1; i < v.size(); i++){
            int m = v[i] - v[i-1];
            if(m < diff){
                diff = m;
                n1 = v[i-1];
                n2 = v[i];
            }
        }
        if(n1 != -1 && n2 != -1){
            res[0] = n1;
            res[1] = n2;
        }
        return res;
    }
};