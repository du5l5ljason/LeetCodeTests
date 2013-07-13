//
//  RemoveDuplicatesFromSortedArrays.cpp
//  
//
//  Created by 廷芳 杜 on 7/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n == 0 || n == 1 ) return n;
        int start = 0;
        if( A[1] == A[0] )
        {
            while( A[start]==A[start+1] && start < n-1 )
                start++;
            if( start == n-1 ) return 1;
        }
        int i = start+1;
        int counter = 1; 
        while( i< n )
        {
            if( A[i] != A[i-1] ) counter++;
            i++;
        }
        int j = 1;
        for( int i = 1 ; i < n; i++ )
        {
            while( A[i]==A[j-1] && i<n ) i++;
            A[j] = A[i];
            j++;
        }
        return counter;
    }
};