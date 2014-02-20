/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Feb 20 11:13:27 2014
 * Modified at:   Thu Feb 20 11:46:36 2014
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
    int minPathSum(vector<vector<int> > &grid) {
        
        int m = grid.size();  // row #
        if(m == 0) return 0;
        int n = grid[0].size();  // col #

        for(int i = 1; i < m; ++i) grid[i][0] += grid[i - 1][0];
        for(int i = 1; i < n; ++i) grid[0][i] += grid[0][i - 1];

        for(int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {

                int min = (grid[i - 1][j] > grid[i][j - 1]) ? grid[i][j - 1] : grid[i - 1][j];

                grid[i][j] += min;
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main() {

    Solution s;

    vector<vector<int> > grid;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    grid.push_back(temp);

    temp.clear();
    temp.push_back(1);
    temp.push_back(1);
    grid.push_back(temp);

    int result = s.minPathSum(grid);

    cout << "The result is: " << result << endl;
    

    return 0;
}
