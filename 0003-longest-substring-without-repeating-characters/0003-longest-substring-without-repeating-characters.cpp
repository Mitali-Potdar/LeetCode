class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
        int l = 0; 
        int r = 0;
        int n = s.size();
        int lmax = 0;
        while(l < n && r < n){
            if(m.find(s[r]) != m.end()){
                while(m.find(s[r]) != m.end() && l <= r){
                    m.erase(s[l]);
                    l++;
                }
                r--;
            } else {
                m.insert(s[r]);
                lmax = max(r-l+1, lmax);
            }
            r++;
        }
        return lmax;
    }
};