class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        if(m > n) {
            swap(a, b);
            swap(m, n);
        }
        for(int i = 0; i < (n-m); i++){
            b = "0" + b;
        }
        string ans = "";
        int flag = 0;
        for(int i = n-1; i >= 0; i--){
            if(flag == 0){
                if(a[i] == '0' && b[i] == '0'){
                    ans = "0" + ans;
                } else if((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')){
                    ans = "1" + ans;
                } else if(a[i] == '1' && b[i] == '1'){
                    ans = "0" + ans;
                    flag = 1;
                }
            } else if (flag == 1){
                if(a[i] == '0' && b[i] == '0'){
                    ans = "1" + ans;
                    flag = 0;
                } else if((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')){
                    ans = "0" + ans;
                } else if(a[i] == '1' && b[i] == '1'){
                    ans = "1" + ans;
                }
            }
        }
        if(flag == 1){
            ans = "1" + ans;
        }
        return ans;
    }
};