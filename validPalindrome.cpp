//
//  ValidPalindrome.cpp
//  
//
//  Created by 廷芳 杜 on 7/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPalindromeHelper( string s )
    {
        int start = 0;
        int end = s.length()-1;
        while( end>=start )
        {
            if( s[start] != s[end] ) return false;
            start++;
            end--;
        }
        return true;
    }
    string process( string &s )
    {
        string str;
        for( int i = 0 ; i< s.length(); i++ )
        {
            if( (s[i]>='0'&&s[i]<='9') || (s[i]>='a'&&s[i]<='z') )
                str  = str+ s[i];
            else if( s[i]>='A'&&s[i]<='Z')
                str  = str + (char)(s[i]+32);
        }
        return str;
    }
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( s.empty() ) return true;
        if( s.length()==1 ) return true;
        string validStr = process( s );
        return isPalindromeHelper( validStr );
    }
};