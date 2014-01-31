/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Jan 31 15:11:30 2014
 * Modified at:   Fri Jan 31 17:20:19 2014
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

#ifdef SPLIT_JOINT

private:

    ListNode* reverseFirstK(ListNode *head, int k) {

        ListNode* node = head;

        if (k == 2) {
            ListNode* temp = new ListNode(head->val); 
            head = head->next;
            temp->next = NULL;
            head->next = temp;
            return head;
        }

        // start from the second
        while (k > 1) {
            
            // save
            ListNode* temp = new ListNode(node->next->val);
            
            // reomve
            node->next = node->next->next;
            
            // add to the front
            temp->next = head;
            head = temp;
            
            k--;
        }

        node->next = NULL;

        return head;
    }

#endif  // PLIT_JOINT

public:
    ListNode *reverseKGroup(ListNode *head, int k) {

#ifdef SPLIT_JOINT

        if (2 > k) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* node = head;
        ListNode* next = head;

        while (NULL != node) {
            
            int i = 0;

            // calculate k nodes
            for (i = 0; i < k; i++) {
                
                if (NULL != next->next) {
                    next = next->next;
                } else {
                    break;
                }
                
            }

            if (i < (k - 1)) {
                next = NULL;
                // no need to continue
                break;
            } if (i == (k-1)) {
                next = NULL;
            }

            // reverse from the node
            ListNode* temp = reverseFirstK(node, k);


            // joint
            if (NULL == prev) {
                head = temp;
            } else {
                prev->next = temp;
            }

            while (NULL != temp->next) {
                prev = temp->next;
                temp = temp->next;
            }
            
            temp->next = next;

            node = temp->next;        
        }
        
        return head;

#endif  // PLIT_JOINT
        
    }


    ListNode* genLinkedList(int a[], int len) {
        
        if (0 == len) return NULL;

        ListNode* head = new ListNode(a[0]);
        ListNode* node = head;

        for (int i = 1; i < len; ++i) {
            node->next = new ListNode(a[i]);
            node = node->next;
        }

        return head;
        
    }

    void displayLinkedList(ListNode* head) {

        ListNode* node = head;

        while (NULL != node) {
            cout << node->val << "->";
            node = node->next;
        }

        cout << endl;
    }

};


int main() {

    Solution s;

    int a[4] = {1, 2, 3, 4};

    int k = 4;

    ListNode* list = s.genLinkedList(a, 4);

    ListNode* result = s.reverseKGroup(list, k);

    s.displayLinkedList(result);

    return 0;
}
