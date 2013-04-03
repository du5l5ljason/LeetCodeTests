//
//  JumpGame.cpp
//  
//
//  Created by 廷芳 杜 on 4/3/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool canJumpHelper( int A[], int currentId, int endId )
    {
        if( currentId == endId ) return true;
        if( A[currentId] == 0 ) return false;
        
        int range = A[currentId];   
        for( int i = 1 ; i<= range ; i++ )
        {
            currentId = currentId + i;
            if( canJumpHelper(A, currentId, endId) )
            {
                return true;
            }
            else
                currentId = currentId - i ;
        }
        return false;
    }
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        if( n== 0 ) return false;
        if( n == 1 ) return true;
        
        
        
        return canJumpHelper( A, 0, n-1 );
        
    }
};