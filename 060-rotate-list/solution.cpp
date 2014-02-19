/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Feb 18 22:39:29 2014
 * Modified at:   Tue Feb 18 22:59:13 2014
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
    ListNode *rotateRight(ListNode *head, int k) {
        
        if (head == NULL) return NULL;
        if (k == 0) return head;

        ListNode* ptr_0 = head;
        ListNode* ptr_1 = head;

        int len = 0;

        while(len < k) {
            len++;
            ptr_1 = ptr_1->next;
            if (ptr_1 == NULL) {  // k is large than the length;
                k = k % len;
                if (k == 0) return head;
                len = 0;
                ptr_1 = head;
            }
        }

        

        while(ptr_1->next != NULL) {
            len++;
            ptr_0 = ptr_0->next;
            ptr_1 = ptr_1->next;            
        }
        
        ListNode* next = ptr_0->next;  // new head;
        ptr_0->next = NULL;

        ptr_1->next = head;

        return next;

    }
};


int main() {

    Solution s;

    ListNode *head = new ListNode(1);
    ListNode *node = head;
    for(int i = 2; i <= 5; ++i) {
        node->next = new ListNode(i);
        node = node->next;
    }

    int k = 0;
    ListNode *result = s.rotateRight(head, k);

    while(result != NULL) {
        cout << result->val << "-> " ;
        result = result->next;
    }

    cout << "NULL" << endl;

    return 0;
}
