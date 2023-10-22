class Solution {
public:
long long score = 0;
priority_queue<pair<int,int>> pq;

    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }
        while(k){
            int val = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            score += val;
            if(nums[ind] % 3 == 0) nums[ind] = nums[ind]/3;
            else nums[ind] = nums[ind]/3 + 1;
            pq.push({nums[ind], ind});
            k--;
        }
        return score;
    }
};