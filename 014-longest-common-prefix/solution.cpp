/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Jan 15 15:01:51 2014
 * Modified at:   Wed Jan 15 15:48:55 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {

#ifdef BRUTE_FORCE
private:

    void commonPrefix(string &cp, string str) {
        int i = 0;
        while ((i < cp.size() && i < str.size()) && (cp[i] == str[i])) i++;

        cp = cp.substr(0, i);
    }

#endif  // BRUTE_FORCE
    
public:
    string longestCommonPrefix(vector<string> &strs) {

#ifdef BRUTE_FORCE
        
        // if the vector is empty
        if (strs.empty()) return "";

        vector<string>::iterator it = strs.begin();
        string lcp = *it;
        it++;

        while (it != strs.end()) {
            commonPrefix(lcp, *it);
            if (0 == lcp.size()) break;
            it++;
        }

        return lcp;

#endif  // BRUTE_FORCE

#ifdef TRIE

        // No time enhancement

#endif  // TRIE
        
    }
};


int main() {

    Solution s;

    vector<string> strs;
//    strs.push_back("");
//    strs.push_back("bc2345");
//    strs.push_back("abc");

    string result = s.longestCommonPrefix(strs);

    cout << "The longest common prefix is : " << result << endl;

    return 0;
}
