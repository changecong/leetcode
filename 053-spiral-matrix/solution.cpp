/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Feb 13 11:35:55 2014
 * Modified at:   Thu Feb 13 12:53:34 2014
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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        
        vector<int> result;
        if (matrix.empty()) return result;

        int h_head = -1;
        int h_tail = matrix[0].size();
        int v_head = 0;
        int v_tail = matrix.size();

        int i = 0;
        int j = 0;
        while(1) {
            
            if ((i == v_head || i == v_tail) && (j == h_head || j == h_tail)) {  // complete
                break;
            } else if (j < h_tail && i == v_head) {  // up border
                result.push_back(matrix[i][j]);
                // move to the right
                if (++j >= h_tail) {  // touch the right border
                    h_tail--;
                    j = h_tail;
                    i++;  // move down, now i > v_head
                    continue;
                }
            } else if (i < v_tail && j == h_tail) {  // right border 
                result.push_back(matrix[i][j]);
                // move down
                if (++i >= v_tail) {  // touch the bottom border
                    v_tail--;
                    i = v_tail;
                    j--;  // move left, now j < h_tail
                    continue;
                }
            } else if (j > h_head && i == v_tail ) {  // bottom border
                result.push_back(matrix[i][j]);
                // move left
                if (--j <= h_head) {  // touch the left border
                    h_head++;
                    j = h_head;
                    i--;  // move up
                    continue;
                }
            } else if (i > v_head && j == h_head) {  // left border
                result.push_back(matrix[i][j]);
                if (--i <= v_head) {  // touch the up border
                    v_head++;
                    i = v_head;
                    j++;
                    continue;
                }
            } else {
                break;
            }
            
        }


        return result;
    }
};


int main() {

    Solution s;

    vector<vector<int> > matrix;
    vector<int> temp0(4, 0);
    matrix.push_back(temp0);
    vector<int> temp1(4, 1);
    matrix.push_back(temp1);
    vector<int> temp2(4, 2);
    matrix.push_back(temp2);
    // vector<int> temp3(4, 3);
    // matrix.push_back(temp3);

    vector<int> result = s.spiralOrder(matrix);

    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    cout << "]" << endl;

    return 0;
}
