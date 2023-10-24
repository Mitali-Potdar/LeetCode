class Solution {
public:
//https://leetcode.com/problems/erect-the-fence/solutions/1442266/a-detailed-explanation-with-diagrams-graham-scan/?envType=list&envId=pxi2crhg

    int slope(vector<int> p1, vector<int> p2, vector<int> p3){
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        int x3 = p3[0], y3 = p3[1];
        return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int sz = trees.size();

        if(sz <= 3){
            return trees;
        }

        sort(trees.begin(), trees.end());
        
        vector<vector<int>> lower, upper;

        // for Upper Hull
        for(int j = 0; j < sz; j++) {
            int n = upper.size();    
            while (n >= 2 && slope(upper[n - 2], upper[n-1], trees[j]) < 0) {
                upper.pop_back();
                n--;
            }
            upper.push_back(trees[j]);
        }

        // for Lower Hull
        for(int j = sz-1; j >= 0; j--) {
            int m = lower.size();    
            while (m >= 2 && slope(lower[m - 2], lower[m-1], trees[j]) < 0) {
                lower.pop_back();
                m--;
            }
            lower.push_back(trees[j]);
        }
        
        set<vector<int>> result(lower.begin(), lower.end());
        for(auto point : upper) {
            result.insert(point);
        }
        
        return vector<vector<int>> (result.begin(), result.end());
    }
};