//
//  MergeTwoSortedArrays.cpp
//  
//
//  Created by 廷芳 杜 on 4/2/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    double findMedianSortedArraysEven( int A[], int m, int B[], int n){
        double median;
        int midA = m/2;
        int midB = n/2;
        int subLenA = m/2;
        int subLenB = n/2;
        int start = 0;  //lowerBand id of median
        int end = (m+n)-1;  //upperBand id of median
        
        
        while ( subLenA > 0 || subLenB > 0 )
        {
            if( A[midA] >= B[midB] ) 
            {
                start = start + subLenB; 
                if( start > (m+n)/2-1 )
                {
                    start = start - subLenB;
                    return findMedianPair( A, midA, m, B, midB, n, start );
                }
                end = end - subLenA;
                subLenA = subLenA/2;
                subLenB = subLenB/2;
                midA = midA - subLenA;
                midB = midB + subLenB;
            }
            else
            {
                start = start + subLenA; 
                if( start > (m+n)/2-1 )
                {
                    start = start - subLenA;
                    return findMedianPair( A, midA, m, B, midB, n, start );
                }
                end = end - subLenB;
                subLenA = subLenA/2;
                subLenB = subLenB/2;
                midA = midA + subLenA;
                midB = midB - subLenB;                
            }
        }
        
        //if goes to here, subLenA == 1, subLenB == 1, then
        median = ( A[midA] , B[midB] )/2.0;
        
        
        return median;       
    }
    double findMedianSortedArraysOdd( int A[], int m, int B[], int n ){
        double median;
        int midA = m/2;
        int midB = n/2;
        int subLenA = m/2;
        int subLenB = n/2;
        int start = 0;  //lowerBand id of median
        int end = (m+n)-1;  //upperBand id of median
        
        //simply case, if A[midA] == B[midB] , return A[midA], because before A[midA], 
        //there are m/2 elements in A, and before B[midB], there are n/2 in B.
        //Since we want to return the (m+n)/2 + 1 th element, thus we just return A[midA]
        if( A[midA] == B[midB] )
            return A[midA];
        
        while ( subLenA > 0 || subLenB > 0 )
        {
            if( A[midA] >= B[midB] ) 
            {
                start = start + subLenB; 
                if( start > (m+n)/2 )
                {
                    start = start - subLenB;
                    return findMedianElement( A, midA, m, B, midB, n, start );
                }
                end = end - subLenA;
                subLenA = subLenA/2;
                subLenB = subLenB/2;
                midA = midA - subLenA;
                midB = midB + subLenB;
            }
            else
            {
                start = start + subLenA; 
                if( start > (m+n)/2 )
                {
                    start = start - subLenA;
                    return findMedianElement( A, midA, m, B, midB, n, start );
                }
                end = end - subLenB;
                subLenA = subLenA/2;
                subLenB = subLenB/2;
                midA = midA + subLenA;
                midB = midB - subLenB;                
            }
        }
        
        //if goes to here, subLenA == 1, subLenB == 1, then
        median = min( A[midA] , B[midB] );
        
        
        return median;  
    }
    
    double findMedianElement( int A[], int midA, int m, int B[], int midB, int n, int start){
        
        while( start < (m+n)/2 && midA < m && midB < n){
            if( A[midA] >= B[midB] )
            {
                midB++;
                start++;
                if( start == (m+n)/2 )
                    return A[midA]<=B[midB]?A[midA]:B[midB];
            }
            else
            {
                midA++;
                start++;
                if( start == (m+n)/2 )
                    return A[midA]<=B[midB]?A[midA]:B[midB];
            }
        }
        
        if( midA == m )
        {
            while( start< (m+n)/2 )
            {
                midB++;
                start++;
            }
            return B[midB];
        }
        else if( midB == n )
        {
            while( start < (m+n)/2 )
            {
                midA++;
                start++;
            }
            return A[midA];
        }
        
    }
    
    double findMedianPair(int A[], int midA, int m, int B[], int midB, int n, int start)
    {
        while( start < (m+n)/2-1 && midA < m && midB < n){
            if( A[midA] >= B[midB] )
            {
                midB++;
                start++;
                if( start == (m+n)/2-1 )
                {
                    int pair1 = min(A[midA], B[midB]);
                    if( pair1 == A[midA] ) midA++;
                    else if( pair1 == B[midB]) midB++;
                    int pair2 = min(A[midA], B[midB]);
                    return (pair1+pair2)/2.0;
                }
            }
            else
            {
                midA++;
                start++;
                if( start == (m+n)/2-1 )
                {
                    int pair1 = min(A[midA], B[midB]);
                    if( pair1 == A[midA] ) midA++;
                    else if( pair1 == B[midB]) midB++;
                    int pair2 = min(A[midA], B[midB]);
                    return (pair1+pair2)/2.0;
                }
            }
        }
        
        if( midA == m )
        {
            while( start< (m+n)/2-1 )
            {
                midB++;
                start++;
            }
            return (B[midB]+B[midB+1])/2.0;
        }
        else if( midB == n )
        {
            while( start < (m+n)/2-1 )
            {
                midA++;
                start++;
            }
            return (A[midA]+A[midA+1])/2.0;
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( m == 0 && n == 0 ) return 0;
        else if( m == 0 && n == 1 ) 
            return B[0];
        else if( m == 1 && n == 0 )
            return A[0];
        else if( m == 1 && n == 1 )
            return (A[0]+B[0])/2;
        //Two cases: m+n is even, then the median is (O[(m+n)/2-1] + O[(m+n)/2])/2,
        //assuming that the O[] stands for the merged array.
        //if m+n is odd, then median is O[(m+n)/2].
        
        if( (m+n)%2 == 0 ) //even
            return findMedianSortedArraysEven( A, m, B, n);
        else
            return findMedianSortedArraysOdd( A, m, B, n );
    }
    
};