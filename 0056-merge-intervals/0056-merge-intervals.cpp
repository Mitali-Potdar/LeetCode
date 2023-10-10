class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> res;
        int i = 0;
        sort(interval.begin(), interval.end());
        for(i; i < interval.size()-1; i++){
            vector<int> v (2);
            if(interval[i][1] < interval[i+1][0]){
                res.push_back(interval[i]);
            } else {
                v[0] = interval[i][0];
                int u = interval[i][1];
                while(i < interval.size()-1 && u >= interval[i+1][0]){
                    u = max(u, interval[i+1][1]);
                    i++;
                }
                u = max(u, interval[i][1]);
                v[1] = u;
                res.push_back(v);
                v.empty();
            }
        }
        cout << i;
        if(i == interval.size() - 1) res.push_back(interval[i]);
        return res;
    }
};