class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        for(int i = 0; i < n; i++){
            m[s[i]]++;
        }
        int cnt = 0;
        int flag = 0;
        for(auto v: m){
            if(v.second % 2 == 0) cnt+= v.second;
            else{
                if(v.second > 1) cnt+= (v.second - 1); 
                flag = 1;
            }
        }
        if(flag == 1) cnt++;
        return cnt;
    }
};