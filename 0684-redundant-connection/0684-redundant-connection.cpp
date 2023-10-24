class Solution {
public:

bool dfs(int node, vector<int> visited, int parent, vector<vector<int>>& graph){

    visited[node] = 1;

    for(int child: graph[node]){
        if(visited[child] == 0){
            if(dfs(child, visited, node, graph)){
                return true;
            }
        }
        else if(child != parent) 
            return true;
    }
    
    return false;
}

vector<int> findRedundantConnection(vector<vector<int>>& A){
        int n = A.size();

        vector<int> visited (n+1, 0);
        vector<vector<int>> graph(n+1);
        for(int i = 0; i < n; i++){
            int f = A[i][0];
            int s = A[i][1];
            
            graph[f].push_back(s);
            graph[s].push_back(f); 

            if(dfs(f, visited, -1, graph)){
              return {f, s};
            }
        }
        
        return {};
    }
};