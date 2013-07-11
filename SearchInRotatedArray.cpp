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
    int offset = 0;
    int id = 0;
    
    void findOffset( int A[], int n, int start, int end )
    {
        if( start > end )   return;
        
        int mid = ( start+ end )/2;
        
        if( mid == 0 && A[mid]<A[n-1] && A[mid]<A[mid+1])
        {
            offset = 0;
            return;
        }
        if( mid == n-1 && A[mid]<A[mid-1] && A[mid] < A[0] )
        {
            offset = n-1;
            return;
        }
        if( mid>0 && mid<n-1 && A[mid] <A[mid+1] &&A[mid]<A[mid-1] )
        {
            offset = mid;
            return;
        }
        
        findOffset(A , n, start, mid-1);
        findOffset(A, n, mid+1, end);
        
    }
    
    bool binarySearch( int A[], int n, int target, int start, int end )
    {
        if( start > end ) return false;
        
        int mid = (start + end )/2;
        
        if( A[mid] < target )
            binarySearch( A, n, target, mid+1, end );
        else if( A[mid] > target )
            binarySearch( A, n, target, start, mid-1 );
        else
        {
            id = mid;
            return true;
        }
    }
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n==0 ) return -1;
        if( n==1 ) return ( A[0]==target?0:(-1) );
        
        findOffset( A, n, 0, n-1 );
        
        int B[n];
        int idB = 0;
        int idA = offset;
        while( idA < n )
            B[idB++] = A[idA++];
        idA = 0;
        while( idA < offset )
            B[idB++] = A[idA++];
        
        if( binarySearch( B, n, target, 0, n-1 ) )
            return (id+offset)<n?(id+offset):(id+offset-n);
        else
            return -1;
    }
};