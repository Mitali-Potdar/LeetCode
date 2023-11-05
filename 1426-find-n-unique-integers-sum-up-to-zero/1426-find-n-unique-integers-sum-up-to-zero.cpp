class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr;
        int m = n/2;
        if(n%2 == 0){
            int k = m;
            while(k){
                arr.push_back(-k);
                k--;
            }
            k = m;
            while(k){
                arr.push_back(k);
                k--;
            }
        } else {
            int k = m;
            while(k){
                arr.push_back(-k);
                k--;
            }
            arr.push_back(0);
            k = m;
            while(k){
                arr.push_back(k);
                k--;
            }
        }
        return arr;
    }
};