/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar  9 00:59:47 2014
 * Modified at:   Sun Mar  9 12:23:52 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

#ifdef RECURSIVE
        switch(n) {
        case 0:
            return 0;
            break;
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        default:
            return climbStairs(n-1) + climbStairs(n-2);
            break;            
        }       

#endif  // RECURSIVE

#ifdef DP

        int *map;
        map = (int*)calloc(n+1, sizeof(int));
        // map = (int*)malloc((n+1)*sizeof(int));
        // memset(map, 0x0, n+1);
        map[0] = 0;
        map[1] = 1;
        map[2] = 2;

        for (int i = 3; i <= n; i++) {
           
            map[i] = map[i-1] + map[i-2];
        }

        return map[n];
        
#endif  // DP 
    }
};


int main() {

    Solution s;

    int n = 4;

    int result = s.climbStairs(n);

    cout << "The result is: " << result << endl;

    return 0;
}
