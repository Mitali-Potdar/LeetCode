class Solution {
public:
    bool isAnagram(string s, string t) {
        // unordered_map <char, int> m1;
        // unordered_map <char, int> m2;
        // if(s.size() != t.size()) return false;
        // for(int i = 0; i < s.size(); i++){
        //     m1[s[i]] ++; 
        // }
        // for(int i = 0; i < t.size(); i++){
        //     m2[t[i]] ++; 
        // }
        // for(int i = 0; i < s.size(); i++){
        //     if(m1[s[i]] != m2[s[i]]){
        //         return false;
        //     }
        // }
        // return true;
        // if (s.size() != t.size()) {
        //     return false;
        // }
        
        vector<int> count(26);
        
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        
        for (int j = 0; j < t.size(); j++) {
            count[t[j] - 'a']--;
            if (count[t[j] - 'a'] < 0) {
                return false;
            }
        }
        for(int i = 0; i < 26; i ++){
            if(count[i] > 0){
                return false;
            }
        }
        return true;

    }
};