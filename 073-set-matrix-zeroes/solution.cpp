/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar  9 22:58:34 2014
 * Modified at:   Mon Mar 10 12:31:24 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {

        // check validity
        if (!matrix.empty()) {

            bool first_row_has_zero = false;
            bool first_col_has_zero = false;

            int rows = matrix.size();
            int cols = matrix[0].size();

            // scan the first row
            for (int i = 0; i < cols; ++i) {
                if(0 == matrix[0][i]) {
                    first_row_has_zero = true;
                    break;
                }
            }

            // scan the first column
            for (int i = 0; i < rows; ++i) {
                if(0 == matrix[i][0]) {
                    first_col_has_zero = true;
                    break;
                }
            }

            // two pass
            // scan the matrix without the 1st row and column
            for (int i = 1; i < rows; ++i) {
                for (int j = 1; j < cols; ++j) {
                    if (0 == matrix[i][j]) {
                        // set corresponding row and col
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }

            // scan the matrix again
            for (int i = 1; i < cols; ++i) {
                
                if (0 == matrix[0][i]) {
                    for (int j = 1; j < rows; ++j) {
                        matrix[j][i] = 0;
                    }
                }
            }

            for (int i = 1; i < rows; ++i) {
                if (0 == matrix[i][0]) {

                    for (int j = 1; j < cols; ++j) {
                        matrix[i][j] = 0;
                    }
                }
            }

            if (first_row_has_zero) {
                for (int i = 0; i < cols; ++i) {
                    matrix[0][i] = 0;
                }
            }

            if (first_col_has_zero) {
                for (int i = 0; i < rows; ++i) {
                    matrix[i][0] = 0;
                }
            } 
            
        }
    }
};


int main() {

    Solution s;

    vector<vector<int> > matrix;

    // too lazy to add a test case

    return 0;

}
