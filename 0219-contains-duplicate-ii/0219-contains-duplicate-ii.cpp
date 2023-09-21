class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int, int> m;
       for(int i = 0; i < nums.size(); i++){
           if(m.find(nums[i]) != m.end()){
               int dif = abs(m[nums[i]] - i);
               if(dif <= k){
                   return true;
               }
           }
           m[nums[i]] = i;
       } 
       return false;
    }
};