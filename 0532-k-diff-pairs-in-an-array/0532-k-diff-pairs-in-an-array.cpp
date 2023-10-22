class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //O(N)
        int n = nums.size();
        unordered_map<int, int> m;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }  
        if(k == 0){
            for(auto v: m){
               if(v.second > 1)
                cnt++;
            }
        } else {
            for(auto v: m){
                int s = k + v.first;
                if(m.find(s) != m.end()){
                    cnt++;
                }
            }
        }
        return cnt;
        //O(NLOGN)

        // int l = 0;
        // int r = 1;
        // int cnt = 0;
        // sort(nums.begin(), nums.end());
        // while(r < nums.size()){
        //     if(nums[r] - nums[l] == k){
        //         cnt++;
        //         l++;
        //         r++;
        //         while(r < nums.size() && nums[r] == nums[r-1]){
        //             r++;
        //         }
        //     }
        //     else if(nums[r] - nums[l] > k){
        //         l++;
        //         if(l == r) r++;
        //     } else{
        //         r++;
        //     }
        // }
        // return cnt;    
    }
};