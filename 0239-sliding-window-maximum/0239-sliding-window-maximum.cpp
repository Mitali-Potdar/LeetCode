class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> id;//Double-ended queue storing index for max
        vector<int> res;

        for(int i = 0; i < n; i++){
            while(!id.empty() && nums[i] >= nums[id.back()]) 
                id.pop_back();// pop back the indexes for smaller ones

            id.push_back(i);  // push back the index for larger one

            if (id.front() == i-k) // index=i-k should not in the window
                id.pop_front(); 

            if (i >= k-1)
                res.push_back(nums[id.front()]); //Max element for this window
        }
        return res;
    }
};