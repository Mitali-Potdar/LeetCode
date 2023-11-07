class Solution {
public:
    vector<vector<int>> res;
    // void solve(vector<int> &nums, vector<int> temp, int k){
    //     if(k == nums.size()) {
    //         res.push_back(temp);
    //         return;
    //     }
        
    //     //exclude
    //     solve(nums, temp, k+1);
        
    //     //include
    //     temp.push_back(nums[k]);
    //     solve(nums, temp, k+1);
    // }
    void solve(vector<int> &nums, vector<int>& temp, int k){
        res.push_back(temp);
        for(int i = k; i < nums.size(); i++){
            temp.push_back(nums[i]);
            solve(nums, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, temp, 0);
        return res;
    }
};