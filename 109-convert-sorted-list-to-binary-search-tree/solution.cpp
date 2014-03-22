/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Mar 21 22:24:32 2014
 * Modified at:   Fri Mar 21 23:04:58 2014
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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *sortedListToBST(ListNode *head, int len) {

        TreeNode *result = NULL;

        if (NULL == head || len = 0) return result;

        // get the middle
        int mid = len / 2;
        
        // get the left head
        ListNode *left_head = head;

        // get the middle value
        ListNode *node = head;
        int idx = 0;
        while (idx < mid) {
            node = node->next;
            idx++;
        }

        int left_len = idx;

        // mid one
        result = new TreeNode(node->val);

        // get the right head
        ListNode *right_head = node->next;

        int right_len = len - left_len - 1;

        result->left = sortedListToBST(left_head, left_len);
        result->right = sortedListToBST(right_head, right_len);
              
        return result;
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        
        TreeNode *result = NULL;
        // list
        if (NULL == head) return result;

        // traversal, get the length
        int len = 0;
        ListNode *node = head;
        while (node != NULL) {
            node = node->next;
            len++;
        }

        return sortedListToBST(head, len);
    }
};


int main() {

    cout << "Too lazy to write a test case!" << endl;    

    return 0;
}
