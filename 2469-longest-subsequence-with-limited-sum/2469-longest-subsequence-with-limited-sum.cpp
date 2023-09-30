class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }
        for(int i = 0; i < q.size(); i++){
            int flag = 0;
            for(int j = n-1; j >= 0; j--){
                if(q[i] >= nums[j]){
                    q[i] = j+1;
                    flag = 1;
                    break;
                } 
            }
            if(flag == 0) q[i] = 0;
        }
        return q;
    }
};