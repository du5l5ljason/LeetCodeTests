//
//  PalindromePartition.cpp
//  
//
//  Created by 廷芳 杜 on 4/16/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    vector< vector<string> > output;
    bool isPalindrome( string s )
    {
        if(s.length() == 0 ) return false;
        if(s.length() == 1 ) return true;
        
        int start = 0;
        int end = s.length()-1;
        while( start < end )
        {
            if( s[start] != s[end] )
                return false;
            start++;
            end--;
        }
        
        return true;
    }
    
    void palindromePermutation( string s, int start, vector<string> &vec )
    {
        if( start == s.length() )
        {
            //push the vec into the output vector array.
            //
            output.push_back( vec );
            return;
        }
        for( int i = start ; i < s.length(); i++ )
        {
            if( isPalindrome(s.substr(start,i-start+1) ))
            {
                vec.push_back(s.substr(start,i-start+1));
                palindromePermutation( s, i+1, vec );
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( s.length() == 0 ) return output;
        vector<string> vec;
        output.clear();
        palindromePermutation( s, 0, vec );
        return output;
    }
};


