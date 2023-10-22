class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int l = 0;
        int r = 1;
        int cnt = 0;
        sort(nums.begin(), nums.end());
        while(r < nums.size()){
            if(nums[r] - nums[l] == k){
                cnt++;
                l++;
                r++;
                while(r < nums.size() && nums[r] == nums[r-1]){
                    r++;
                }
            }
            else if(nums[r] - nums[l] > k){
                l++;
                if(l == r) r++;
            } else{
                r++;
            }
        }
        return cnt;    
    }
};