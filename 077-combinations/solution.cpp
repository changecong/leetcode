/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Mar 10 23:48:13 2014
 * Modified at:   Tue Mar 11 11:01:03 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {

private:

/*
    // resturn all permutations of the set
    // remove is the position that need to be removed
    vector<vector<int> > permutations(vector<int> set, int remove) {
        
        vector<vector<int> > result;

        if (remove < set.size()) {  // valid remove position
            // remove
            set.erase(set.begin() + remove);
        }

        if (set.size() == 0) return result;
        if (set.size() == 1) {
            result.push_back(set);
            return result;
        }

        for (int i = 0; i < set.size(); ++i) {

            vector<vector<int> > temp = permutations(set, i);
            
            for (int j = 0; j < temp.size(); ++j) {
                temp[j].push_back(set[i]);
                result.push_back(temp[j]);
            }
        }
        
        return result;

    }
*/
    // n is number of candidant
    vector<vector<int> > combines(vector<int> num, int n) {

        vector<vector<int> > result;

        if (n <= 1) {
            
            for (int i = 0; i < num.size(); ++i) {
                
                vector<int> temp(1, num[i]);
                result.push_back(temp);
            }

            return result;            
        }

        while (num.size() >= n) {
            
            int first = num[0];

            // remove the first
            num.erase(num.begin());

            // the rest
            vector<vector<int> > temp = combines(num, n - 1);

            for (int i = 0; i < temp.size(); ++i) {
                temp[i].push_back(first);
                
                // all permutations
                // vector<vector<int> > temp_result = permutations(temp[i], temp[i].size());
                
                // for (int i = 0; i < temp_result.size(); ++i) {
                //    result.push_back(temp_result[i]);
                // }

                result.push_back(temp[i]);
            }

        }

        return result;

    }

public:
    vector<vector<int> > combine(int n, int k) {

        vector<int> num;
        vector<vector<int> > result;

        if (n < k) return result;

        // gen a vector from 1 ~ n
        for (int i = n; i > 0; --i) {
            num.push_back(i);
        }

        return combines(num, k);
        
    }
};


int main() {

    Solution s;
    
    int n = 4;
    int k = 2;

    vector<vector<int> > result = s.combine(n, k);

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
