/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Feb 11 19:50:35 2014
 * Modified at:   Tue Feb 11 22:16:41 2014
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

    vector<vector<string> > solveNQueens(int n,  // the size
                                         vector<int> &idx  // valid indics
        ) {
        
        vector<vector<string> > result;
    }

public:
    vector<vector<string> > solveNQueens(int n) {

        vector<vector<string> > result;

        if (n == 0) return result;

        if (n == 1) {
            vector<string> temp;
            temp.push_back("Q");
            result.push_back(tmep);
            return result;
        }

        if (n == 2 || n == 3) {
            return result;
        }

        // gen a n x n chessboard
        vector<int> t_row;
        vector<vector<int> > t_board;
        for (int i = 0; i < n; ++i) t_rows.push_back(0);
        for (int i = 0; i < n; ++i) t_board.push_back(t_row);
        
        for (int row = 0; row < n; ++row) {  // each row

            for (int q = 0; q < n; ++q) {
                
                if (t_board[row][q] == 0) {  // valid blank
                    
                }
            }
        }
        

    }
};
