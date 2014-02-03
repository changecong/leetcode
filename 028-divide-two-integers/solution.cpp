/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Feb  3 12:02:32 2014
 * Modified at:   Mon Feb  3 16:37:48 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

// +----------+-------------+
// |operater  |functionality|
// +----------+-------------+
// |~         |not          |
// +----------+-------------+
// |<<        |shift left   |
// +----------+-------------+
// |>>        |shift right  |
// +----------+-------------+
// |&         |and          |
// +----------+-------------+
// |^         |xor          |
// +----------+-------------+
// ||         |or           |
// +----------+-------------+

#include <iostream>

using namespace std;

class Solution {
public:
    int add(int first, int second) {
        
        // TODO
        // consider about the overflow
        return (0 == second) ? first : add((first^second), (first&second)<<1);

    }

    int minus(int minuend, int subtracted) {
        
        // minuend + COMPLEMENT(subtracted)
        // COMPLEMENT(subtracted) = ~subtracted + 1
        return add(minuend, add(~subtracted, 1) );
        

    }
    
    int multiply(int first, int second) {

#ifdef ADDS        
        // add 'second' times
        if (second < 0) {
            second = add(~second, 1);
            first = add(~first, 1);
        }
        int result = 0;
        while(0 != second) {
            result = add(result, first);
            second = add(second, -1);
        }

        return result;
#endif  // ADDS

#ifdef ABS

        // get abs
        int multiplier = (first < 0) ? add(~first, 1) : first;
        int multiplicend = (second < 0) ? add(~second, 1) : second;

        // get the product
        int product = 0;
        while(multiplicend) {
            

            if (multiplicend & 0x1) {  // last digist is 1
                product = add(product, multiplier);
            }

            // shift
            multiplicend = multiplicend >> 1;
            multiplier = multiplier << 1;
        }

        // symbol
        if ((first^second) < 0) {  // different
            product = add(~product, 1);
        }

        return product;

#endif  // ABS
    }

    int divide(int dividend, int divisor) {
        
#ifdef MINUS

        // abs
        int reminder = (dividend < 0) ? add(~dividend, 1) : dividend;
        int absDivisor = (divisor < 0) ? add(~divisor, 1) : divisor;

        //
        int quotient = 0;
        while (reminder >= absDivisor) {
            reminder = minus(reminder, absDivisor);
            quotient = add(quotient, 1);
        }

        // symbol
        if ((dividend^divisor) < 0) {  // different
            quotient = add(~quotient, 1);
        }

        return quotient;

#endif  // MINUS

#ifdef MULT
        
        // inorder to pass the OJ all int convert to long

        // avoid overflow
        long long reminder = (dividend < 0) ? -(long long)(dividend) : (long long)dividend;
        long long absDivisor = (divisor < 0) ? -(long long)(divisor) : (long long)divisor;

        int quotient = 0;
        while (reminder >= absDivisor) {
            
            int shift = 0;
            while(reminder > (absDivisor<<shift)) {
                shift++;
                cout << shift << endl;
            }
            

            if(shift > 0) shift--;
            
            reminder -= absDivisor<<shift;
            quotient += 1<<shift;
            
            

        }

                // symbol
        if ((dividend^divisor) < 0) {  // different
            quotient = -quotient;
        }

        return quotient;

#endif  // MULT

    }
    
};


int main() {

    Solution s;
    static int max = 0x7fffffff;
    static int min = 0x80000000;

    int a = -1010369383;  // max;
    int b = min;  // min;

    cout << "Input are [" << a << "] and [" << b << "]" << endl;

    // add
    // int addResult = s.add(a, b);
    // cout << a << " + " << b << " = " << addResult << endl;
    
    // minus
    // int minusResult = s.minus(a, b);
    // cout << a << " - " << b << " = " << minusResult << endl;

    // multiplication
    // int multResult = s.multiply(a, b);
    // cout << a << " x " << b << " = " << multResult << endl;

    // division
    int divResult = s.divide(a, b);
    cout << a << " / " << b << " = " << divResult << endl;

    return 0;
}
