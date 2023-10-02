class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        int l = 0;
        int r = 0;
        long long res = 0;
        unordered_map<int, int> m;
        int n = nums.size();
        while(r < n){
            m[nums[r]]++;
            sum += nums[r];
            while(m.size() != r-l+1 && l <= r){
                sum -= nums[l];
                m[nums[l]]--;
                if(m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }
            if(m.size() > k){
                sum -= nums[l];
                m[nums[l]]--;
                if(m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }
            if(m.size() == r-l+1  && r-l+1 == k){
                res = max(res, sum);
            } 
            
            r++;
        }
        return res;
    }
};