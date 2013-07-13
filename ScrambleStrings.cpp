//
//  ScrambleStrings.cpp
//  
//
//  Created by 廷芳 杜 on 7/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if( s1.empty() && s2.empty() && s3.empty() ) return true;
        if( s3.empty() ) return false;
        if( s1.empty() ) return s2==s3?true:false;
        if( s2.empty() ) return s1==s3?true:false;
        
        if( s3.size() != s1.size()+s2.size() ) return false;
        bool isValid[s1.size()][s2.size()];
        
        if( s3[0]!=s1[0]&&s3[0]!=s2[0] ) return false;
        isValid[0][0] = true;
        for( int i = 1; i < s1.size(); i++ )
            isValid[i][0] = (s3[i]==s1[i]?true:false);
        for( int i = 1; i < s2.size(); i++ )
            isValid[0][i] = (s3[i]==s2[i]?true:false);
        for( int i = 1; i < s1.size(); i++ )
        {
            for( int j = 1; j<s2.size(); j++ )
            {
                if( (s3[i+j+1] == s1[i] ) && s3[i+j+1] == s2[j])
                    isValid[i][j] = isValid[i-1][j] || isValid[i][j-1];
                else if( s3[i+j+1] == s2[j] )
                    isValid[i][j] = isValid[i][j-1];
                else if(s3[i+j+1] == s1[i] )
                    isValid[i][j] = isValid[i-1][j];
                else
                    isValid[i][j] = false;
            }
        }
        
        return isValid[s1.size()-1][s2.size()-1];
    }
};