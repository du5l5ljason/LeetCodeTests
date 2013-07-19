//
//  setMatricesZero.cpp
//  
//
//  Created by 廷芳 杜 on 7/18/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( matrix.size() == 0 || matrix[0].size() == 0 ) return;
        
        bool isZeroCol = false;
        bool isZeroRow = false;
        for( int i = 0 ; i < matrix.size(); i++ )
            if( matrix[i][0] == 0 ) 
                isZeroRow = true;
        for( int i = 0 ; i < matrix[0].size() ; i++ )
            if( matrix[0][i] == 0 )
                isZeroCol = true;
        
        for( int i = 1 ; i < matrix.size() ; i ++ )
        {
            for( int j = 1; j < matrix[0].size(); j++ )
            {
                if( matrix[i][j] == 0 )
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for( int i = 1 ; i < matrix.size() ; i++ )
        {
            for( int j = 1 ; j < matrix[0].size(); j++ )
            {
                if( matrix[i][0] == 0 || matrix[0][j] == 0 )
                    matrix[i][j] = 0;
            }
        }
        
        for( int i = 0 ; i < matrix.size(); i++ )
        {
            if( isZeroRow ) matrix[i][0] = 0;
        }
        for( int j = 0 ; j < matrix[0].size(); j++ )
        {
            if( isZeroCol ) matrix[0][j] = 0;
        }
    }
};