/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Feb 18 23:13:38 2014
 * Modified at:   Thu Feb 20 10:53:35 2014
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

#ifdef COMBINE0  

    int combination(int b, int a) {

        if(a == 1) return b;
        if(b == a || a == 0) return 1;
        
        return combination(b - 1, a) + combination(b - 1, a - 1);
    }

#endif  // COMBINE0

#ifdef COMBINE1  

    int combination(int b, int a) {

        vector<double> C(a + 1, 0);

        C[0] = 1;
        int diff = b - a;

        for(int i = 1; i <= a; ++i) {
            C[i] = C[i - 1] * a / i + C[i - 1] * diff-- / i;
        }

        return (int) C[a];
    }

#endif  // COMBINE1

#ifdef COMBINE2  

    int combination(int b, int a) {

        vector<vector<int> > C(b + 1, vector<int> (a + 1, 0));

        C[0][0] = 1;

        for(int i = 1; i <= b; ++i) C[i][0] = 1;
        
        for(int i = 1; i <= b; ++i) {
            for (int j = 1; j <= a; ++j) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }

        return C[b][a];
    }

#endif  // COMBINE2

#ifdef RECURSIVE  // O(m*n) slow
    int possiblePathsNum(int m, int n,  // size of the board
                         int x, int y   // current coordinate
        ) {
        
        int possible_path = 0;

        // reach the finish block
        if (x + 1 >= m || y + 1 >= n) {  // right bottom or finish
            return 1;
        } else {
            return possiblePathsNum(m, n, x + 1, y) + 
                possiblePathsNum(m, n, x, y + 1);  // move right + move down
        }
    }
#endif  // RECURSIVE

public:
    int uniquePaths(int m, int n) {

#ifdef RECURSIVE       
        if (0 == m || 0 == n) return 0;

        return possiblePathsNum(m, n, 0, 0);
#endif  // RECURSIVE

#ifdef COMBINE0  // C(m + n - 2, m - 1) or C(m + n - 2, n - 1) 

        // A / A
        int a = (m > n) ? n - 1 : m - 1; 
        int b = m + n - 2;

        return combination(b, a);


#endif  // COMBINE0

#ifdef COMBINE1  // C(m + n - 2, m - 1) or C(m + n - 2, n - 1) 

        // A / A
        int a = (m > n) ? n - 1 : m - 1; 
        int b = m + n - 2;

        return combination(b, a);


#endif  // COMBINE1

#ifdef COMBINE2  // C(m + n - 2, m - 1) or C(m + n - 2, n - 1) 

        // A / A
        int a = (m > n) ? n - 1 : m - 1; 
        int b = m + n - 2;

        return combination(b, a);


#endif  // COMBINE2

#ifdef DP0

        if (0 == m || 0 == n) return 0;

        vector<vector<int> > map(m, vector<int>(n, 1));

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
        
        return map[m - 1][n - 1];

#endif  // DP0

    }
};


int main() {

    Solution s;

    int m = 23;
    int n = 12;

    int result = s.uniquePaths(m, n);

    cout << "There is(are) " << result << " unique path(s)" << endl;

    return 0;
}
