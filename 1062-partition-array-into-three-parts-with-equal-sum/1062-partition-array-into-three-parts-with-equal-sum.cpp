class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        if(sum % 3 != 0) return false;
        int curr = 0;
        int p = 0;
        for(int i = 0; i < n; i++){
            curr += arr[i];
            if(curr == sum/3){
                p++;
                curr = 0;
                if (p == 2 && i != n-1) {
                    return true;
                }
            }
        }
        return false;
    }
};