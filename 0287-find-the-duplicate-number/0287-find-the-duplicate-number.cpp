class Solution {
public:
//https://leetcode.com/problems/find-the-duplicate-number/solutions/560089/c-4-different-solutions-beats-100-detailed-explanantion/?envType=study-plan-v2&envId=top-100-liked
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            
            // mark as visited
            nums[index] *= -1;
            // incase of duplicate, this will become +ve 
            if(nums[index] > 0)
                return abs(nums[i]);
        }    
        return -1;
    }
};