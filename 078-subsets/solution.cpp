/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Mar 11 11:06:38 2014
 * Modified at:   Tue Mar 11 14:11:43 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(int a, int b) {
    return a > b;
}


class Solution {
private:
    vector<vector<int> > combine(vector<int> S, int k) {

        vector<vector<int> > result;

        if (k <= 1) {
            
            for (int i = 0; i < S.size(); ++i) {
                vector<int> temp(1, S[i]);
                result.push_back(temp);
            }

            return result;

        }

        // > 1
        while(S.size() >= k) {

            int first = S[0];
            
            // remove the first one
            S.erase(S.begin());
            
            vector<vector<int> > temp = combine(S, k - 1);

            for (int i = 0; i < temp.size(); ++i) {
                
                temp[i].push_back(first);
                result.push_back(temp[i]);
            }
        

        }

        return result;
    }

public:

    vector<vector<int> > subsets(vector<int> &S) {
  
        // sort
        sort(S.begin(), S.end(), compare);

        vector<vector<int> > result;
        
        // return each combine with order
        int size = S.size();
      
        for (int i = 0; i <= size; ++i) {

            if (i == 0) {
                // insert an empty one

                vector<int> temp;
                result.push_back(temp);
                continue;
            }

            // others return combinations
            vector<vector<int> > temp = combine(S, i);

            for (int j = 0; j < temp.size(); ++j) {
                result.push_back(temp[j]);
            }
            
        }

        return result;

    }
};


int main() {

    Solution s;

    int A[3] = {1, 2, 3};

    vector<int> S;
    for (int i = 0; i < 3; ++i) {

        S.push_back(A[i]);
    }

    vector<vector<int> > result = s.subsets(S);

    cout << "[" << endl;

    for (int i = 0; i < result.size(); ++i) {
        cout << "\t[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }

    cout << "]" << endl;

    return 0;
}
