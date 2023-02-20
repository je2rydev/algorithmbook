// 51. N-Queen
class Solution {
private:
    vector<vector<string>> result;
    vector<vector<int>> board;
    void makeBoard(int n){
        vector<string> tmp;
        for(int i=0; i<n; i++){
            string str = "";
            for(int j=0; j<n; j++){
                if(board[i][j]==1)
                    str += "Q";
                else
                    str += ".";
            }
            tmp.push_back(str);
        }
        result.push_back(tmp);
    }

    bool checkVertical(int cur, int n){
        for(int i=cur ; i>=0 ; i--){
            cout << i << endl;
            if(board[i][n] == 1)
                return false;
        }
        return true;
    }

    bool checkDiagonal(int cur, int n){
        for(int i=cur ; i>=0 ; i--){
            if(cur-i >= 0 && n-i >= 0)
                if(board[cur-i][n-i] == 1)
                    return false;
        }
        for(int i=cur ; i>=0 ; i--){
            if(cur-i >= 0 && n+i < board.size())
                if(board[cur-i][n+i] == 1)
                    return false;
        }
        return true;
    }

    // cur 
    void backtrackingNQueens(int n, int cur){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << endl;

        if(cur == board.size()){
            makeBoard(n);
            return;
        }
        for(int i=0; i<n; i++){
            if(cur == 0 || (checkVertical(cur, i) && checkDiagonal(cur, i))){
                board[cur][i] = 1;
                backtrackingNQueens(n, cur+1);
                board[cur][i] = 0;
            }
        }
    }

public:


    vector<vector<string>> solveNQueens(int n) {
        board = vector<vector<int>>(n,vector <int>(n,0));
        backtrackingNQueens(n, 0);
        return result;
    }
};