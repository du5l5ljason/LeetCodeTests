//
//  SortColors.cpp
//  
//
//  Created by 廷芳 杜 on 7/16/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n == 0 || n == 1) return;
        int front = 0;
        int back = n-1;
        int current = 0;    //when A[i] == 2, swap with A[front], when A[i] == 0, swap with A[back]
        while( current <= back)
        {
            while( back>front && A[front] == 0 ) front++;
            while( back>front && A[back] == 2 ) back--;
            
            if( current<back && A[current] == 2 ) swap(A[current], A[back]);
            if( current>front && A[current] == 0 ) swap(A[front], A[current]);
            current++;
        }
    }
};