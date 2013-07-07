//
//  Triangle.cpp
//  
//
//  Created by 廷芳 杜 on 7/5/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( triangle.size() == 0 ) return 0;
        if( triangle.size() == 1 ) return triangle[0][0];
        
        for( int i = 0 ; i< triangle.size() ; i++ )
        {
            for( int j = 0 ; j < triangle[i].size(); j++ )
            {
                if( i == 0 )
                    triangle[i][j] = triangle[0][0];
                else if( j == 0 )
                    triangle[i][j] = triangle[i-1][j] + triangle[i][j];
                else if( j == triangle[i].size()-1 )
                    triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
                else
                    triangle[i][j] = min( triangle[i-1][j], triangle[i-1][j-1] ) + triangle[i][j];
            }
        }
        
        int minVal = 100000;
        
        for( int i = 0 ; i < triangle[triangle.size()-1].size(); i++ )
        {
            if( triangle[triangle.size()-1][i] < minVal ) 
                minVal = triangle[triangle.size()-1][i];
        }
        
        return minVal;
    }
};