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
            int x = n-1;
            long long res = 0;
            for(long long i = 1; i < x; i++){
                res += i;
            }
            res = res % MOD;
            return res;
        }
        else{
            int x = cnt/3;
            long long z1 = 0, z2 = 0;
            int i = 0;
            int one = 0;
            while(one < x){
                if(s[i] == '1') one++;
                i++;
            } 
            while(s[i] != '1'){
                z1++;
                i++;
            }
            one = 0;
            while(one < x){
                if(s[i] == '1') one++;
                i++;
            }
            while(s[i] != '1'){
                z2++;
                i++;
            }
            int res = (z1+1)*(z2+1) % MOD;
            return res;
        }
        return -1;
    }
};