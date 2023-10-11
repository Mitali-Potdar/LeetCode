class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0, r = 0;
        int total = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            total += nums[i];
        }
        if(x > total) return -1;
        int target = total - x;
        if (target == 0) return n;
        int len = INT_MIN;
        int sum = 0;
        while(r < n){
            sum += nums[r];
            while(sum > target){
                sum -= nums[l];
                l++;
            }
            if(sum == target) len = max(len, r-l+1);
            r++;
        }
        if(len == INT_MIN) return -1;
        return n - len;
    }
};