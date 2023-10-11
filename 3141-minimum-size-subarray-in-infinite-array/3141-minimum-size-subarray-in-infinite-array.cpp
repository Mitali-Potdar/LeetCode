class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        int res = 0;
        vector<int> v(3*n, 0);
        long lsum = 0;
        for(int i = 0; i < n; i++){
            v[i] = nums[i];
            v[n+i] = nums[i];
            lsum += nums[i];
        }
        int N = 2*n;
        if(target >= lsum){
            int m = target/lsum; 
            res = m*n;
            target = target%lsum;
            if(target == 0) return res;
        }
        int l = 0;
        int r = 0;
        int sum = 0;
        int len = INT_MAX;
        while(r < N){
            sum += v[r];
            while(sum > target){
                sum -= v[l];
                l++;
            } 
            if(sum == target) len = min(len , r-l+1);
            r++;
        }
        if(len == INT_MAX)return -1;
        return res+len;
    }
};