class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        while(start && goal){
            cnt += (start&1) ^ (goal&1);
            start >>= 1;
            goal >>= 1;
        }
        while(start){
            cnt += (start&1);
            start >>= 1;
        }
        while(goal){
            cnt += (goal&1);
            goal >>= 1;
        }
        return cnt;
    }
};