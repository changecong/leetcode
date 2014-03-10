/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Mar 10 12:34:49 2014
 * Modified at:   Mon Mar 10 12:50:52 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        
        bool result = false;

        if (matrix.empty()) return result;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // search with the range

        for (int i = 0; i < rows; i++) {

            if(matrix[i][0] <= target && matrix[i][cols-1] >= target) {
             
                // search in this section
                for (int j = 0; j < cols; ++j) {
                    if (matrix[i][j] == target) {
                        return true;
                    }
                }
   
            }
            
        }

        return result;
      
    }
};


int main() {

    Solution s;

    vector<vector<int> > matrix;
/*
  [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
  ]
*/
    
    cout << "Sorry, I am too lazy to write a test case..." << endl;
    return 0;
}
