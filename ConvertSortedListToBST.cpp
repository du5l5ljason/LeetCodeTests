//
//  ConvertSortedListToBST.cpp
//  
//
//  Created by 廷芳 杜 on 4/22/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getLength( ListNode *head )
    {
        if( head == NULL ) return 0;
        int count = 0;
        
        while ( head!= NULL )
        { 
            count++;
            head = head->next;
        }
        return count;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //1. go the medium of the sortedlist, put 
        //create bst root based on this node
        //2. create BST left using head to medium
        //create BST right using medium+1 to end 
        //complexity O(nlogn );
        if( head == NULL ) return NULL;
        
        int len = getLength( head );
        TreeNode *newNode = createBST( head, 0, len-1 );
        return newNode;
    }
    
    TreeNode *createBST( ListNode *node, int start, int end )
    {
        if( node == NULL ) return NULL;
        if( start>end ) return NULL;
        int mid = (start+end)/2;
        ListNode *current = node;
        for( int i = start ; i<mid; i++ )
        {
            current = current->next;
        }
        TreeNode *newNode = new TreeNode( current->val );
        newNode->left = createBST( node, start, mid-1);
        newNode->right = createBST( current->next, mid+1, end );
        
        return newNode;
    }
    
};