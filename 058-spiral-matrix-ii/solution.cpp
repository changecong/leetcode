/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Feb 14 00:42:44 2014
 * Modified at:   Fri Feb 14 10:42:29 2014
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
    vector<vector<int> > generateMatrix(int n) {

        vector<vector<int> > result;

        if (0 == n) return result;

        // initial
        vector<int> row(n, 0);
        for (int i = 0; i < n; ++i) {
            result.push_back(row);
        }
        
        int element = 1;

        int h_head = -1;
        int h_tail = n;
        int v_head = 0;
        int v_tail = n;
        
        int i = 0;
        int j = 0;
        
        while(true) {
        
            if ((i == v_head || i == v_tail) && (j == h_head || j == h_tail)) {
                break;
            } else if (i == v_head && j < h_tail) {  // up border
                result[i][j] = element++;
                if (++j >= h_tail) {  // touch to the right border
                    h_tail--;  // move the border left
                    j = h_tail;
                    i++;
                    continue;
                }               
            } else if (j == h_tail && i < v_tail) {  // right border
                result[i][j] = element++;
                if (++i >= v_tail) {  // touch the bottom border
                    v_tail--;  // move the bottom up
                    i = v_tail;
                    j--;
                    continue;
                }                
            } else if (i == v_tail && j > h_head) {  // bottom border
                result[i][j] = element++;
                if (--j <= h_head) {  // touch the left border
                    h_head++;
                    j = h_head;
                    i--;
                    continue;
                }
            } else if (j == h_head && i > v_head) {  // left border
                result[i][j] = element++;
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

    int n = 3;

    vector<vector<int> > result = s.generateMatrix(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
 
