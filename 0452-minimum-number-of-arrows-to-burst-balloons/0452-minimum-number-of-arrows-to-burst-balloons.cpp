class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt = 1;
        sort(points.begin(), points.end());
        int lastpoint = points[0][1];
        for(auto p : points){
            if(p[0] > lastpoint){
                cnt++;
                lastpoint = p[1];
            }
            lastpoint = min(lastpoint, p[1]);
        }
        return cnt;
    }
};