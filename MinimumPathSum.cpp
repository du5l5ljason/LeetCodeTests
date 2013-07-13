//
//  MinimumPathSum.cpp
//  
//
//  Created by 廷芳 杜 on 7/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( grid.size() == 0 ) return 0;
        if( grid[0].size() == 0 ) return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        int minSum[row][col];
        memset( minSum, 0, row*col*sizeof( int ) );
        
        minSum[0][0] = grid[0][0];
        for( int i = 1 ; i < row; i++ )
            minSum[i][0] = minSum[i-1][0] + grid[i][0];
        for( int i = 1; i < col; i++ )
            minSum[0][i] = minSum[0][i-1] + grid[0][i];
        
        for( int i = 1 ; i < row ; i++ )
        {
            for( int j = 1; j< col; j++ )
            {
                minSum[i][j] = grid[i][j] + min( minSum[i-1][j], minSum[i][j-1] );
            }
        }
        return minSum[row-1][col-1];
    }
};