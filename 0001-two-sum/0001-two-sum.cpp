class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int dif = target - nums[i];
            if(m.find(dif) != m.end() && i != m[dif]){
                ans.push_back(i);
                ans.push_back(m[dif]);
                return ans;
            }
        }
        return ans;

        // vector<int> ans;
        // for(int i = 0; i < nums.size(); i++){
        //     int t = target - nums[i];
        //     ans.push_back(i);
        //     for(int j = i+1; j < nums.size(); j++){
        //         if(nums[j] == t){
        //             ans.push_back(j);
        //             return ans;
        //         } 
        //         else
        //             continue;  
        //     }
        //     ans.pop_back();
        // }
        // return ans;
    }
};