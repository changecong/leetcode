/*
 * Filename:      util.hpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Jan  6 13:10:40 2014
 * Modified at:   Fri Jan 31 11:38:08 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#ifndef UTIL_HPP
#define UTIL_HPP

#include <vector>
#include <stdlib.h> 
#include <time.h>  
#include <iostream>

namespace util {

    void random_int_vector(std::vector<int>& numbers,
                           int& target,
                           int min = 0,
                           int max = 10000,
                           int len = 10000000) {
        
        srand((unsigned)time(NULL));
        int i = 0;
        while (i++ < len) {
            numbers.push_back((rand() % (max - min + 1)) + min);
            target += numbers[i-1];
        }

        target = (int)(target*2/len);
        // std::cout << "target: " << target << std::endl;
    }

}

#endif  // UTIL_HPP 
