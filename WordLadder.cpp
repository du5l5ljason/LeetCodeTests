//
//  WordLadder.cpp
//  
//
//  Created by 廷芳 杜 on 7/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( start == end ) return 1;
        if( dict.empty() ) return 0;
        
        int len = 1;
        queue<string> u;
        u.push( start );
        u.push( "" );
        while( !u.empty()  )
        {
            string v = u.front();
            u.pop();
            if( v == "" )   //whole level has been traversaled.
            {
                len = len+1;
                if( !u.empty() ) u.push( "" );
            }
            else
            {
                if( v == end ) return len;
                
                else
                {
                    string temp = v;
                    for( int i = 0; i < v.length(); ++i )
                    {
                        for( int j = 'a' ; j <= 'z'; ++j )
                        {
                            v[i] = j;
                            if( dict.find(v) != dict.end()  ) //find the word
                            {
                                u.push( v );
                                dict.erase( v );
                            }
                        }
                        v = temp;
                    }
                    
                }
            }
        }
        return 0;
    }
};