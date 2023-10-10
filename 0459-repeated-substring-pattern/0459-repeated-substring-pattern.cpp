class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // int n = s.size();
        // for(int i = 1; i <= n/2; i++){
        //     if(n % i == 0){
        //         string str = s.substr(0, i);
        //         //cout << str << " ";
        //         string repeated = "";
        //         for(int j  = 0; j < n/i; j++){
        //             repeated += str;
        //         }
        //         //cout << repeated << " ";
        //         if(s == repeated)return true;
        //     }
        // }
        // return false;
        int n=s.size();
        for(int i=n/2;i>=1;i--){                //commented below
            if(n%i==0){                                                             
                if(s.substr(0,n-i)==s.substr(i))return true;  //rotation approach-->if two substrings from first and last match then we can say they can repeatedly form the string.
            }
        }
        return false;
    }
};