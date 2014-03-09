/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar  9 00:15:17 2014
 * Modified at:   Sun Mar  9 00:57:01 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   this problem needs more explanations. X is 
 *                not the perfect square number, besides, we
 *                want to find the closest int which is smaller
 *                than or equals to exact sqrt(x).
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        
#ifdef BRUTE_FORCE  // too slow
        
        int result = 0;
        int n2 = 0;

        while (true) {

            n2 = n2 + 2 * result + 1;
            if (n2 > x) return result;
            result++;
        }

#endif  // BRUTE_FORCE

#ifdef NEWTON

        // Xn+1 = 1/2(Xn + S/xn)

        double rx = 3.0;  // square root of x
        double last = rx;
        double e = 1.0e-4;
        
        do {
            last = rx;
            rx = 0.5*(rx + x/rx);
        } while (abs(rx - last) > e);

        return (int)rx;        
        

#endif  // NEWTON
        

    }
};


int main() {

    Solution s;

    int x = 25;
    while (x >= 0) {

        int result = s.sqrt(x);
        cout << "sqrt(" << x << ") = " << result << endl;
        x--;
    }

    

    return 0;
}
