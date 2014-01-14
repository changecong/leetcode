/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Jan 13 11:11:01 2014
 * Modified at:   Mon Jan 13 12:15:36 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {

private:
    ListNode *addCarry(ListNode *list, int c) {
        list->val = list->val + c;
        if (list->val < 10) {
            return list;
        } else {
            c = (int)(list->val / 10);
            list->val = list->val % 10;
            if (NULL != list->next) {
                list->next = addCarry(list->next, c);
            } else {
                list->next = new ListNode(c);
            }

            return list;
        }
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        if(NULL == l1) return l2;
        if(NULL == l2) return l1;

        ListNode *head = new ListNode(-1);
        ListNode *node = head;
        int c = 0;

        // both digits in l1 and l2 are exist
        while(NULL != l1 && NULL != l2 ) {

            int sum = l1->val + l2->val + c;
            c = (sum > 9) ? (int)(sum/10) : 0;
            sum = sum % 10;
            node->next = new ListNode(sum);
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // only l1 has digit
        if (NULL != l1) {
            node->next = addCarry(l1, c);
        } else if (NULL != l2) {  // only l2 has digit
            node->next = addCarry(l2, c);
        } else {  // only carry exist
            if (c > 0) {
                node->next = new ListNode(c);
                node = node->next;
            }
        }

        return head->next;
        
    }
};


int main() {

    Solution s;

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

    int a[3] = {2, 4, 3};
    int b[4] = {5, 6, 7, 9};

    ListNode *l1 = new ListNode(a[0]);
    ListNode *node1 = l1;
    ListNode *l2 = new ListNode(b[0]);
    ListNode *node2 = l2;
    for (int i = 1; i < 3; ++i) {
        node1->next = new ListNode(a[i]);
        node1 = node1->next;
    }
    
    for (int i = 1; i < 4; ++i) {
        node2->next = new ListNode(b[i]);
        node2 = node2->next;
    }

    ListNode *result = s.addTwoNumbers(NULL, l2);

    while (NULL != result) {
        cout << result->val << " -> ";
        result = result->next;
    }

    cout << endl;

    return 0;
}
