//
//  NextPermutation.cpp
//  
//
//  Created by 廷芳 杜 on 7/19/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( num.size() == 0 || num.size() == 1 ) return;
        for( int i = num.size() -1 ; i>=1; i-- )
        {
            if( num[i] > num[i-1] ) //find the digit to be swap
            {
                int minId = i;
                for( int j = i;j< num.size() ; j++ )
                    if( num[j] > num[i-1] && num[j] < num[minId] )
                        minId = j;   
                swap( num[i-1], num[minId] );
                sort( num.begin() + i, num.end() );
                return;
            }
        }
        //not find that digit
        sort( num.begin(), num.end() );
    }
};