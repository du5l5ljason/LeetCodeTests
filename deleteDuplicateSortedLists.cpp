//
//  deleteDuplicateSortedLists.cpp
//  
//
//  Created by 廷芳 杜 on 4/29/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( head == NULL ) return NULL;
        
        ListNode *current = head->next;
        ListNode *newCur = head;
        while( current != NULL )
        {
            if( current->val != newCur->val )  
            {
                newCur->next = current;
                newCur = newCur->next;
            }    
            current = current->next;
        }
        newCur->next = NULL;
        return head;
    }
};