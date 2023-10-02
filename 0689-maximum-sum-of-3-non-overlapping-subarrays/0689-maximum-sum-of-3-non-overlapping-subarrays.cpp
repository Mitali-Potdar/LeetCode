class Solution {
public:
// https://www.geeksforgeeks.org/max-sum-of-m-non-overlapping-subarrays-of-size-k/

    void calculatePresumArray(vector<int> &prefix, vector<int>& nums, int n, int k){   
        for (int i = 0; i < k; i++)
            prefix[0] += nums[i];
    
        // store sum of array index i to i+k in presum array at index i of it.
        for (int i = 1; i <= n - k; i++)
            prefix[i] += prefix[i-1] + nums[i+k-1] - nums[i-1];
    }

    //m : number of subarrays
    int dp[20002][4];
    int maxSum(vector<int> &prefix, int m, int k, int i) {
        // if m is zero then no need any array of any size so return 0.
        if (m == 0)
            return 0;

        int n = prefix.size();
        // if start is greater then the size of presum array return 0.
        if (i >= n)
            return 0;

        if(dp[i][m] != -1) return dp[i][m];
    
        // if including subarray of size k
        int includeMax = prefix[i] + maxSum(prefix, m - 1, k, i + k);
    
        // if excluding element and searching in all next possible subarrays
        int excludeMax = maxSum(prefix, m, k, i + 1);
    
        // return max
        return dp[i][m] = max(includeMax, excludeMax);
    }

    void dfs(vector<int>& prefix, int k, int i, int m, vector<int>& res){
        int n = prefix.size();
        if(i >= n || m == 0){
            return;
        }
        
        int includeMax = prefix[i] + maxSum(prefix, m - 1, k, i + k);
        int excludeMax = maxSum(prefix, m, k, i + 1);
        
        if(includeMax >= excludeMax){
            res.push_back(i);
            dfs(prefix, k, i+k, m-1, res);
        }else{
            dfs(prefix, k, i+1, m, res);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1-k, 0);
        memset(dp, -1, sizeof(dp));
        calculatePresumArray(prefix, nums, n, k);
        maxSum(prefix, 3, k, 0);
        vector<int> res;
        dfs(prefix, k, 0, 3, res);
        return res;
    }
};