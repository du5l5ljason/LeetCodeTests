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
        int startIdA = m/2;
        int startIdB = n/2;
        int currentId = 0 ;
        int thresh = (m+n)/2-1;
        
        if( m == 0 )
            return (B[n/2-1] + B[n/2])/2.0;
        else if(n == 0)
            return (A[m/2-1] + A[m/2])/2.0;
        while( currentId < thresh )
        {
            if( A[startIdA] <= B[startIdB] )
            {
                startIdA += startIdA + (m - startIdA )/2;
                currentId += ( m-startIdA );
                if( currentId >= thresh )
                {
                    currentId = currentId - ( m-startIdA );
                    startIdA = startIdA- (m-startIdA)/2;
                    break;
                }
            }
            else
            {
                startIdB += startIdB + (n- startIdB)/2;
                currentId += (n-startIdB);
                if( currentId >= thresh )
                {
                    currentId = currentId - ( m-startIdB );
                    startIdB = startIdB- (m-startIdB)/2;
                    break;
                }
            }
        }
        
        //find median between A[startIdA]-A[m] and B[startIdB]-B[n]
        while( currentId < thresh )
        {
            if( A[startIdA] <= B[startIdB] )
            {
                startIdA ++;
            }   
            else    startIdB++;
            
            currentId++;
        }
        //currentId = (m+n)/2-1;
        int median1 = A[startIdA]<=B[startIdB]?A[startIdA++]:B[startIdB++];
        int median2;
        if( startIdA>=m ) 
            median2 = B[startIdB];
        else if( startIdB>=n )
            median2 = A[startIdA];
        else
            median2 = A[startIdA]<=B[startIdB]?A[startIdA]:B[startIdB];
        return (median1+median2)/2;
    }
    
    double findMedianSortedArraysOdd( int A[], int m, int B[], int n){
        
        int startIdA = m/2;
        int startIdB = n/2;
        int currentId = 0 ;
        int thresh = (m+n)/2;
        
        if( m == 0 )
            return B[n/2];
        else if(n == 0)
            return A[m/2];
        while( currentId < thresh )
        {
            if( A[startIdA] <= B[startIdB] )
            {
                startIdA += startIdA + (m - startIdA )/2;
                currentId += ( m-startIdA );
                if( currentId >= thresh )
                {
                    currentId = currentId - ( m-startIdA );
                    startIdA = startIdA- (m-startIdA)/2;
                    break;
                }
            }
            else
            {
                startIdB += startIdB + (n- startIdB)/2;
                currentId += (n-startIdB);
                if( currentId >= thresh )
                {
                    currentId = currentId - ( m-startIdB );
                    startIdB = startIdB- (m-startIdB)/2;
                    break;
                }
            }
        }
        
        //find median between A[startIdA]-A[m] and B[startIdB]-B[n]
        while( currentId < thresh )
        {
            if( A[startIdA] <= B[startIdB] )
            {
                startIdA ++;
            }   
            else    startIdB++;
            
            currentId++;
        }
        //currentId = (m+n)/2-1;
        return A[startIdA]<=B[startIdB]?A[startIdA]:B[startIdB];
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