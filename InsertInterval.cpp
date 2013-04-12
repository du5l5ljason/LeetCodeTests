//
//  InsertInterval.cpp
//  
//
//  Created by 廷芳 杜 on 4/12/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        if( intervals.size() == 0 )
        {
            result.push_back( newInterval );
            return result;
        }    
        
        int len = intervals.size();
        if( newInterval.end < intervals[0].start )
        {
            vector<Interval>::iterator it = intervals.begin();
            intervals.insert(it, newInterval );
            return intervals;
        }
        if ( newInterval.start > intervals[len-1].end )
        {
            intervals.push_back( newInterval );
            return intervals;            
        }
        
        else
        {
            int startId, endId;
            findInterval( intervals, newInterval, startId, endId ); 
            result = mergeIntervals( intervals, newInterval, startId, endId );
            return result;
            
        }
        
        
    }
    
    void findInterval( vector<Interval> &intervals, Interval &newInterval, int &start, int &end ){
        int len = intervals.size();
        
        for( int i = 0 ; i < len; i++ )
        {
            if( intervals[i].start <= newInterval.start && newInterval.start <= intervals[i].end )
            {
                newInterval.start = intervals[i].start;
                start = i;
                break;
            }
            else if(newInterval.start < intervals[i].start)
            {
                if(intervals[0].start > newInterval.start )
                {
                    start = 0;
                    break;
                }
                else
                {
                    start = i;
                    break;
                }   
            }   
            
        }
        
        for( int i = 0 ; i < len; i++ )
        {        
            if( intervals[i].start <= newInterval.end && newInterval.end <= intervals[i].end )
            {
                newInterval.end = intervals[i].end;
                end = i; 
                break;
            }
            else if(newInterval.end < intervals[i].start) 
            {
                end = i;
                break;
            }    
        }
        
        if( intervals[len-1].end < newInterval.end )
            end = len-1;
    }
    
    vector<Interval> mergeIntervals( vector<Interval>intervals, Interval newInterval, int startId, int endId )
    {
        vector<Interval> result;
        int len = intervals.size();
        for( int i = 0 ; i< startId ;i ++ )
            result.push_back( intervals[i] );
        
        result.push_back( newInterval );
        
        if( endId < len-1 )
            for( int i = endId+1; i<len;i++ )
                result.push_back( intervals[i] );
        
        return result;
    }
};