class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1)nums[i] = 1;
            else nums[i] = 0;
        }
        int res = 0;
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            m[sum]++;
            if(m.find(sum-k) != m.end()){
                res += m[sum-k];
            }
        }
        return res;
    }
};