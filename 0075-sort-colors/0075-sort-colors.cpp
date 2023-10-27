class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int j = n-1;
        int k = 0;
        while(k <= j){
            if(nums[k] == 2){
                swap(nums[k], nums[j]);
                j--;
            }
            else if(nums[k] == 0){
                swap(nums[k], nums[i]);
                i++;
                k++;
            }
            else{
                k++;
            }
        }
    }
};