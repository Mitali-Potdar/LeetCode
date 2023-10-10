//Since you cannot rob both the first and last house, just create two separate vectors, one excluding the first house, and another excluding the last house. The best solution generated from these two vectors using the original House Robber DP algorithm is the optimal one.

class Solution {
public:
    int robbing(vector<int>& nums){
        int rob1 = nums[0];
        int rob2 = max(nums[0], nums[1]);
        int temp;
        for(int i = 2; i < nums.size(); i++){
            temp = max(rob2, rob1 + nums[i]);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int temp = nums[nums.size()-1];
        nums.erase(nums.begin() + nums.size()-1);
        int l = robbing(nums);
        nums.erase(nums.begin());
        nums.push_back(temp);
        int f = robbing(nums);
        return max(l, f);
    }
};