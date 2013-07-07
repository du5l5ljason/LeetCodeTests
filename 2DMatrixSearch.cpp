//
//  2DMatrixSearch.cpp
//  
//
//  Created by 廷芳 杜 on 7/6/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( matrix.size() == 0 ) return false;
        if( target < matrix[0][0] || target > matrix[matrix.size()-1][matrix[0].size()-1] ) return false;
        
        int i = 0;
        for( i = 0 ; i < matrix.size() ; i++ )
        {
            if( target < matrix[i][0] )
            {
                break;
            }
        }
        for( int j = 0 ; j < matrix[i-1].size(); j++ )
        {
            if( target == matrix[i-1][j] )
                return true;
        }
        return false;
    }
};