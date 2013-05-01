//
//  PalindromNumber.cpp
//  
//
//  Created by 廷芳 杜 on 4/30/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int highest=1;
        int lowest=10;
        int temp=x;
        if( x<0 ) return false;
        if( x >=0 && x < 10 ) return true;
        
        while( temp/10 )
        {
            highest = 10*highest;
            temp = temp/10;
        }
        
        while( highest >= lowest )
        {
            temp = abs(x%lowest);
            x = x-temp;
            if( temp >= 10 )
            {
                while( temp/10 )
                    temp = temp/10;
            }
            if( x/highest != temp )
                return false;
            
            x = x - x/highest*highest;
            highest = highest/10;
            lowest = lowest*10;
        }
        
        return true;
    }
};