class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map <char, int> m1;
        unordered_map <char, int> m2;
        for(int i = 0; i < s.size(); i++){
            m1[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            m2[t[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            if(m1[t[i]] != m2[t[i]] || m1.find(t[i]) == m1.end()){
                return t[i];
            }
        }
        return '0';
    }
};