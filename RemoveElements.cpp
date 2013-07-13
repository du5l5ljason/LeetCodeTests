//
//  RemoveElements.cpp
//  
//
//  Created by 廷芳 杜 on 7/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n == 0 ) return 0;
        if( n == 1 ) return A[0]==elem?0:1;
        int endId = n-1;
        for( int i = 0; i < n ; i++ )
        {
            if( A[i] == elem )
            {
                while( A[endId] == elem && endId > i )  endId--;
                int temp = A[i];
                A[i] = A[endId];
                A[endId] = temp;
            }
        }
        int counter = 0;
        for( int i = 0 ; i<n; i++ )
            if( A[i] != elem ) counter++;
        return counter;
    }
};