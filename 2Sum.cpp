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
        vector<int> numbersCopy = numbers;
        sort( numbers.begin(), numbers.end() );
        
        int len = numbers.size();
        int id1 = 0;
        int id2 = len-1;
        int min, max;
        
        while( id1 < id2 )
        {
            if( numbers[id1] + numbers[id2] < target )
                id1++;
            else if( numbers[id1] + numbers[id2] > target )
                id2--;
            else
            {
                min = numbers[id1];
                max = numbers[id2];
                break;
            }
        }
        
        for( int i = 0 ; i < numbersCopy.size() ; ++i )
        {
            if( numbersCopy[i] == min )
                min = i+1;
        }
        
        for( int i = 0 ; i < numbersCopy.size() ; ++i )
        {
            if( numbersCopy[i] == max && i!=min-1)
                max = i+1;
        }
        
        if( min > max )
            swap( min, max );
        
        result.push_back( min );
        result.push_back( max );
        
        return result;
        
    }
};