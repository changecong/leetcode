/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Feb 11 19:50:35 2014
 * Modified at:   Wed Feb 12 15:10:43 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    string genRow(int q,  // the position of Q 
                  int n  // len of the row
        ) {
        
        string result = "";
        for (int i = 0; i < n; ++i) {
            if (i == q) {
                result += "Q";
            } else {
                result += ".";
            }
        }

        return result;
    }    

    void updateChessBoard(int n,
                          vector<vector<int> > &t_board,
                          int row,
                          int q
        ) {
        
        // row doesn't matter
        for(int i = 0; i < n; ++i) t_board[row][i] = 1;
        // col
        for(int i = 0; i < n; ++i) t_board[i][q] = 1;
        // diagonal right
        int i , j;
        for(i = row, j = q; i < n && j < n; ++i, ++j) t_board[i][j] = 1;
        // diagonal left
        for(i = row, j = q; i < n && j >= 0; ++i, --j) t_board[i][j] = 1;
    }

    vector<vector<string> > solveNQueensRecursive(int n, 
                                                  int row,  // current row
                                                  vector<vector<int> > t_board  // current chessboard
        ) {
        
        vector<vector<string> > result;

        if (row < n) {
        
            int size = result.size();

            for (int q = 0; q < n; ++q) {
                
                if (t_board[row][q] == 0) {  // valid blank
                
                    // update chessboard
                    vector<vector<int> > t_temp = t_board;
                    updateChessBoard(n, t_temp, row, q);

                    vector<vector<string> > temp = solveNQueensRecursive(n, row + 1, t_temp);
                    
                    string new_line = genRow(q, n);
                    // combine
                    
                    if (!temp.empty() ) {

                        for (int i = 0; i < temp.size(); ++i) {
                            temp[i].push_back(new_line);
                            result.push_back(temp[i]);
                        }                        
                    }
                    if (row == (n - 1)) {
                        vector<string> s_temp;
                        s_temp.push_back(new_line);
                        result.push_back(s_temp);
                    } 
                }
            }
            
            if (size == result.size()) {  // if the last row, skip
                vector<vector<string> > empty;
                return empty;
            }


        }

        return result;
    }

public:
    vector<vector<string> > solveNQueens(int n) {

        vector<vector<string> > result;

        if (n == 0) return result;

        if (n == 1) {
            vector<string> temp;
            temp.push_back("Q");
            result.push_back(temp);
            return result;
        }

        if (n == 2 || n == 3) {
            return result;
        }

        // gen a n x n chessboard
        vector<int> t_row;
        vector<vector<int> > t_board;
        for (int i = 0; i < n; ++i) t_row.push_back(0);
        for (int i = 0; i < n; ++i) t_board.push_back(t_row);
        
        
        return solveNQueensRecursive(n, 0, t_board);

    }
};


int main() {

    Solution s;

    int n = 7;

    vector<vector<string> > result = s.solveNQueens(n);

    for(int i = 0; i < result.size(); ++i) {
        
        for (int j = 0; j < n; ++j) {
            cout << result[i][n - j - 1] << endl;
        }

        cout << endl;
    }
    
    return 0;
}
