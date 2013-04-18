//
//  LongestConsecutiveSequences.cpp
//  
//
//  Created by 廷芳 杜 on 4/18/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if( num.size() == 0 ) return 0;
        if( num.size() == 1 ) return 1;
        
        unordered_multimap<int, int> hash;
        for( int i = 0 ; i< num.size(); i++ )
        {
            hash.emplace( num[i], num[i] );
        }
        
        int maxCount = 0;
        for( int i = 0 ; i< num.size(); i++)
        {
            if( hash.count(num[i]) > 0) 
            {
                maxCount = max( maxCount, countLower(hash, num[i])+countHigher(hash, num[i]+1)  );
            }
        }
        
        return maxCount;
    }
    
    int countLower(unordered_multimap<int, int> &hash, int element )
    {
        int count = 0;
        while( hash.count(element)>0)
        {
            count++;
            hash.erase( element );
            element--;
        }
        return count;
    }
    
    int countHigher(unordered_multimap<int, int> &hash, int element )
    {
        int count = 0;
        while( hash.count(element)>0)
        {
            count++;
            hash.erase( element );
            element++;
        }
        return count;
    }
    
};