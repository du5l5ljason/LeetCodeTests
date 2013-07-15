//
//  WordLadderII.cpp
//  
//
//  Created by 廷芳 杜 on 7/15/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    struct pathNode{
        string str;
        pathNode *pre;
        pathNode( string s){
            str = s;
            pre = NULL;
        };
    };
    void findPath( pathNode &node, vector<string> &path )
    {
        while( node!=NULL )
        {
            path.push_back( node.str );
            node = node->pre;
        }
        swap( path.begin(), path.end() );
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<string> > pathPool;
        if( start == end )
        {
            vector<string> vec;
            vec.push_back("");
            pathPool.push_back( vec );
            
            return pathPool;
        }
        
        queue<pathNode> u;
        u.push( pathNode(start) );
        u.push( pathNode("") );
        bool isFound = false;
        while( !u.empty() )
        {
            pathNode v = u.front();
            u.pop();
            if( isFound && v.str=="") return pathPool;
            else
            {
                if( v.str=="" ) //reach to the end of a level
                {
                    if( !u.empty() ) u.push( pathNode("") );
                }
                else
                {
                    if( v.str == end )
                    {
                        vector<string> vec;
                        findPath( v,vec );
                        pathPool.push_back( vec );
                        isFound = true;
                    }
                    else
                    {
                        string temp = v.str;
                        for( int i = 0; i < v.str.length(); i++ )
                        {
                            for( char j = 'a' ; j <= 'z'; j++ )
                            {
                                v.str[i] = j;
                                if( v.str == temp ) continue;
                                else 
                                {
                                    if( dict.find( v.str ) !=dict.end() )
                                    {
                                        pathNode newNode(v);
                                        newNode->pre = &v;
                                        u.push( newNode );
                                    }
                                }
                            }
                            v.str = temp;
                        }
                        dict.erase( v.str );
                    }
                }
                
            }
        }
        
        return pathPool;        
    }
};