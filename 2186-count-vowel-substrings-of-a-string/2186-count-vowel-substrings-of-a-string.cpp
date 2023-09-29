class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int atMostK(string str, int k){
        int n = str.size();
        int res = 0;
        unordered_map<char, int> mp;
        int l = 0;
        for(int r = 0; r < n; r++){
            if(!isVowel(str[r])){
                    mp.clear();
                    l = r + 1;
                    continue;
            }
            else
            {
                mp[str[r]]++;
    
                while(l <= r && mp.size() > k){
                    mp[str[l]]--;
                    if(mp[str[l]] == 0){
                        mp.erase(str[l]);
                    }
                    l++;
                }
                res += r-l+1;
            }
        }
        return res;
    }
    int countVowelSubstrings(string str) {
        return atMostK(str, 5) - atMostK(str, 4);
    }
};