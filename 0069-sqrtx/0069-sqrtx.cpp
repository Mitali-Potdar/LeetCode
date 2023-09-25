class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x <= 3)return 1;
        int low = 1;
        int high = x/2;
        int mid;
        while(high >= low){
            mid = low + (high-low)/2;
            // mid * mid == x gives runtime error
            if(mid == x/mid) return mid;
            if(mid > x/mid){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low-1;
    }
};