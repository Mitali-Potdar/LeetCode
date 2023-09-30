class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums[nums.size()-1];
        int ans = n*k;
        ans += (k)*(k-1)/2 ;
        return ans;
    }
};