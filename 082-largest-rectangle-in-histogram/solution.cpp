/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Mar 13 22:07:53 2014
 * Modified at:   Fri Mar 14 22:10:08 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
  
        int result = 0;
        
        if (height.empty()) return result;

        if (1 == height.size()) return height[0];

        stack<int> bars;  // index
        int len = height.size();
        int i = 0;

        while (i < len){
            
            if (bars.empty() || height[i] >= height[bars.top()]) {  //
                
                // in stack
                bars.push(i++);

            } else {  // 
                // calculate the max area
                int top = bars.top();
                bars.pop();

                int temp = height[top] * (bars.empty() ? i : i - bars.top() - 1);
                
                result = (temp > result) ? temp : result;  
            }
                
        }

        // pop the remained bars
        while (!bars.empty()) {

            // calculate the max area
            int top = bars.top();
            bars.pop();
            
            int temp = height[top] * (bars.empty() ? i : i - bars.top() - 1);
            
            result = (temp > result) ? temp : result;
            
        }

        return result;
      
    }
};


int main() {

    Solution s;

    int A[6] = {2,1,5,6,2,3};
    int n = 6;
    vector<int> height;
    for (int i = 0; i < n; ++i) height.push_back(A[i]);

    int result = s.largestRectangleArea(height);

    cout << "The largest rectangle area is: " << result << endl;

    return 0;
}
