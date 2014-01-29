/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Jan 28 16:04:23 2014
 * Modified at:   Wed Jan 29 11:30:32 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {

private:

    map<char, string > genLetterNumberMap() {
        
        map<char, string > result;
       
        result.insert( pair<char, string>('0', " ") );
        result.insert( pair<char, string>('1', "") );
        result.insert( pair<char, string>('2', "abc") );
        result.insert( pair<char, string>('3', "def") );
        result.insert( pair<char, string>('4', "ghi") );
        result.insert( pair<char, string>('5', "jkl") );
        result.insert( pair<char, string>('6', "mno") );
        result.insert( pair<char, string>('7', "pqrs") );
        result.insert( pair<char, string>('8', "tuv") );
        result.insert( pair<char, string>('9', "wxyz") );
       
        return result;        
    }


public:
    vector<string> letterCombinations(string digits) {
   
#ifdef BRUTE_FORCE
        
        vector<string> results;

        // empty string
        if (0 == digits.size()) {
            return vector<string>(1, "");
        }
        
        // gen a map of chars
        map<char, string> charMap = genLetterNumberMap();
        
        // get mapping
        string mapping = charMap.find(digits[0])->second;
        
        for(int i = 0; i < mapping.size(); ++i) {
            vector<string> previous = letterCombinations(digits.substr(1));

            if (0 == previous.size()) {
                
                string result = "";
                result += mapping[i];                
                results.push_back(result);

            } else {

                for(int j = 0; j < previous.size(); ++j) {
                    string result = mapping[i] + previous[j];

                
                    results.push_back(result);
                }
            }
        }

        return results;       

#endif  // BRUTE_FORCE

     
    }
};

int main() {

    Solution s;

    string digits = "23";

    vector<string> result = s.letterCombinations(digits);

    vector<string>::iterator it = result.begin();

    while(it != result.end()) {
        cout << "\" " << *it << " \"" << endl;
        it++;
    }

    return 0;
}
