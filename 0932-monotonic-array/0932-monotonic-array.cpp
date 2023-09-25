class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag = 1;
        int n = nums.size();
        for(int i = 0; i < n-1; i ++){
            if(nums[i] <= nums[i+1]){
                flag = 1;
                continue;
            } else{
                flag = 0;
                break;
            }
        }
        if(flag == 1) return true;

        for(int i = 0; i < n-1; i ++){
            if(nums[i] >= nums[i+1]){
                flag = 1;
                continue;
            } else{
                flag = 0;
                break;
            }
        }

        if(flag == 1) return true;
        return false;
    }
};