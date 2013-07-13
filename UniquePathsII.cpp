//
//  UniquePathsII.cpp
//  
//
//  Created by 廷芳 杜 on 7/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( obstacleGrid.size() == 0 ) return 0;
        if( obstacleGrid[0].size() == 0 ) return 0;
        if( obstacleGrid[0][0] == 1) return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int paths[row][col];
        memset( paths, 0, row*col*sizeof( int ) );
        for( int i = 0 ; i < row; i++ ) 
        {
            paths[i][0] = !obstacleGrid[i][0];
            if( paths[i][0] == 0 ) break;
        }
        for( int j = 1 ; j < col; j++ ) 
        {
            paths[0][j] = !obstacleGrid[0][j];
            if( paths[0][j] == 0 ) break;
        }
        for( int i = 1 ; i < row; i++ )
        {
            for( int j = 1 ; j < col ; j++ )
            {
                if( obstacleGrid[i][j] == 1 ) paths[i][j] = 0;
                else
                    paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[row-1][col-1];
    }
};