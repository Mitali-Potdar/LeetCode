class Solution {
public:
    int atMost(string nums, int k){
        if( k < 0) return 0;
        unordered_map<int, int> m;
        int l = 0;
        int cnt = 0;
        for(int r = 0; r < nums.size(); r++){
            m[nums[r]]++;
            while(m.size() > k){
                m[nums[l]]--;
                if(m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }
            cnt += r-l+1;
        }
        return cnt;
    }

    int numberOfSubstrings(string s) {
        return atMost(s, 3) - atMost(s, 2);
    }
};