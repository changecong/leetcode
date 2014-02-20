/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Feb 20 12:32:35 2014
 * Modified at:   Thu Feb 20 14:45:28 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

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
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

        if(l1 == NULL && l2 == NULL) return NULL;
        else if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;

        ListNode* head;

        ListNode* node;
        ListNode* other;

        if (l1->val < l2->val) {
            head = l1;
            other = l2;
        } else {
            head = l2;
            other = l1;
        }
        
        node = head;

        while(true) {
            
            if (other == NULL) break;
            if (node->next == NULL) {
                node->next = other;
                break;
            }

            if (node->next->val <= other->val) {
                node = node->next;
            } else {  // switch node and other
                ListNode *temp = node->next;
                node->next = other;
                other = temp;
            }

        }


        return head;
    }
};


int main() {

    Solution s;

    int L_1[5] = {1, 2, 4, 6, 7};
    int L_2[7] = {1, 3, 5, 10, 15, 16, 17};

    ListNode *l1 = new ListNode(L_1[0]);
    ListNode *node = l1;
    for (int i = 1; i < 5; ++i) {
        node->next = new ListNode(L_1[i]);
        node = node->next;
    }

    ListNode *l2 = new ListNode(L_2[0]);
    node = l2;
    for (int i = 1; i < 7; ++i) {
        node->next = new ListNode(L_2[i]);
        node = node->next;
    }

    ListNode *result = s.mergeTwoLists(l1, l2);

    while (result != NULL) {
        cout << result->val << " -> ";
        result = result->next;
    }
    cout << "NULL" << endl;

    return 0;
}
