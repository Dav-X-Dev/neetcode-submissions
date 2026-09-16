class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //container for rows cols n 3x3s that track dupes
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        map<pair<int, int>, unordered_set<char>> treys;

        for (int r = 0; r < 9; r++){
            for (int c = 0; c < 9; c++){

                if (board[r][c] == '.'){
                    continue;
                }

                
                if (rows[r].count(board[r][c]) || cols[c].count(board[r][c])
                || treys[{r/3 , c/3}].count(board[r][c])){
                    return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                treys[{r/3 , c/3}].insert(board[r][c]);
            }
        }  

        return true;      
    }
};
