//
//  Longest Substring without Repeating.cpp
//  
//
//  Created by 廷芳 杜 on 4/2/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //scan the string, and search if the current character is already found, if not, set is to found.
        //create a longestNumstring, to store the longest string.
        //each time, 
        // if isn't found, numOfLS[i] = numOfLS[i-1] + 1;  add the character.
        // if is found. numOfLS[i] = length between the repeated characters.
        //find the largest number in the array of numOfLS
        vector<int> existedId(256, -1);
        
        int len = s.length();
        if( len == 0 )
            return 0; 
        if( len == 1 )
            return 1;
        
        int numOfLS[len];
        memset(numOfLS, 0, len*sizeof(int));
        
        for( int i = 0 ; i < len ; i ++ )
        {
            if( existedId[s[i]] < 0 )
            {
                existedId[s[i]] = i;
                int id = i-1<0?0:i-1;
                numOfLS[i] = numOfLS[id] + 1;
            }
            else //existed
            {
                int repId = existedId[s[i]];
                numOfLS[i] = i - repId;
                existedId[s[i]] = i;
            }
        }
        
        int longest = 0;
        for( int i = 0 ; i< len ; i++ )
        {
            if( longest < numOfLS[i] )
                longest = numOfLS[i];
        }
        
        return longest;
    }
};