//
//  2Sum.cpp
//  
//
//  Created by 廷芳 杜 on 4/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        
        map<int, int> map;
        
        int len = numbers.size();
        int l1 = 0;
        int l2 = 0;
        if( len < 2 ) return result;
        else
        {
            for( int i  = 0 ; i< numbers.size(); i++ )
            {
                map[i] = target - numbers[i];
            }
            
            for( int i = 0 ; i<numbers.size() ; i++ )
            {
                for( int j = 0 ; j < numbers.size(); j++ )
                {
                    if( map[i] == numbers[j] && i!= j )
                    {
                        l1 = j;
                        l2 = i;
                    }
                }
            }
            
            if( l1 > l2 )
                swap( l1 , l2 );
            
            result.push_back( l1+1 );
            result.push_back( l2+1 );
            return result;
        }
        
        
    }
};