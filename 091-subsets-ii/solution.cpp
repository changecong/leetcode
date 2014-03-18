/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Mar 17 11:44:56 2014
 * Modified at:   Mon Mar 17 20:24:47 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
private:

public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {

        // sorting
        sort(S.begin(), S.end());
        
        // create a vector, and push [] in
        vector<vector<int> > result(1);
        int current = S[0];
        int last_j = 0;
        for (int i = 0; i < S.size(); ++i) {
            
            int end = 0;

            int j = result.size();

            if (current == S[i]) {  // if equal, only extend items with S[i]'s predecessor
                end = last_j;
            } else {
                current = S[i];  // not equal, store the new item
            }            
            
            last_j = j;  // store the most recent j

            while(j-- > end) {
                result.push_back(result[j]);
                result.back().push_back(S[i]);
            }
        }

        return result;
    }
};


int main() {

    Solution s;

    int A[5] = {1, 2, 2, 2, 3};
    vector<int> S;

    for (int i = 0; i < 5; ++i) {
        S.push_back(A[i]);
    }

    vector<vector<int> > result = s.subsetsWithDup(S);

    cout << "[" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "\t[ ";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    

    return 0;
}
