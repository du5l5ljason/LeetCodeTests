//
//  UniqueBinarySearchTrees.cpp
//  
//
//  Created by 廷芳 杜 on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> uBST(n+1, 0);
        
        if( n == 0 ) return 0;
        if( n == 1 ) return 1;
        
        return numTreesHelper( n, uBST );
    }
    
    int numTreesHelper( int n, vector<int> &uBST )
    {
        if( n == 0 ) return 1;
        if( n == 1 ) return 1;
        
        int sum = 0;
        if( uBST[n] != 0 )
            return uBST[n];
        else
        {
            for( int i = 0 ; i < n ; i++ )
            {
                sum += numTreesHelper( i, uBST) * numTreesHelper( n-1-i, uBST );
            }
            uBST[n] = sum;
        }           
        
        return uBST[n];
    }
    
    
};