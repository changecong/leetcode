/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Mar 17 21:37:14 2014
 * Modified at:   Mon Mar 17 21:53:07 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        
#ifdef FOMULA

        // a look up table
        int *lookup;
        lookup = (int *) calloc(n + 1, sizeof(int));

        lookup[0] = 1;

        for (int i = 1; i <= n; ++i) {
            
            for (int j = 0; j < i; ++j) {
                
                lookup[i] += lookup[j] * lookup[i - 1 - j];
                // cout << "c" << i << " = " << "c" << j << "* c" << i - 1 -j << " = " << lookup[i] << endl;

            }
        }
        
        return lookup[n];

#endif  // FOMULA
    }
};

int main() {

    Solution s;

    int n = 3;

    int result = s.numTrees(n);

    cout << "The result is: " << result << endl;

    return 0;
}
