#include <bits/stdc++.h>

bool isSafe(int row,int col,vector<vector<int>>& board,int val,int n){
    
    for(int i=0;i<n;i++){
        if(board[row][i] == val){
            return false;
        }

        if(board[i][col] == val){
            return false;
        }

        if(board[3*(row/3) + i/3][3*(col/3)+i%3] == val){
            return false;
        } 
    }
    return true;
}

bool solve(vector<vector<int>>& board){
    int n = board[0].size();

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col] == 0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col,board,val,n)){
                        board[row][col] = val;
                        bool possible = solve(board);
                        if(possible){
                            return true;
                        } else {
                          board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}

int main(){
    vector<vector<int>> sudoku;
    int n;
    cin >> n;
    for(int i = 0; i< n ; i++){
        for(int j = 0; j<n; j++){
            cin >> sudoku[i][j];
        }
    }
    solveSudoku(sudoku);
    return 0;
}