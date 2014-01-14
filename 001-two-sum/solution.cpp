/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Jan  6 14:30:58 2014
 * Modified at:   Mon Jan  6 15:35:18 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#ifdef HASH
#include <map>
#endif   // HASH
#ifdef SORTING
#include <utility>      // std::pair
#include <algorithm>      // std::sort
#endif  //SORTING
#include <iostream>  // std::cout, std::endl
#include <util.hpp>  // util::random_int_vector()

using namespace std;
#ifdef SORTING
        // 1. generate a vector contains indices
typedef vector< pair<int, int> > vector_pair;    
#endif  // SORTING

class Solution {


#ifdef SORTING
private:
    static bool compare(const pair<int, int>& left,
                 const pair<int, int>& right) {
        return left.first < right.first;
    }
#endif  // SORTING

public:
    vector<int> twoSum(vector<int> &numbers, int target) {

        vector<int> result;

#ifdef BRUTE_FORCE
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = 0; j < numbers.size(); j++) {

                if (i == j) continue;

                if ((numbers[i] + numbers[j]) == target) {
                    // push
                    // indices are not zero-based
                    if (i > j) {
                        result.push_back(j+1);
                        result.push_back(i+1);
                    } else {
                        result.push_back(i+1);
                        result.push_back(j+1);
                    }   

                    break;
                } 
            }
        }
#endif  // BRUTE_FORCE

#ifdef HASH
        // 1. store the vector to a map
        map<int, vector<int> > num_map;
        int i = 0;
        int diff = 0;
        while (i < numbers.size()) {
            num_map[numbers[i]].push_back(i);
            i++;
        }

        // 2. find if the difference is exist
        for (i = 0; i < numbers.size(); i++) {
            diff = target - numbers[i];
            if (num_map.find(diff) != num_map.end()) {
                vector<int> temp = num_map.find(diff)->second;
                int j = temp[0];
                
                if (i == j) {
                    if (temp.size() > 1) {
                        j = temp[1];
                    } else {
                        continue;
                    }
                } 
                
                if (i > j) {
                    result.push_back(j+1);
                    result.push_back(i+1);
                } else if (i < j) {
                    result.push_back(i+1);
                    result.push_back(j+1);
                }   

                break;
            }
        }

#endif // HASH

#ifdef SORTING
        // 1. generate a vector contains indices
        vector_pair num_pair;    
        
        int i = 0;

        while(i < numbers.size()) {
      
            num_pair.push_back(make_pair(numbers[i], i));
            i++;
        }
            
        // 2. sorting
        sort(num_pair.begin(), num_pair.end(), compare);

        // 3. find the target
        int head = 0;
        int tail = numbers.size() - 1;
        int sum = 0;
        
        while(head < tail) {
            sum = num_pair[head].first + num_pair[tail].first;
            
            if (sum == target) {
                int i = num_pair[head].second;
                int j = num_pair[tail].second;
                // indices are not zero-based
                if (i > j) {
                    result.push_back(j+1);
                    result.push_back(i+1);
                } else {
                    result.push_back(i+1);
                    result.push_back(j+1);
                }

                break;

            } else if (sum > target) {
                tail--;
            } else {
                head++;
            }
        }
            

#endif  // SORTING

        
        return result;
    }

};


int main() {

    Solution s;
    vector<int> numbers;
    vector<int> result;
    int target = 6;

    // generate a target number and a vector.
    // util::random_int_vector(numbers, target);
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(4);
    numbers.push_back(5);

    result = s.twoSum(numbers, target);
    
    if (0 == result.size()) {
        cout << "No result found" << endl;
    } else {
        cout << "index1=" << result[0] << ", index2=" << result[1] << endl; 
        cout << numbers[result[0]-1] << ", " << numbers[result[1]-1] << endl; 
    }
    return 0;
}
