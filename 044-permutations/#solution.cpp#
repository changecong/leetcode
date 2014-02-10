/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Feb 10 12:34:02 2014
 * Modified at:   Mon Feb 10 14:08:59 2014
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

    vector<vector<int> > permuteRecursive(vector<int> num, int remove) {
        
        vector<vector<int> > result;

        if (remove < num.size()) {
            num.erase(num.begin() + remove);
        }

        if (num.size() == 0) return result;
        if (num.size() == 1) {
            result.push_back(num);
        }

        for (int i = 0; i < num.size(); ++i) {
            vector<vector<int> > temp = permuteRecursive(num, i);
            for (int j = 0; j < temp.size(); ++j ) {
                temp[j].push_back(num[i]);
                result.push_back( temp[j] );
            }
        }

        return result;
    }
public:
    vector<vector<int> > permute(vector<int> &num) {

        return permuteRecursive(num, num.size());
   
    }
};


int main() {

    Solution s;

    vector<int> num;
    // num.push_back(1);
    // num.push_back(2);
    // num.push_back(3);

    vector<vector<int> > result = s.permute(num);

    for (int i = 0; i < result.size(); ++i) {
        cout << "[" ;
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ", ";
        }

        cout << "], ";
    }

    cout << endl;

    return 0;
}
