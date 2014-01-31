/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Jan 31 11:07:48 2014
 * Modified at:   Fri Jan 31 13:33:36 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include "util.hpp"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {

#ifdef MERGE

private:
    ListNode* merge2Lists(ListNode* list2, ListNode* list1) {
        
        if (NULL == list2) return list1;

        ListNode* result = new ListNode(0);
        ListNode* node = result;

        while (NULL != list1 || NULL != list2) {

            if (NULL == list1) {
                node->next = list2;
                return result->next;
            }
            if (NULL == list2) {
                node->next = list1;
                return result->next;
            }

            int a = list1->val;
            int b = list2->val;

            if (a < b) {  // a in
                
                node->next = new ListNode(a);
                node = node->next;
                
                list1 = list1->next;
            } else if (a == b) {  // both

                node->next = new ListNode(a);
                node->next->next = new ListNode(a);
                node = node->next->next;

                list1 = list1->next;
                list2 = list2->next;
            } else {  // b in
                node->next = new ListNode(b);
                node = node->next;
                
                list2 = list2->next;
            }  
        }

        return result->next;
    }

#endif  // MERGE

public:
    void displayLinkedList(ListNode *head) {
        
        ListNode *node = head;
        
        while (NULL != node) {
            cout << node->val << "->";
            node = node->next;
        }

        cout << endl;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {

#ifdef BRUTE_FORCE

#endif // BRUTE_FORCE
        
#ifdef VECTOR

        ListNode *head;

        if (lists.empty()) return NULL;

        vector<int> num_vec;

        for (int i = 0; i < lists.size(); ++i) {

            ListNode* node = lists[i];

            while (NULL != node) {
                num_vec.push_back(node->val);
                node = node->next;
            }
        }
        
        if (num_vec.empty()) return NULL;

        // sort the vector
        sort(num_vec.begin(), num_vec.end());        

        // gen a linked list
        head = new ListNode(num_vec[0]);
        ListNode *node = head;

        for (int i = 1; i < num_vec.size(); ++i) {
            node->next = new ListNode(num_vec[i]);
            node = node->next;
        }

        return head;

#endif // VECTOR

#ifdef MERGE

        ListNode *head;

        // cout << lists.size() << endl;

        if (lists.empty()) return NULL;

        if (1 == lists.size()) return lists[0];

        if (lists.size() % 2 == 1) lists.push_back(NULL);

        vector<ListNode *> temps;

        for (int i = 0; i < lists.size(); i++) {

            ListNode* temp = merge2Lists(lists[++i], lists[i]);
            
            temps.push_back(temp);
        }

        return mergeKLists(temps);

        

#endif  // MERGE

    }


    ListNode* genLinkedList(vector<int> nums) {

        ListNode* head;

        if (nums.empty()) return head;
        
        head = new ListNode(nums[0]);

        ListNode* node = head;        

        for (int i = 1; i < nums.size(); ++i) {
            node->next = new ListNode(nums[i]);
            node = node->next;
        }

        displayLinkedList(head);
        return head;
    }

};


int main() {

    Solution s;

    int k = 3;

    vector<ListNode *> lists;

    for (int i = 0; i < k; ++i) {
        vector<int> nums;
        int target;
        util::random_int_vector(nums,
                                target,
                                0,   // min
                                10,  // max
                                5    // len
            );

        sort(nums.begin(), nums.end());
        ListNode* list = s.genLinkedList(nums);

        lists.push_back(list);
        
    }

    ListNode* result = s.mergeKLists(lists);

    s.displayLinkedList(result);
    

    return 0;
}
