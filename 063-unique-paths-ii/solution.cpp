/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Feb 20 11:49:59 2014
 * Modified at:   Thu Feb 20 12:29:42 2014
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
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        
        int m = obstacleGrid.size();
        if (0 == m) return 0;
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 ) return 0; 

        if (m == 1 && n == 1) return 1;

        obstacleGrid[0][0] = 1;

        for(int i = 1; i < m; ++i) {
            if ( 1 == obstacleGrid[i][0] ) {  // obstacle
                obstacleGrid[i][0] = 0;
            } else {

                obstacleGrid[i][0] = (obstacleGrid[i - 1][0] == 0) ? 0 : 1;
            }
        }

        for(int i = 1; i < n; ++i) {
            if ( 1 == obstacleGrid[0][i] ) {  // obstacle
                obstacleGrid[0][i] = 0;
            } else {
                obstacleGrid[0][i] = (obstacleGrid[0][i - 1] == 0) ? 0 : 1;
            }
        }

        for(int i = 1; i < m; ++i) {

            for (int j = 1; j < n; ++j) {

                if (1 == obstacleGrid[i][j]) {  // obstacle
                    obstacleGrid[i][j] = 0;
                } else {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                }
            }
        }

        return obstacleGrid[m - 1][n - 1];
    }
};


int main() {

    Solution s;

    /*
     * 0, 0, 0
     * 0, 1, 0
     * 0, 0, 0
     */

    vector<vector<int > > obstacleGrid;
    int m = 3;
    int n = 3;
    vector<int> temp(n, 0);
    for (int i = 0; i < m; ++i) {
        obstacleGrid.push_back(temp);
    }
    
    obstacleGrid[1][1] = 1;

    int result = s.uniquePathsWithObstacles(obstacleGrid);

    cout << "The result is: " << result << endl;

    return 0;
}
