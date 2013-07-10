//
//  MergeSortedArrays.cpp
//  
//
//  Created by 廷芳 杜 on 7/9/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
ass Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n == 0 ) return;
        if( m == 0 )
        {
            for( int i = 0 ; i < n ; i++ )
                A[i] = B[i];
        }
        
        int ptA = m-1;
        int ptB = n-1;
        int pt = m+n-1;
        
        while( ptA>=0 && ptB>=0 )
        {
            if( A[ptA] < B[ptB] )
            {
                A[pt] = B[ptB];
                ptB--;
                pt--;
            }
            else
            {
                A[pt] = A[ptA];
                ptA--;
                pt--;
            }
        }
        
        if( ptA>= 0 )
        {
            while( pt>=0 )
                A[pt--] = A[ptA--];
            
            return;
        }
        else
        {
            while( pt>=0 )
                A[pt--] = B[ptB--];
            
            return;
        }
        
    }
};