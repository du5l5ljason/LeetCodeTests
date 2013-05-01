//
//  LongestCommonPrefix.cpp
//  
//
//  Created by 廷芳 杜 on 4/30/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( strs.size()==0 ) return "";
        
        sort(strs.begin(), strs.end());     //sort the vector, so that we know the upperbound of the LCP.
        string lcp = "";
        for( int j = 0; j < strs[0].length(); j++ )
        {
            lcp = lcp + strs[0][j];
            for( int i = 0 ; i<strs.size(); i++ ) 
            {
                if( strs[i].substr(0,j+1) != lcp )
                {
                    lcp = lcp.substr(0, lcp.length()-1);
                    break;
                }
            }
        }    
        
        return lcp;
    }
};