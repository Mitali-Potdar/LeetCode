class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        if(n % 2 == 0){
            for(int i = 1; i <= n/2; i++){
                ans += 2*i - 1;
            }
        } else { //odd
            for(int i = 1; i <= n/2; i++){
                ans += 2*i;
            }
        }
        return ans;
    }
};