//
//  UniquePaths.cpp
//  
//
//  Created by 廷芳 杜 on 7/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==0&&n==0) return 0;
        if( m==0 ) return 1;
        if( n==0 ) return 1;
        
        int paths[m][n];
        memset( paths, 0, sizeof(int)*m*n );
        paths[0][0] = 1;
        for( int i = 1; i < m; i++ ) paths[i][0] = 1;
        for( int j = 1; j < n; j++ ) paths[0][j] = 1;        
        for( int i = 1; i < m ; i++ )
            for( int j = 1; j < n ; j++ )
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
        
        return paths[m-1][n-1];
    }
};