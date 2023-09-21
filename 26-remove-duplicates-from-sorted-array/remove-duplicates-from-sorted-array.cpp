class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x = nums[0];
        int k = nums.size();
        for(int i = 1; i < k; i++){
            if(nums[i] == x){
                nums.erase(nums.begin() + i);
                i--;
                k--;
            }
            else{
                x = nums[i];
            }
        }
        return k;
    }
};