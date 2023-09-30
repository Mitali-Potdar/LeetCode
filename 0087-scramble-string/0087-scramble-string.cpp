class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.length() != s2.length()) return false;
        int n = s1.size();
        if(n == 0) return true;
        string str1 = s1;
        sort(str1.begin(), str1.end());
        string str2 = s2;
        sort(str2.begin(), str2.end());
        if( str1 != str2) return false;
        bool flag = false;
        string key = s1 + " " + s2;
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        for(int i = 1; i < n; i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i))){
                flag = true;
                break;
            }
            if(isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i))){
                flag = true;
                break;
            } 
            mp[key] = flag;       
        }
        return flag;
    }
};