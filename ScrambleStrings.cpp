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
    bool isInterleaveHelper( string s1, int id1, string s2, int id2, string s3, int id3 )
    {
        if( id3 < 0 ) return true;
        if( id1 < 0 && id2 < 0 ) return false;
        if( id1 < 0 )
        {
            if( s3[id3] == s2[id2] )
                return isInterleaveHelper( s1, id1, s2, id2-1, s3, id3-1 );
            else
                return false;
        }
        else if( id2 < 0 )
        {
            if( s3[id3] == s1[id1] )
                return isInterleaveHelper( s1, id1-1, s2, id2, s3, id3-1 );
            else
                return false;            
        }
        else
        {
            if( s3[id3] != s1[id1] && s3[id3] != s2[id2] ) return false;
            if( s3[id3] != s1[id1] )
                return isInterleaveHelper( s1, id1, s2, id2-1, s3, id3-1 );
            if( s3[id3] != s2[id2] )
                return isInterleaveHelper( s1, id1-1, s2, id2, s3, id3-1 );
            
            return isInterleaveHelper( s1, id1-1, s2, id2, s3, id3-1 ) || isInterleaveHelper( s1, id1, s2, id2-1, s3, id3-1 );
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if( s3.size() != s1.size()+s2.size() ) return false;
        int id1 = s1.size()-1;
        int id2 = s2.size()-1;
        int id3 = s3.size()-1;
        
        return isInterleaveHelper( s1, id1, s2, id2, s3, id3 );
    }
};