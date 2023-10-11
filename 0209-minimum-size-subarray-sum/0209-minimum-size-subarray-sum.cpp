class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
        while(r < n){
            sum += nums[r];
            r++;
            while(sum >= target){
                len = min(len, r-l);
                sum -= nums[l];
                l++;
            }
        }
        if(len == INT_MAX)return 0;
        return len;
    }
};