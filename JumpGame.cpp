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
    
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        if( n== 0 ) return false;
        if( n == 1 ) return true;
        
        int range = A[0];
        for( int i = 0; i<=range; ++i )
        {
            range = max( range, i+A[i] );
            if( range >=n-1 ) return true;
        }
        return false;
    }
};