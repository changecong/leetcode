/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Feb  4 13:30:55 2014
 * Modified at:   Tue Feb  4 15:31:11 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {

        if(!num.empty() && 1 != num.size()) {
        
            int i = num.size() - 1;
            
            for (; i > 0; --i) {
                
                if (num[i] > num[i-1]) break; 
            }
            
            if (0 == i) {  // greatest
                
                sort(num.begin(), num.end());
            } else {
                int j = i;
                for (; j < num.size(); ++j) {
                    if (num[j] <= num[i-1]) break;
                }

                // if(j == num.size()) j--;

                swap(num[i-1], num[j-1]);

                sort(num.begin()+i, num.end());
            } 
            
        }
        
    }
};


int main() {

    Solution s;

    vector<int> num;
    
    num.push_back(1);
    num.push_back(5);
    num.push_back(1);
    // num.push_back(6);
    // num.push_back(5);
    // num.push_back(4);
    // num.push_back(3);

    cout << "[";
    for (int i = 0; i < num.size(); ++i) {
        cout << num[i] << " ";
    }
    cout << "]" << endl;

    s.nextPermutation(num);

    cout << "[";
    for (int i = 0; i < num.size(); ++i) {
        cout << num[i] << " ";
    }
    cout << "]" << endl;
    

    return 0;
}
