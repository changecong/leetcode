/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Feb  3 20:44:26 2014
 * Modified at:   Tue Feb  4 13:08:26 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

using namespace std;

class Solution {

private:

    void findAllIndices(string S, string str, vector<int> &indices) {

        // Non-kmp
        int offset = 0;
        while(true) {

            int pos = S.find(str, offset);

            if (pos != -1) {  // get
                indices.push_back(pos);
            } else {
                break;
            }

            // update offset
            offset = pos + 1;
            
        }
    }

public:
    vector<int> findSubstring(string S, vector<string> &L) {

        vector<int> results;
        if (S.empty() || L.empty()) return results;
        
        // initialize two hash tables
        map<int, string> indices;
        map<string, int> exist;

        int len = L.size();

        for (int i = 0; i < len; ++i) {
            
            if(exist.find(L[i]) != exist.end()) {
                // exist
                exist[L[i]]++;
                continue;
            }
            exist.insert(pair<string, int>(L[i], 1));
        
            // find all indices for each words
            vector<int> word_indices;
            findAllIndices(S, L[i], word_indices);

            if (1 == len) return word_indices;

            // fill up the map
            for (int j = 0; j < word_indices.size(); ++j) {
                indices.insert(pair<int, string>(word_indices[j], L[i]));
            }
        }


        // find all comcatenations
        int step = L[0].size();
        
        map<int, string>::iterator it = indices.begin();
        
        map<string, int> temp = exist;

        while(it != indices.end()) {

            // clear
            exist = temp;

            int first = it->first;
            if ((first + len*step) > S.size()) break;
            
            // set exist
            exist[it->second] -= 1;
            int i = 1;
     
            map<int, string>::iterator temp_it = indices.find(first);
     
            for (; i < len; ++i) {

                temp_it++;

                int next = first + step * i;

                while( (temp_it->first < next) && (temp_it != indices.end())) {
                    temp_it++;
                }

                if (temp_it->first == next) {
                    // get
                    if (exist[temp_it->second] == 0) {
                        
                        break;
                        
                    } else {
                        exist[temp_it->second] -= 1;
                    }
                } else {
                    // doesn't find
                    break;
                }               
                
            }

            if (len == i) {
                results.push_back(first);
            }

            it++;
        }

        return results;
        
    }
};

string getFromText(vector<string>& L) {

    ifstream ifs ("input.txt", std::ifstream::in);
    
    string result;

    ifs >> result;

    // cout << result << endl;

    string pattens;
    ifs >> pattens;

    int offset = 3;

    // get the length
    int pos0 = pattens.find("\",\"", 0);
    int pos1 = pattens.find("\",\"", 3);
    int len = pos1 - pos0 - 3;
    
    while(offset + len < pattens.size()) {
        
        string temp = pattens.substr(offset, len);

        L.push_back(temp);
        
        offset = offset + len + 3;

        // cout << temp << endl;

    }

    return result;

}

int main() {

    Solution s;

    // string S = "barfoothefoobarman";
    // string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    // string S = "cccbcacaa";

    // string S(5000, 'a');

    vector<string> L;
    string S = getFromText(L);
    // L.push_back("fooo");
    // L.push_back("barr");
    // L.push_back("wing");
    // L.push_back("ding");
    // L.push_back("wing");
    // L.push_back("ab");
    // L.push_back("ba");
    // L.push_back("cc");
    // L.push_back("bc");
    // L.push_back("foo");
    // L.push_back("bar");



    // for (int i = 0; i < S.size(); ++i) {
    //     string temp = string(1, S[i]);
    //     L.push_back(temp);
    // }

    


    vector<int> results = s.findSubstring(S, L);
    
    if (!results.empty()) {
        cout << "[";
        for (int i = 0; i < results.size() - 1; ++i) {
            cout << results[i] << ", ";
        }
        cout << results[results.size() - 1] << "]" << endl;
    } else {
        cout << "null" << endl;
    }
    return 0;
}
