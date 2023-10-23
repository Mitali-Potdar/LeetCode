class Solution {
public:
    int numWays(string s) {
        long long MOD = 1000000007;
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            if(s[i] == '1') cnt++;
        }
        if(cnt % 3 != 0) return 0;
        if(cnt == 0){
            long long res = (long long)(n-1)*(n-2);
            res = res/2;
            return res%MOD;
        }
        else{
            long long z1 = 0, z2 = 0;
            int one = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == '1') one++;
                if(one == cnt/3) z1++;
                if(one == 2*cnt/3) z2++;
            }
            int res = z1*z2 % MOD;
            return res;
        }
        return -1;
    }
};