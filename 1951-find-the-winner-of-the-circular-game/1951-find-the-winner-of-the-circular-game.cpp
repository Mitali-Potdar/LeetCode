class Solution {
public:
//https://cs.stackexchange.com/questions/7048/a-recursive-formula-for-generalized-josephus-problem
//Finally only one zero will be left
//We want the old position of that 0
    int helper(int n, int k){
        if(n == 1)
            return 0;
        return (helper(n-1, k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        //return helper(n, k) + 1; //since we are taking zero indexed
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for(int i = 1; i < n+1; i++){
            dp[i] = (dp[i-1] + k) % i;
        }
        return dp[n]+1 ;
    }
};