//
//  ContainWithMostWater.cpp
//  
//
//  Created by 廷芳 杜 on 7/9/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if( height.size() == 0 ) return 0;
        
        int i = 0;
        int j = height.size()-1;
        int area = 0;
        int maxArea = 0;
        
        maxArea = min(height[i], height[j]) * (j-i );
        while( i < j )
        { 
            if( height[i] < height[j] )
                i++;
            else
                j--;
            
            area = min( height[i], height[j] ) * (j-i);      
            
            if( maxArea < area ) maxArea = area;
        }
        return maxArea;
    }
};