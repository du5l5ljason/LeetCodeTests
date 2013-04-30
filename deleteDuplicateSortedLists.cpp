//
//  deleteDuplicateSortedLists.cpp
//  
//
//  Created by 廷芳 杜 on 4/29/13.
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( head == NULL ) return NULL;
        
        ListNode *current = head->next;
        ListNode *newList = head;
        ListNode *newCur = newList;
        int temp = head->val;
        while( current != NULL )
        {
            if( current->val != temp )  //delete this
            {
                newCur->next = current;
                newCur = newCur->next;
                temp = current->val;
            }    
            current = current->next;
        }
        newCur->next = NULL;
        return newList;
    }
};