//
//  SearchInRotatedArray.cpp
//  
//
//  Created by 廷芳 杜 on 7/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n == 0 ) return -1;
        if( n == 1 ) return A[0]==target?0:(-1);
        
        int l = 0;
        int r = n-1;
        
        while( l <= r )
        {
            int m = (l+r)/2;
            if( A[m] == target ) return m;
            if( A[m] < target )
            {
                if( A[r] == target )
                    return r;
                else if( A[r] > target )
                    l = m+1;
                else
                    r--;
            }
            else
            {
                if( A[l] == target )
                    return l;
                else if( A[l] < target )
                    r = m-1;
                else
                    l++;
            }
        }
        return -1;
    }
};