//
//  SearchForARange.cpp
//  
//
//  Created by 廷芳 杜 on 7/9/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> range;
        if( n == 0 ) return range;
        int start = 0;
        int end = n-1;
        int min = end;
        int max = start;
        bool isFound = binarySearch( A, n, target, start, end, min, max );
        
        if( !isFound )
        {
            range.push_back(-1);
            range.push_back(-1);
            return range;
        }
        else
        {
            range.push_back( min );
            range.push_back( max );
            return range;
        }
    }
    
    bool binarySearch( int A[], int n, int target, int startId, int endId, int &min, int &max )
    {
        if( endId < startId ) return false;
        
        int len = endId - startId + 1;
        int mid = startId + len/2;
        int flag;
        
        if( A[mid] < target )
            flag = binarySearch( A, n, target, mid+1, endId, min, max );
        else if( A[mid] > target )
            flag = binarySearch( A, n, target, startId, mid-1, min, max );
        else
        {
            flag = true;
            if( mid == 0 ) min = mid;
            if( mid == n-1 ) max = mid;
            
            if( A[mid-1] < A[mid] ) //this is the lower bound
                min = mid;
            if( A[mid+1] > A[mid] )
                max = mid;
            
            if( min==n-1 || max==0 )// in the middle
            {
                binarySearch( A, n, target, startId, mid-1, min, max );
                binarySearch( A, n, target, mid+1, endId, min, max );
            }
            
        }
        
        return flag;
    }
};