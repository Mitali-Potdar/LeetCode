class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(s.find(board[i][j]) != s.end()) return false;
                if(board[i][j] != '.') s.insert(board[i][j]);
            }
            s.clear();
        }
        for(int j = 0; j < 9; j++){
            for(int i = 0; i < 9; i++){
                if(s.find(board[i][j]) != s.end()) return false;
                if(board[i][j] != '.') s.insert(board[i][j]);
            }
            s.clear();
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                int k = 2;
                while(k >= 0){
                    int l = 2;
                    while(l >= 0){
                        if(s.find(board[i+k][j+l]) != s.end()) return false;
                        if(board[i+k][j+l] != '.') s.insert(board[i+k][j+l]);
                        l--;
                    }
                    k--;
                }
                s.clear();
            }
            s.clear();
        }
        return true;
    }
};