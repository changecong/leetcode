/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Feb  7 12:52:33 2014
 * Modified at:   Fri Feb  7 13:31:33 2014
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

    bool isValid(vector<vector<char> > &board,
                 int row, int col) {
        
        int size = 9;
        
        // check the row
        for (int i = 0; i < size; ++i) {
            if (i != col && board[row][i] == board[row][col]) {
                return false;
            }
        }

        // check the col
        for (int i = 0; i < size; ++i) {
            if (i != row && board[i][col] == board[row][col]) {
                return false;
            }
        }

        // check the block
        int tx = (row / 3) * 3;
        int ty = (col / 3) * 3;
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tx + i != row && ty + j != col && board[tx+i][ty+j] == board[row][col]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solveSudokuRecursive(vector<vector<char> > &board) {

        int size = 9;

        // for each cell
        for (int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) {
                
                if ('.' == board[i][j]) {  // blank cell
                    
                    for (int v = 0; v < size; ++v) {
                        board[i][j] = '1' + v;

                        if (isValid(board, i, j) && solveSudokuRecursive(board)) {
                            // a valid answer
                            return true;
                        }

                        board[i][j] = '.';

                    }

                    // assume there is one unique answer
                    return false;

                }
                
            }

        }

        return true;

    }

public:
    void solveSudoku(vector<vector<char> > &board) {
    
        solveSudokuRecursive(board);
    }

};

int main() {

    /*Too lazy to write a test sample*/

    return 0;
}
