class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int flag = 1;
        int i = 0;
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '-'){
            flag = -1;
            i++;
        }
        else if(s[i] == '+') i++;
        else if(!isdigit(s[i])) return 0;
        if(isdigit(s[i])){
            while(i < s.size() && isdigit(s[i])){
                ans = ans *10 + (s[i] - '0');
                if(ans*flag >= INT_MAX) return INT_MAX;
                if(ans*flag <= INT_MIN) return INT_MIN;
                i++;
            }
        } else return 0;

        return ans*flag;
        
    }
};