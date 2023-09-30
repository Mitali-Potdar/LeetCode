class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> set;
        for(auto it:nums) if(it!=0) set.insert(it);
        return set.size();
    }
};