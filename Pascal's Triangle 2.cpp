//
//  Pascal's Triangle 2.cpp
//  
//
//  Created by 廷芳 杜 on 7/5/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> row(rowIndex+1, 0);
        if( rowIndex < 0 ) return row;
        
        for( int i = 0 ; i<= rowIndex ; i++ )
        {
            vector<int> copy = row;
            for( int j = 0 ; j <=i ; j++ )
            {
                
                if( i == 0 )
                    row[0] = 1;
                else
                {
                    if( j == 0 )
                        row[j] = 1;
                    else if( j == i )
                        row[j] = 1;
                    else
                        row[j] = copy[j-1] + copy[j];
                }
            }
        }
        
        return row;
    }
};