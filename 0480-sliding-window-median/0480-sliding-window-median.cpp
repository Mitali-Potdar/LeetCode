class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<double> window(begin(nums), begin(nums) + k);
        auto it = next(begin(window), (k - 1) / 2);      //take the iterator to mid position
         
        for(int i=k; ;++i){
            const double median = ((k & 1) ? *it : (*it + *next(it)) / 2.);
            ans.emplace_back(median);
            
            if(i == nums.size()) break;
            
            window.insert(nums[i]);
            
            if(nums[i] < *it)    // If the inserted number is smaller than mid, obviously the iterator must have moved one position ahead..... which means we should take it one step backwards
                --it;
            if(nums[i - k] <= *it)    // If the number inserted k steps before is smaller than or equal to the mid, the iterator must have moved one position backwards, because of which we should move it forward by one.
                ++it;
            
            window.erase(window.lower_bound(nums[i - k]));
        }
        return ans;
    }
};