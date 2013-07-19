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
        ListNode *read = head->next;    //Read original list.
        ListNode *write = head;         //Write the list.
        ListNode *collector = NULL;     //Point to the nodes to be deleted.
        while( read )
        {
            if( read->val != write->val ) //correct, write one 
            {
                write->next = read;
                write = write->next;
            }    
            else                        //duplicates, need to be deleted.
                collector = read;
            read = read->next;
            if(!collector) delete collector;
        }
        write->next = NULL;
        return head;
    }
};