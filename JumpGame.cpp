//
//  JumpGame.cpp
//  
//
//  Created by 廷芳 杜 on 4/3/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int calcMaxJump( int A[], int n, int startId, int endId )
    {
        int range=0;
        if( startId == endId ) 
            return 0;
        else
        {
            for( int i = startId; i< endId; ++i )
            {
                range = max( range, i+A[i] );
            }
        }
        return range;
    }
    
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        if( n == 0 ) return false;
        if( n == 1 ) return true;
        
        std::vector<int> zeroIds;
        for(int i = 0 ; i<n ; i++ )
        {
            if( A[i] == 0 )
                zeroIds.push_back(i);
        }
        int len = zeroIds.size();
        if(len == 0 )
            return true;
        else
        {
            int last0 = 0;
            int maxRange[len];
            int range = 0;
            for(int i=0;i<len;i++)
            {
                maxRange[i] = calcMaxJump( A, n, last0, zeroIds[i] );
                range = max( maxRange[i] , range );
                if( range >= n-1 )
                    return true;
                else
                {
                    last0 = zeroIds[i];
                    j++;
                }
            }
            return false;
        }
    }
};