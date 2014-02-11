/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Feb 11 10:00:20 2014
 * Modified at:   Tue Feb 11 13:06:27 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
  
#ifdef HASH_INDEX
        // extra space temp : contains sorted strings
        // extra space t_str : hash table that represents if the string has been checked.

        // sort
        vector<string> temp = strs;

        vector<string>::iterator s_it = temp.begin();
        while (s_it != temp.end()) {
            sort(s_it->begin(), s_it->end());
            s_it++;
        }

        vector<string> result;
        
        int n = strs.size();

        // gen a hashtable
        int *t_str;
        t_str = (int *)calloc(n, sizeof(t_str));
        memset(t_str, 0x0, sizeof(t_str)*n);

        for (int i = 0; i < n; ++i) {
            // if checked
            if (t_str[i] != 0) continue;

            // push
            result.push_back(strs[i]);
            int size = result.size();
            

            for (int j = i + 1; j < n; ++j) {
                
                if (t_str[j] != 0) continue;
                
                if (temp[j] == temp[i]) {
                    result.push_back(strs[j]);
                    // set read
                    t_str[j] = 1;
                }

            }

            if (size == result.size()) { // no new found
                result.pop_back();
            }
            
            t_str[i] = 1;
        }
        
        return result;

#endif  // HASH_INDEX

#ifdef HASH_STRING

        // sort
        vector<string> temp = strs;

        vector<string>::iterator s_it = temp.begin();

        map<string, vector<int> > m_str;

        int idx = 0;

        while (s_it != temp.end()) {

            sort(s_it->begin(), s_it->end());

            if (m_str.find(*s_it) != m_str.end()) {  // already exist

                m_str[*s_it].push_back(idx);  // store the index

            } else {  // not exist

                vector<int> temp_idx;
                temp_idx.push_back(idx);
                m_str.insert(make_pair(*s_it, temp_idx));

            }

            s_it++;
            idx++;
        }

        vector<string> result;
        
        map<string, vector<int> >::iterator m_it = m_str.begin();

        while(m_it != m_str.end()) {

            int size = m_it->second.size(); 

            if( size > 1 ) {
                for (int i = 0; i < size; ++i) {
                    result.push_back(strs[m_it->second[i]]);
                }
            }
            
            m_it++;
        }

        return result;

#endif  // HASH_STRING
    }
};


int main() {

    Solution s;

    vector<string> strs;

    strs.push_back("dog");
    strs.push_back("cat");
    strs.push_back("god");
    strs.push_back("tac");
    strs.push_back("foo");
    strs.push_back("bar");

    vector<string> result = s.anagrams(strs);

    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    cout << "]" << endl;

    return 0;
}
