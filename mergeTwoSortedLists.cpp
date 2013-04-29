//
//  mergeTwoSortedLists.cpp
//  
//
//  Created by 廷芳 杜 on 4/26/13.
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
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( l1 == NULL && l2 == NULL ) return NULL;
        if( l1 == NULL ) return l2;
        if( l2 == NULL ) return l1;
        
        //l1 and l2 are not NULL.
        ListNode *result = NULL;
        
        if( l1->val <= l2->val )
        {
            result = l1;
            result->next = mergeTwoLists( l1->next, l2 );
        }
        else
        {
            result = l2;
            result->next = mergeTwoLists( l1, l2->next );
        }
        
        return result;
    }
};