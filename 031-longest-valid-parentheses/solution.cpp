/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Feb  4 15:36:18 2014
 * Modified at:   Tue Feb  4 18:08:36 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <stack>
#include <iostream>

using namespace std;

class Solution {

#ifdef STACK

    int getTheMax(stack<int>);

#endif  // STACK

public:
    int longestValidParentheses(string s) {
  
#ifdef STACK

        if(s.empty()) return 0;

        int max = 0;
        int i = 0;
        
        int top = s.size();  

        while(')' == s[i]) i++;

        // from i
        stack<int> lefts;

        for (int j = i; j < s.size(); ++j) {

            if('(' == s[j]) lefts.push(j);

            if(')' == s[j]) {
             
                if (lefts.empty() ) {
                    
                    int temp = longestValidParentheses(s.substr(j));                 
                    
                    max = (temp > max) ? temp : max;
                    top = j;
                    
                    break;

                } else {
                    lefts.pop();                    
                }
            }
        }

        if(lefts.empty()) {

            int temp = top - i;
            
            max = (temp > max) ? temp : max;

            return max;
            

        } else {
          
            if(lefts.size() == top - i) return max;

            while(!lefts.empty()) {
                
                int temp = top - lefts.top() - 1;
                // compare
                max = (temp > max) ? temp : max;

                top = lefts.top();
                lefts.pop();
            }

            int final = top - i;
            max = (final > max) ? final : max;

            return max;
            
        }       
      

#endif  // STACK

    }
};


int main() {

    Solution s;

    string str = "(())";
    // string str = "()";

    int result = s.longestValidParentheses(str);

    cout << result << endl;

    return 0;
}
