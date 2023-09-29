class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    int countVowelSubstrings(string str) {
        int n = str.size();
        if(n < 5) return 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            unordered_set<char> s;
            for(int j = i; j < n; j++){
                if(isVowel(str[j])){
                    s.insert(str[j]);
                }
                else
                    break;
                if(s.size() == 5){
                    res++;
                }
            }
        }
        
        return res;
    }
};