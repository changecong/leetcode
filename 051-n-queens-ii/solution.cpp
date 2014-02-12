/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Feb 12 15:18:26 2014
 * Modified at:   Wed Feb 12 16:38:13 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:

    void updateChessboard(vector<vector<int> > &chess_board,
                          int n,
                          int row,
                          int q) {
        
        int i, j;
        
        // row doesn't matter
        // col
        for (i = row; i < n; ++i) chess_board[i][q] = 1;
        
        // diagonal right
        for (i = row, j = q; i < n && j < n; ++i, ++j) chess_board[i][j] = 1;
        
        // diagonal right
        for (i = row, j = q; i < n && j >= 0; ++i, --j) chess_board[i][j] = 1;
    }
        
        
    int totalNQueensRecursive(int n,
                              int row,
                              vector<vector<int> > &chess_board
        ) {
        
        int result = 0;
        
        if (row < n) {

            int temp = result;

            for (int q = 0; q < n; ++q) {
                
                if (chess_board[row][q] == 0) {  // valid

                    if (row == n - 1) {
                        result += 1;
                    } else {

                        // update chessboard
                        vector<vector<int> > temp_chess_board = chess_board;
                        updateChessboard(temp_chess_board, n, row, q);

                        result += totalNQueensRecursive(n, row + 1, temp_chess_board);
                    }
                }
                                
            }

            if (temp == result) return 0;  // all invalid

        } 

        return result;        
    }

public:
    int totalNQueens(int n) {
        
        vector<vector<int> > chess_board;

        // initial
        vector<int> temp;
        for (int i =0; i < n; ++i) temp.push_back(0);
        for (int i =0; i < n; ++i) chess_board.push_back(temp);

        return totalNQueensRecursive(n, 0, chess_board);
    }
};
    
int main() {

    Solution s;

    int n = 4;

    int result = s.totalNQueens(n);

    cout << "The result is: " << result << endl;

    return 0;
}
