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
    bool isFound(vector< vector<bool> > &table, int id)
    {
        if( table[id].size() == 0 )
            return false;
        else
        {
            for( int i = 0 ; i< table[id].size(); i++ )
            {
                if( table[id][i] == 1 )
                    return true;
            }
            return false;
        }
    }
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //scan the string, and search if the current character is already found, if not, set is to found.
        //create a longestNumstring, to store the longest string.
        //each time, 
        // if isn't found, numOfLS[i] = numOfLS[i-1] + 1;  add the character.
        // if is found. numofLS[i] = 1;, clear the table, add the chracter.
        int len = s.length();
        if( len <= 0 ) return -1;
        else if( len == 1 ) return 1;
        
        vector< vector<bool> > isFoundTab;
        for( int i = 0 ; i< 256; i++ )
            for( int j = 0 ; j < len; j++ )
            {
                isFoundTab[i][j] = 0;
            }
        int numOfLS[ len ];
        memset( numOfLS, 0, len*sizeof( int ) );
        
        for( int i = 0; i < len; i++ )
        {
            if( i == 0 ) 
            {
                numOfLS[0] = 1;
                isFoundTab[s[i]][i] = 1;
            }
            else if(isFound(isFoundTab, i))
            {
                //find the id, and update the numOfLS.
                for( int j = 0 ; j < isFoundTab[s[i]].size(); j++ )
                {
                    if(isFoundTab[s[i]][j] == 1 )
                        numOfLS[i] = i - j;
                }
                isFoundTab[s[i]][i] = 1;
            }
            else
            {
                numOfLS[i] = numOfLS[i] + 1;
                isFoundTab[s[i]][i] = 1;
            }
        }
        
        //find the largest number in the array of numOfLS
        int longest = 0;
        for( int i = 0 ; i< len ; i++ )
        {
            if( longest < numOfLS[i] )
                longest = numOfLS[i];
        }
        
        return longest;
    }
};