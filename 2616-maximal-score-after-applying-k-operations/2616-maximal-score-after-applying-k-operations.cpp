class Solution {
public:
long long score = 0;
priority_queue<int> pq;

    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
        }
        while(k){
            int val = pq.top();
            pq.pop();
            score += val;
            if(val % 3 == 0) val = val/3;
            else val = val/3 + 1;
            pq.push(val);
            k--;
        }
        return score;
    }
};