class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        int neg = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                if(k > 0){
                    nums[i] = -nums[i];
                    k--;
                }
            }
            res += (nums[i]);
        }
        cout << k;
        if(k <= 0) return res;
        sort(nums.begin(), nums.end());
        if(k % 2 == 0) return res;
        else return res - 2*nums[0];
        return 0;
    }
};