class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<long long> end(n);
        vector<long long> start(n);
        end[n-1] = nums[n-1];
        for(int i = n-2; i > 0; i--){
            end[i] = max((long long)nums[i], end[i+1]);
        }
        start[0] = nums[0];
        for(int i = 1; i < n; i++){
            start[i] = max((long long)nums[i], start[i-1]);
        }
        for(int i = 1; i < n-1; i++){
            long long val = (start[i-1] - (long long)nums[i])*end[i+1];
            ans = max(val, ans);
        }
        return ans;
    }
};