class Solution {
public:
//https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum/solutions/4175366/read-this-if-you-couldn-t-understand-from-any-other-solution-comment-if-you-still-have-a-doubt/
    long long MOD = 1000000007;
    int countSubMultisets(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int j = 0;

        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;

        for(int i = 0; i < n; i++){
            if(m.find(nums[i]) == m.end()){
                nums[j] = nums[i];
                j++;
            } 
            m[nums[i]]++;
        }

        nums.erase(nums.begin() + j, nums.begin()+n);

        n = j;

        vector<vector<int>> t(n+1, vector<int> (r+1, 0));

        for(int i = 0; i < n+1; i++){  
            t[i][0] = 1;
            if(nums[0] == 0) t[i][0] += m[0]; //for handling zero sum
        }

        for(int i = 1; i < n+1; i++){  
            for(int j = 1; j < r+1; j++){
                int freq = m[nums[i-1]];
                long long sum = 0;
                if((freq + 1) * nums[i-1] <= j){
                    sum = (t[i-1][j] + t[i][j-nums[i-1]] - t[i-1][j - (freq+1)*nums[i-1]] + MOD)%MOD;
                }
                else if(nums[i-1] <= j){
                    sum = t[i-1][j] + t[i][j-nums[i-1]];
                }
                else{
                    for(int cnt = 0; cnt <= freq; cnt++){
                        if(nums[i-1]*cnt <= j){
                            sum += t[i-1][j - nums[i-1]*cnt];
                        }
                    }
                }
                t[i][j] += sum % MOD;  
                // TLE
                // ll sum = 0;
                // for(int cnt = 0; cnt <= freq; cnt++){
                //     if(nums[i-1]*cnt <= j){
                //         sum += t[i-1][j - nums[i-1]*cnt]; 
                //         sum = sum % MOD;
                //     }
                // } 
                // t[i][j] += sum;   
            }
        }

        int ans = 0;  
        for (int i = l; i <= r; i++) {
            ans += t[n][i]; 
            ans %= MOD; 
        }
        return ans;
    }
};