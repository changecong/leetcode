/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Feb 10 23:27:04 2014
 * Modified at:   Tue Feb 11 09:51:36 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
  
#ifdef NTIMES
        
        if (n > 0) {

            double temp_x = x;
            while(n > 1) {
                x *= temp_x;
                n--;
            }

            return x;
        } 
        
        if (n == 0) {
            return 1;
        } 
        
        if (n < 0) {

            x = 1/x;
            double temp_x = x;

            while (n < -1) {
                x *= temp_x;
                n++;
            }

            return x;
        }

#endif  // NTIMES
      
#ifdef BIN

        int n0 = n / 2;
        int n1 = n % 2;

        if (n < 0) {
            x = 1/x;
            n0 = -n0;
            n1 = -n1;
        }
        
        if (n == 1) {
            return x;
        }

        if (n == 0) {
            return 1;
        } 
        
        double temp = pow(x, n0);
        
        return temp * temp * pow(x, n1);

       
#endif  // BIN

    }
};


int main() {

    Solution s;

    double x = 0.00001;
    int n = -2147483647;
    
    double result = s.pow(x, n);

    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
