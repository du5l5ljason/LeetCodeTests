//
//  RemoveDuplicatesFromSortedListsII.cpp
//  
//
//  Created by 廷芳 杜 on 7/19/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( !head ) return NULL;
        if( !head->next ) return head;
        ListNode *read = head;
        ListNode *newHead = NULL;
        ListNode *write = newHead;        
        ListNode *collector = NULL;
        int dupVal = 0;
        while( read && read->next)
        {
            if( read->val == read->next->val )
            {
                dupVal = read->val;
                while( read && read->val == dupVal ) 
                {
                    collector = read;
                    read = read->next;
                    delete collector;
                }
            }
            else    //no duplicates
            {
                if( !newHead ) 
                {
                    newHead = read;
                    write = newHead;
                }
                else
                {
                    write->next = read;
                    write = write->next;
                }
                read = read->next;
            }
        }
        if( read )
        {
            if( !newHead ) return read;
            else    
            {
                write->next = read;
                write = write->next;
            }
        }
        if(write)write->next = NULL;
        return newHead;
    }
};