class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(number[i] == digit)
                cnt++;
        }
        string res = "";
        for(int i = 0; i < n; i++){
            if(number[i] == digit && cnt > 0){
                if(cnt == 1){
                    res = number.substr(0, i) + number.substr(i+1, n-i-1);
                    return res;
                }
                if(number[i+1] > number[i]){
                    res = number.substr(0, i) + number.substr(i+1, n-i-1);
                    return res;
                } else cnt--;
            }
        }
        return res;
    }
};