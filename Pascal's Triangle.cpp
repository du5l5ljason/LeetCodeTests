//
//  Pascal's Triangle.cpp
//  
//
//  Created by 廷芳 杜 on 7/5/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > triangle;
        
        if( numRows == 0 ) return triangle;
        
        for( int i = 0 ; i < numRows ; i ++ )
        {
            vector<int> row;
            for( int j = 0; j <= i ; j++ )
            {
                if( i == 0 )
                    row.push_back( 1 );
                else
                {
                    if( j == 0 )
                        row.push_back(1);
                    else if( j == i )
                        row.push_back(1);
                    else
                        row.push_back( triangle[i-1][j-1] + triangle[i-1][j] );
                }
            }
            triangle.push_back(row);
        }
        
        return triangle;
    }
};