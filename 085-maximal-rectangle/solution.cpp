/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sat Mar 15 00:10:22 2014
 * Modified at:   Sun Mar 16 01:52:28 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
private:

    int maxArea(vector<int> &bars) {

        int result = 0;

        if (bars.empty()) return result;
        if (bars.size() == 1) return bars[0];

        stack<int> indics;
        
        int i = 0;
        int len = bars.size();

        while (i < len) {

            if (indics.empty() || bars[i] >= bars[indics.top()]) {  // push
                
                indics.push(i++);

            }

            if (bars[i] < bars[indics.top()]) {  // pop

                int height = bars[indics.top()];
                indics.pop();
                
                int max = height * (indics.empty() ? i : i - indics.top() - 1);
                
                result = (result < max) ? max : result;

            }
        }

        while (!indics.empty()) {

            int height = bars[indics.top()];
            indics.pop();
                
            int max = height * (indics.empty() ? i : i - indics.top() - 1);
                
            result = (result < max) ? max : result;

        }

        return result;

        
    }



public:
    int maximalRectangle(vector<vector<char> > &matrix) {

        int result = 0;

        if (matrix.empty()) return result;
   
        int rows = matrix.size();
        int cols = matrix[0].size();

        // create a new matrix
        vector<int> temp(cols);
        vector<vector<int> > matrix01(rows, temp);

        /*

          0 0 0 0 0
          0 1 0 0 0
          0 1 1 0 0
          0 0 1 1 1
          0 0 1 1 1
          0 0 0 1 1

         */

        for (int i = rows - 2; i >= 0; --i) {  // each row
            
            for (int j = 0; j < rows; ++j) {
                
                matrix01[i][j] = matrix[i][j] - '0' + matrix[i + 1][j] - '0';
                
            }

        }

        /*
          0 0 0 0 0
          0 2 0 0 0
          0 1 3 0 0
          0 0 1 3 3
          0 0 1 2 2
          0 0 0 1 1

         */

        for (int i = 0; i < rows; ++i) {
            
            int max = maxArea(matrix01[i]);

            result = (result < max) ? max : result;
        }


        return result;

    }
};


int main() {

    Solution s;

    int A[6][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1}
    };

    vector<char> temp(3, '0');
    vector<vector<char> > matrix(4, temp);
    
    // for (int i = 0; i < 6; i++) {

    //     for (int j = 0; j < 5; j++) {
    //         cout << A[i][j] << " ";
    //         matrix[i][j] = A[i][j] + '0';
    //     }

    //     cout << endl;
    // }
    
    int result = s.maximalRectangle(matrix);


    cout << "The maximal rechangle area is: " << result << endl;

    return 0;
}
