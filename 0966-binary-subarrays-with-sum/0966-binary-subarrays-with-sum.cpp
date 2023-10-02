class Solution {
public:
    int atMost(vector<int>& nums, int k){
        if(k < 0)return 0;
        int l = 0;
        int sum = 0;
        int cnt = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum > k){
                sum -= nums[l];
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
        // unordered_map<int, int> m;
        // int sum = 0;
        // m[0] = 1;
        // int cnt = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     sum += nums[i];
        //     if(m.find(sum-k) != m.end()){
        //         cnt += m[sum-k];
        //     }
        //     m[sum]++;
        // }
        // return cnt;
    }
};