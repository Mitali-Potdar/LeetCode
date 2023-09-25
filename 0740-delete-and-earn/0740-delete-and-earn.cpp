class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        vector<int> cnt(10002);
		for(int i = 0; i < nums.size(); i++){
			cnt[nums[i]] += nums[i];
		}

		vector<int> dp(10002);
		dp[1] = cnt[1];
		dp[2] = max(cnt[1], cnt[2]);
		for(int i = 3; i < dp.size(); i++)
		{
			dp[i] = max(dp[i-2] + cnt[i], dp[i-1]);
		}

		return max(dp[10000], dp[9999]);
    
        // sort(nums.begin(), nums.end());
        // unordered_map<int, int> count;
        // for(int i = 0; i < nums.size(); i++){
        //     if(count.find(nums[i]) != count.end()){
        //         nums.erase(nums.begin() + i);
        //         i--;
        //     }
        //     count[nums[i]]++;
        // }

        // int n = nums.size();
        // int earn1 = nums[0]*count[nums[0]];
        // if(n == 1) return earn1;
        // int earn2, temp;
        // if(nums[0] == nums[1] - 1)
        //     earn2 = max(earn1, nums[1]*count[nums[1]]);
        // else 
        //     earn2 = earn1 + nums[1]*count[nums[1]];

        // for(int i = 2; i < n; i++){
        //     if(nums[i-1] == nums[i]-1){
        //         temp = max(earn1 + nums[i]*count[nums[i]], earn2);
        //     }
        //     else{
        //         temp = earn2 + nums[i]*count[nums[i]];
        //     }
        //     earn1 = earn2;
        //     earn2 = temp;
        // }
        // return earn2;

        // vector <int> dp (n, -1);
        // dp[0] = nums[0]*count[nums[0]];
        // if(n == 1) return dp[0];
        // if(nums[0] == nums[1] - 1)
        //     dp[1] = max(dp[0], nums[1]*count[nums[1]]);
        // else 
        //     dp[1] = dp[0] + nums[1]*count[nums[1]];
        // for(int i = 2; i < n; i++){
        //     if(nums[i-1] == nums[i]-1){
        //         dp[i] = max(dp[i-2] + nums[i]*count[nums[i]], dp[i-1]);
        //     }
        //     else{
        //         dp[i] = dp[i-1] + nums[i]*count[nums[i]];
        //     }
        // }

        // return dp[n-1];
    }
};