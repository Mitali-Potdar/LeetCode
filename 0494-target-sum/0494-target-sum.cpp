class Solution {
public:
    int dp(vector<int>& nums, int s, int n){
        int t[n+1][s+1];
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < s+1; j++){
                if(i == 0) t[i][j] = 0;
                if(j == 0) t[i][j] = 1;
            }
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < s+1; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j - nums[i-1]] + t[i-1][j];
                } else t[i][j] = t[i-1][j];
            }
        }
        return t[n][s];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if((sum+target)%2 != 0) return 0;
        if(sum < target) return 0;
        int s = (sum + target)/2;
        if(s < 0) return 0;
        return dp(nums, s, n);
    }

};