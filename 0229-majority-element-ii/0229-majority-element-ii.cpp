class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        vector<int> res;
        for(auto x : m){
            if(x.second > n/3){
                res.push_back(x.first);
            }
        }
        return res;
    }
};