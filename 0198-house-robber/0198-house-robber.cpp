class Solution {
public:
		int rob(vector<int> &nums){
			int n = nums.size();
			vector <int> dp(n, -1);
			dp[0] = nums[0];
			if(n == 1) return dp[0];
			dp[1] = max(dp[0], nums[1]);
			for(int i = 2; i < n; i++){
				dp[i] = max(dp[i-1], dp[i-2] + nums[i]);  //don't really need an array, can just keep variables for the last values and keep on calculating -> optimised
			}
			return dp[n-1];
		}
    // int Memoization(int i, vector<int> &nums, vector<int> &dp){
		// 	if(i == 0){
		// 		return nums[0];
		// 	}
		// 	if(i < 0)
		// 		return 0;
		// 	if(dp[i] != -1){
		// 		return dp[i];
		// 	} else
		// 		return dp[i] = max(nums[i] + Memoization(i-2, nums, dp), Memoization(i-1, nums, dp));     	    
		// }

    // int rob(vector<int> &nums){
    //   int n = nums.size();
    //   vector<int> dp(n, -1);
    //   return Memoization(n-1, nums, dp);
    // }
};